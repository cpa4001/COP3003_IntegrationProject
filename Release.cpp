#include "Release.h"

/*
* Constructor for Sprint - Calls Iteration constructor
* Parameters:
* sprintName				Name of sprint
* iterationLengthInDays		lenght of the iteration in days
*/
Release::Release(std::string releaseName, int iterationLengthInDays) :
	Iteration(releaseName, "Release", iterationLengthInDays) {

}