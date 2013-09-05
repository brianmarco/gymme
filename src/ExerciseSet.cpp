/*
 * ExerciseSet.cpp
 *
 *  Created on: Aug 16, 2013
 *      Author: brianmarco
 */

#include "ExerciseSet.hpp"

using namespace gymme;

ExerciseSet::ExerciseSet()
    :m_exerciseSetNum(0),
     m_workingTime(0),
     m_restingTime(0),
     m_wastingTime(0)
{

}

ExerciseSet::~ExerciseSet() {
}

int ExerciseSet::exerciseSetNum() {
	return m_exerciseSetNum;
}

void ExerciseSet::setExerciseSetNum(int exerciseSetNum) {
	m_exerciseSetNum = exerciseSetNum;
}

int ExerciseSet::workingTime() {
	return m_workingTime;
}

void ExerciseSet::setWorkingTime(int workingTime) {
	m_workingTime = workingTime;
}

int ExerciseSet::restingTime() {
	return m_restingTime;
}

void ExerciseSet::setRestingTime(int restingTime) {
	m_restingTime = restingTime;
}

int ExerciseSet::wastingTime() {
	return m_wastingTime;
}

void ExerciseSet::setWastingTime(int wastingTime) {
	m_wastingTime = wastingTime;
}
