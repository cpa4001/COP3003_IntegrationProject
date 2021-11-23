/*
        Name: ScrumMaster.h
        Author: Christian Apostoli
        Purpose: Declaration file for ScrumMaster class
                 inherits from Collaborator class
*/

#ifndef SCRUMMASTER_H
#define SCRUMMASTER_H
#include "Collaborator.h"

// Scrum Master inherits from Collaborator with public visibility
class ScrumMaster : public Collaborator {
 public:
  ScrumMaster(std::string collaboratorName);

  void assignStory(int storyID);
};
#endif