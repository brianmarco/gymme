/*
 * ExerciseSet.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: brianmarco
 */

#include "ExerciseSet.hpp"

namespace brianmarco {
namespace gymme {

ExerciseSet::ExerciseSet()
:mWorkingTime(QTime(0, 0)),
 mRestingTime(QTime(0, 0)),
 mWastingTime(QTime(0, 0))
{

}

ExerciseSet::~ExerciseSet() {
}

} /* namespace gymme */
} /* namespace brianmarco */
