#include "Sprint.h"

/**
* Constructor for Sprint - Calls Iteration constructor
* Parameters:
* sprintName				Name of sprint
* iterationLengthInDays		lenght of the iteration in days
*/
Sprint::Sprint(std::string sprintName, int iterationLengthInDays) : Iteration(sprintName, "Sprint", iterationLengthInDays) {

}