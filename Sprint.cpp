/** @file Sprint.cpp
 *  @brief Implementation file for Sprint class
           inherits from Iteration class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#include "Sprint.h"
// LO2

/**
 * Constructor for Sprint - Calls Iteration constructor
 * Parameters:
 * sprintName				Name of sprint
 * iterationLengthInDays	lenght of the iteration in days
 */
Sprint::Sprint(std::string sprintName, int iterationLengthInDays)
    : Iteration(sprintName, "Sprint", iterationLengthInDays) {}