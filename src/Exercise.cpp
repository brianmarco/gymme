/*
 * Exercise.cpp
 *
 *  Created on: Aug 22, 2013
 *      Author: brianmarco
 */

#include "Exercise.hpp"

using namespace gymme;

Exercise::Exercise()
	:m_exerciseNum(0),
	 m_exerciseSets(QList<ExerciseSet*>())
{
}

Exercise::~Exercise() {
}

int Exercise::exerciseNum() {
	return m_exerciseNum;
}

void Exercise::setExerciseNum(int exerciseNum) {
	m_exerciseNum = exerciseNum;
}

QList<ExerciseSet*> Exercise::exerciseSets() {
	return m_exerciseSets;
}

void Exercise::addExerciseSet(ExerciseSet* excerciseSet) {
	m_exerciseSets << excerciseSet;
}
