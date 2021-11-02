#pragma once
#include "Iteration.h"
class Release :
    public Iteration
{
private:

public:
    Release(std::string releaseName, int iterationLengthInDays);
};

