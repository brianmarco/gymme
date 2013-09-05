#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>

#include "WorkoutController.hpp"
#include "SoundManager.hpp"

namespace bb
{
    namespace cascades
    {
        class Application;
        class LocaleHandler;
    }
}

class QTranslator;

class ApplicationUI : public QObject
{
    Q_OBJECT

public:
    ApplicationUI(bb::cascades::Application *app);
    ~ApplicationUI();

    /**
     * Play a sound using the internal SoundManager.
     */
    Q_INVOKABLE void playSound(const QString &sound);

    /**
     * Convenience method for QML code to determine if the Dark theme is used.
     */
    Q_INVOKABLE bool isUsingDarkTheme();

private slots:
    void onSystemLanguageChanged();

private:
    QTranslator* m_pTranslator;
    bb::cascades::LocaleHandler* m_pLocaleHandler;
    gymme::WorkoutController* m_workoutController;
    gymme::SoundManager* m_soundManager;
};

#endif /* ApplicationUI_HPP_ */
