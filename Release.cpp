/** @file Release.cpp
 *  @brief implementation file for Release class
           inherits from Iteration class
 *  @author Christian Apostoli
 *  @bug No known bugs.
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