#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>
#include <bb/cascades/Window>
#include <bb/cascades/Container>
#include <bb/cascades/ColorTheme>
#include <bb/cascades/Theme>
#include <bb/cascades/ThemeSupport>
#include <QDebug>

using namespace bb::cascades;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
        QObject(app)
{
	m_workoutController = new gymme::WorkoutController();

    m_soundManager = new gymme::SoundManager("sounds/");

    // prepare the localization
    m_pTranslator = new QTranslator(this);
    m_pLocaleHandler = new LocaleHandler(this);
    if(!QObject::connect(m_pLocaleHandler, SIGNAL(systemLanguageChanged()), this, SLOT(onSystemLanguageChanged()))) {
        // This is an abnormal situation! Something went wrong!
        // Add own code to recover here
        qWarning() << "Recovering from a failed connect()";
    }
    // initial load
    onSystemLanguageChanged();

    app->mainWindow()->setScreenIdleMode(ScreenIdleMode::KeepAwake);

    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    qml->setContextProperty("workoutController", m_workoutController);
    qml->setContextProperty("app", this);

    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();

    // Disable the dummy containers (used for quick preview in QML editor
    Container *dummyHeaderContainer = root->findChild<Container*>("dummyHeaderContainer");
    Container *dummyTimeContainer = root->findChild<Container*>("dummyTimerContainer");
    Container *headerContainer = root->findChild<Container*>("headerContainer");
    Container *timeContainer = root->findChild<Container*>("timerContainer");

    dummyHeaderContainer->setVisible(false);
    dummyTimeContainer->setVisible(false);
    headerContainer->setVisible(true);
    timeContainer->setVisible(true);

    // Set created root object as the application scene
    app->setScene(root);
}

ApplicationUI::~ApplicationUI() {
	delete m_soundManager;
}

void ApplicationUI::playSound(const QString &sound) {
	m_soundManager->play(sound);
}

bool ApplicationUI::isUsingDarkTheme() {
	ThemeSupport *themeSupport = Application::instance()->themeSupport();
	Theme *theme = themeSupport->theme();
	ColorTheme *colorTheme = theme->colorTheme();

	return colorTheme->style() == VisualStyle::Dark;
}

void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(m_pTranslator);
    // Initiate, load and install the application translation files.
    QString locale_string = QLocale().name();
    QString file_name = QString("gymme_%1").arg(locale_string);
    if (m_pTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(m_pTranslator);
    }
}
