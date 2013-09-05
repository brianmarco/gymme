/*
 * ExerciseSet.hpp
 *
 *  Created on: Aug 16, 2013
 *      Author: brianmarco
 */

#ifndef EXERCISESET_HPP_
#define EXERCISESET_HPP_

#include <QTime>

namespace gymme {

class ExerciseSet {
public:
	ExerciseSet();
	virtual ~ExerciseSet();

	int exerciseSetNum();

	int workingTime();
	int restingTime();
	int wastingTime();

	void setExerciseSetNum(int exerciseSetNum);

	void setWorkingTime(int workingTime);
	void setRestingTime(int restingTime);
	void setWastingTime(int wastingTime);
private:
	int m_exerciseSetNum;

	int m_workingTime;
	int m_restingTime;
	int m_wastingTime;
};

} /* namespace gymme */
#endif /* EXERCISESET_HPP_ */
