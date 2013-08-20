/*
 * ExerciseSet.hpp
 *
 *  Created on: Aug 16, 2013
 *      Author: brianmarco
 */

#ifndef EXERCISESET_HPP_
#define EXERCISESET_HPP_

#include <QTime>

namespace brianmarco {
namespace gymme {

class ExerciseSet {
public:
	ExerciseSet();
	virtual ~ExerciseSet();

	QTime workingTime();
	QTime restingTime();
	QTime wastingTime();

	void setWorkingTime(QTime workingTime);
	void setRestingTime(QTime restingTime);
	void setWastingTime(QTime wastingTime);
private:
	QTime mWorkingTime;
	QTime mRestingTime;
	QTime mWastingTime;
};

} /* namespace gymme */
} /* namespace brianmarco */
#endif /* EXERCISESET_HPP_ */
