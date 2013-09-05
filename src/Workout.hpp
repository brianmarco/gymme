/*
 * Workout.hpp
 *
 *  Created on: Aug 16, 2013
 *      Author: brianmarco
 */

#ifndef WORKOUT_HPP_
#define WORKOUT_HPP_

#include <QDateTime>
#include <QList>
#include <QVariant>

#include "Exercise.hpp"

namespace gymme {

class Workout {
public:
	Workout();
	virtual ~Workout();

	QList<Exercise*> exercises();
	QDateTime dateTime();

	void addExercise(Exercise* exercise);

	QVariant workoutData();
private:
	QDateTime m_dateTime;
	QList<Exercise*> m_exercises;
};

} /* namespace gymme */
#endif /* WORKOUT_HPP_ */
