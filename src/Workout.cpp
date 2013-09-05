/*
 * Workout.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: brianmarco
 */

#include "Workout.hpp"

using namespace gymme;

Workout::Workout()
	:m_dateTime(QDateTime::currentDateTime()),
	 m_exercises(QList<Exercise*>())
{
}

Workout::~Workout() {
}

QDateTime Workout::dateTime() {
	return m_dateTime;
}

QList<Exercise*> Workout::exercises() {
	return m_exercises;
}

void Workout::addExercise(Exercise* exercise) {
	m_exercises << exercise;
}

QVariant Workout::workoutData() {

	QVariant result;

	return result;
}
