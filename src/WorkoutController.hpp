/*
 * WorkoutController.hpp
 *
 *  Created on: Aug 2, 2013
 *      Author: brianmarco
 */

#ifndef WORKOUTCONTROLLER_HPP_
#define WORKOUTCONTROLLER_HPP_

#include <QObject>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>

#include "SoundManager.hpp"
#include "Workout.hpp"

namespace gymme {

const int TIMER_INTERVAL = 2;

class WorkoutController : public QObject {
	Q_OBJECT
	Q_PROPERTY(int exerciseCount READ exerciseCount NOTIFY exerciseCountChanged)
	Q_PROPERTY(int exerciseSetCount READ exerciseSetCount NOTIFY exerciseSetCountChanged)
	Q_PROPERTY(QString currentTime READ currentTimeAsQString NOTIFY timeChanged)
	Q_PROPERTY(QString totalTime READ totalTimeAsQString NOTIFY totalTimeChanged)
	Q_PROPERTY(QString bufferTime READ bufferTimeAsQString NOTIFY bufferTimeChanged)
	Q_PROPERTY(QString currentActivity READ currentActivity NOTIFY activityChanged)
	Q_PROPERTY(bool isWastingTime READ isWastingTime NOTIFY nowWastingTime)

public:
	WorkoutController();
	virtual ~WorkoutController();

	int exerciseCount();
	int exerciseSetCount();
	QString currentTimeAsQString();
	QString totalTimeAsQString();
	QString bufferTimeAsQString();
	QString currentActivity();
	bool isWastingTime();

	Q_INVOKABLE bool isActive();
	Q_INVOKABLE void start();
	Q_INVOKABLE void togglePause();
	Q_INVOKABLE void buffer();
	Q_INVOKABLE void stop();
	Q_INVOKABLE void startRest();
	Q_INVOKABLE void stopRest();
	Q_INVOKABLE void nextExercise();

private slots:
	void timerIntervalPassed();

signals:
	void exerciseCountChanged();
	void exerciseSetCountChanged();
	void timeChanged();
	void totalTimeChanged();
	void bufferTimeChanged();
	void activityChanged();
	void nowWastingTime();

private:
	enum Activity {
		NILL,
		RESTING,
		PAUSED,
		WORKING,
		WASTING
	};

	Activity m_currentActivity;
	Activity m_prevActivity;

	int m_exerciseCount;
	int m_exerciseSetCount;

	QTimer* m_timer;
	QElapsedTimer m_elapsedTimer;

	QTime m_time;
	QTime m_totalTime;
	QTime m_bufferTime;

	int m_timeBetweenSets;
	int m_timeBetweenExercises;

	Workout* m_currentWorkout;
	Exercise* m_currentExercise;
	ExerciseSet* m_currentExerciseSet;

	void debugExerciseSet(ExerciseSet* exerciseSet);
};
}

#endif /* WORKOUTCONTROLLER_HPP_ */
