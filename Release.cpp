/*
        Name: Release.cpp
        Author: Christian Apostoli
        Purpose: implementation file for Release class
                 inherits from Iteration class

*/

#include "Release.h"
// LO2

/*
 * Constructor for Sprint - Calls Iteration constructor
 * Parameters:
 * sprintName				Name of sprint
 * iterationLengthInDays		lenght of the iteration in days
 */
Release::Release(std::string releaseName, int iterationLengthInDays)
    : Iteration(releaseName, "Release", iterationLengthInDays) {}