/** @file Sprint.h
 *  @brief Declaration file for Sprint class
           inherits from Iteration class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#pragma once
#include "Iteration.h"
// LO2
// LO2a
// Sprint inherits from Iteration with public visibility
class Sprint : public Iteration {
 private:
 public:
  Sprint(std::string sprintName, int iterationLengthInDays);
};
