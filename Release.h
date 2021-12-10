/** @file Release.h
 *  @brief Declaration file for Release class
           inherits from Iteration class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#ifndef RELEASE_H
#define RELEASE_H

#include "Iteration.h"
// LO2
// LO2a

/**
 * @brief Release inherits from Iteration with public visibility
 */
class Release : public Iteration {
 private:
 public:
  Release(std::string releaseName, int iterationLengthInDays);
};
#endif