/*
 * WorkoutController.cpp
 *
 *  Created on: Aug 2, 2013
 *      Author: brianmarco
 */

#include <unistd.h>

#include <QDebug>

#include "WorkoutController.hpp"

using namespace gymme;

WorkoutController::WorkoutController() {
	m_currentWorkout = NULL;
	m_currentExercise = NULL;
	m_currentExerciseSet = NULL;

	m_currentActivity = NILL;
	m_prevActivity = NILL;

	m_exerciseCount = 1;
	m_exerciseSetCount = 0;

	m_timer = new QTimer(this);
	m_elapsedTimer = QElapsedTimer();

	m_time = QTime(0, 0);
	m_totalTime = QTime(0,0);
	m_bufferTime = QTime(0,0);

	m_timeBetweenSets = 30;
	m_timeBetweenExercises = 60;

	bool connectResult;
	Q_UNUSED(connectResult);
	connectResult = QObject::connect(m_timer, SIGNAL(timeout()), this,
			SLOT(timerIntervalPassed()));
	Q_ASSERT(connectResult);
}

WorkoutController::~WorkoutController() {
	delete m_timer;
	delete m_currentWorkout;
	delete m_currentExercise;
	delete m_currentExerciseSet;
}

int WorkoutController::exerciseCount() {
	return m_exerciseCount;
}

int WorkoutController::exerciseSetCount() {
	return m_exerciseSetCount;
}

QString WorkoutController::currentTimeAsQString() {
	return m_time.toString("mm:ss.zzz");
}

QString WorkoutController::totalTimeAsQString() {
	return m_totalTime.toString("hh:mm:ss");
}

QString WorkoutController::bufferTimeAsQString() {
	return m_bufferTime.toString("s");
}

QString WorkoutController::currentActivity() {
	QString activityStr;

	switch(m_currentActivity) {
	case WORKING:
		activityStr = "Working";
		break;
	case RESTING:
		activityStr = "Resting";
		break;
	case PAUSED:
		activityStr = "Paused";
		break;
	case WASTING:
		activityStr = "Wasting";
		break;
	default:
		activityStr = "";
	}

	return activityStr;
}

bool WorkoutController::isActive() {
	return m_currentActivity == WORKING;
}

bool WorkoutController::isWastingTime() {
	return m_currentActivity == WASTING;
}

void WorkoutController::start() {
	if (m_timer->isActive()) {
		return;
	}

	if (m_currentWorkout == NULL) {
		m_currentWorkout = new Workout();
	}

	if (m_currentExercise == NULL) {
		m_currentExercise = new Exercise();
		m_currentExercise->setExerciseNum(m_exerciseCount);
		m_currentWorkout->addExercise(m_currentExercise);
	}

	m_currentExerciseSet = new ExerciseSet();
	m_currentExercise->addExerciseSet(m_currentExerciseSet);

	m_time = QTime(0, 0);
	m_elapsedTimer.start();
	m_timer->start(TIMER_INTERVAL);

	m_exerciseSetCount++;
	m_currentExerciseSet->setExerciseSetNum(m_exerciseSetCount);

	emit exerciseSetCountChanged();

	m_currentActivity = WORKING;
	emit activityChanged();
}

void WorkoutController::togglePause() {
	if (m_currentActivity != PAUSED) {
    	m_timer->stop();

    	m_prevActivity = m_currentActivity;
    	m_currentActivity = PAUSED;
	}
	else {
    	m_timer->start(TIMER_INTERVAL);

    	m_currentActivity = m_prevActivity;
    	m_prevActivity = NILL;
	}

	emit activityChanged();
}

void WorkoutController::stop() {
	m_timer->stop();
	m_currentExerciseSet->setWorkingTime(m_elapsedTimer.elapsed());
	debugExerciseSet(m_currentExerciseSet);
}

void WorkoutController::buffer() {
	m_bufferTime = QTime(0,0);

	for (int i=0; i < 5; i++) {
		delay(1000);
		m_bufferTime = m_bufferTime.addSecs(1);
		emit bufferTimeChanged();
	}
}

void WorkoutController::startRest() {
	if (m_timer->isActive()) {
		return;
	}

	m_currentActivity = RESTING;
	m_time = QTime(0, 0, m_timeBetweenSets);
	m_elapsedTimer.start();
	m_timer->start(TIMER_INTERVAL);

	emit activityChanged();
}

void WorkoutController::stopRest() {
	m_timer->stop();

	if (m_currentExerciseSet == NULL) {
		return;
	}

	m_currentExerciseSet->setRestingTime(m_elapsedTimer.elapsed());
	debugExerciseSet(m_currentExerciseSet);
}

void WorkoutController::nextExercise() {
	int timeStillInRest = m_timeBetweenSets + m_time.secsTo(QTime(0,0));

	m_exerciseCount++;
	m_exerciseSetCount = 0;

	m_time = QTime(0, 0);
	m_time = m_time.addSecs(m_timeBetweenExercises - timeStillInRest);

	Exercise* newExercise = new Exercise();
	newExercise->setExerciseNum(m_exerciseCount);

	m_currentWorkout->addExercise(newExercise);
	m_currentExercise = newExercise;
	m_currentExerciseSet = NULL;

	emit exerciseCountChanged();
	emit exerciseSetCountChanged();
	emit timeChanged();
}

void WorkoutController::timerIntervalPassed() {
	if (m_currentActivity == WORKING || m_currentActivity == WASTING) {
    	m_time = m_time.addMSecs(TIMER_INTERVAL);

    	// Effectively beep every three seconds
    	if (m_currentActivity == WASTING && ((m_time.second() * 1000 + m_time.msec()) % 3000 == 0)) {
    		emit nowWastingTime();
    	}
	}
	else if (m_currentActivity == RESTING) {
		m_time = m_time.addMSecs(-1 * TIMER_INTERVAL);
	}

	emit timeChanged();

	m_totalTime = m_totalTime.addMSecs(TIMER_INTERVAL);
	emit totalTimeChanged();

	if (m_currentActivity != WASTING && m_time <= QTime(0,0)) {
		m_currentActivity = WASTING;
    	emit activityChanged();
    	emit nowWastingTime();
	}
}

void WorkoutController::debugExerciseSet(ExerciseSet* exerciseSet) {
	QString debugMsg = "gymme::";

	QString workoutStr = m_currentWorkout->dateTime().toString();
	QString exerciseStr = QString::number(m_currentExercise->exerciseNum());

	debugMsg.append(workoutStr);
	debugMsg.append(",");
	debugMsg.append(exerciseStr);
	debugMsg.append(",");
	debugMsg.append(QString::number(exerciseSet->exerciseSetNum()));
	debugMsg.append(",");
	debugMsg.append(QString::number(exerciseSet->workingTime()));
	debugMsg.append(",");
	debugMsg.append(QString::number(exerciseSet->restingTime()));
	debugMsg.append(",");
	debugMsg.append(QString::number(exerciseSet->wastingTime()));

	qDebug() << debugMsg;
}
