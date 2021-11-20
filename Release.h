/*
        Name: Release.h
        Author: Christian Apostoli
        Purpose: Declaration file for Release class
                         inherits from Iteration class
*/

#pragma once
#include "Iteration.h"
class Release : public Iteration {
 private:
 public:
  Release(std::string releaseName, int iterationLengthInDays);
};
