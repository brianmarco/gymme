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

#include "ExerciseSet.hpp"

namespace gymme {

class Workout {
public:
	Workout();
	virtual ~Workout();

	const QList<ExerciseSet>* exerciseSets();
	const QDateTime* dateTime();

	void addExerciseSet(const ExerciseSet* exerciseSet);
private:
	QDateTime mDateTime;
	QList<ExerciseSet> mExerciseSets;
};

} /* namespace gymme */
#endif /* WORKOUT_HPP_ */
