/*
 * ExerciseSet.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: brianmarco
 */

#include "ExerciseSet.hpp"

using namespace gymme;

ExerciseSet::ExerciseSet()
:mWorkingTime(QTime(0, 0)),
 mRestingTime(QTime(0, 0)),
 mWastingTime(QTime(0, 0))
{

}

ExerciseSet::~ExerciseSet() {
}
