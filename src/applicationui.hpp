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

/*!
 * @brief Application object
 *
 *
 */

class ApplicationUI : public QObject
{
    Q_OBJECT

public:
    ApplicationUI(bb::cascades::Application *app);
    ~ApplicationUI();

    Q_INVOKABLE void playSound(const QString &sound);

private slots:
    void onSystemLanguageChanged();

private:
    QTranslator* m_pTranslator;
    bb::cascades::LocaleHandler* m_pLocaleHandler;

    gymme::WorkoutController* m_workoutController;

    SoundManager* m_soundManager;
};

#endif /* ApplicationUI_HPP_ */
