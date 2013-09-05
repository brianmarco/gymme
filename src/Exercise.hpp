/*
 * Exercise.hpp
 *
 *  Created on: Aug 22, 2013
 *      Author: brianmarco
 */

#ifndef EXERCISE_HPP_
#define EXERCISE_HPP_

#include "ExerciseSet.hpp"

namespace gymme {

class Exercise {
public:
	Exercise();
	virtual ~Exercise();

	int exerciseNum();
	void setExerciseNum(int exerciseNum);

	QList<ExerciseSet*> exerciseSets();
	void addExerciseSet(ExerciseSet* exerciseSet);
private:
	int m_exerciseNum;
	QList<ExerciseSet*> m_exerciseSets;
};

} /* namespace gymme */
#endif /* EXERCISE_HPP_ */
