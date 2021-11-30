/*
        Name: Sprint.h
        Author: Christian Apostoli
        Purpose: Declaration file for Sprint class
                         inherits from Iteration class
*/

#pragma once
#include "Iteration.h"
// LO2
// Sprint inherits from Iteration with public visibility
class Sprint : public Iteration {
 private:
 public:
  Sprint(std::string sprintName, int iterationLengthInDays);
};
