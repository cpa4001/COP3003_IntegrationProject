/*
        Name: Developer.h
        Author: Christian Apostoli
        Purpose: Declaration file for Developer class
                 inherits from Collaborator class
*/

#pragma once
#include "Collaborator.h"

// Developer inherits from Collaborator with public visibility
class Developer : public Collaborator {
 public:
  Developer(std::string name);

  void assignStory(int storyID);
};
