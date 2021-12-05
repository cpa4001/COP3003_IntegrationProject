/** @file Release.cpp
 *  @brief implementation file for Release class
 *         inherits from Iteration class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#include "Release.h"
// LO2

/** @brief Constructor for Sprint - Calls Iteration constructor
 *
 * @param releaseName		Name of realease
 * @param iterationLengthInDays	lenght of the iteration in days
 */
Release::Release(std::string releaseName, int iterationLengthInDays)
    : Iteration(releaseName, "Release", iterationLengthInDays) {}