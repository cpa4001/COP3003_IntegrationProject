/*
        Name: ScrumMaster.cpp
        Author: Christian Apostoli
        Purpose: implementation file for ScrumMaster class
                 inherits from Collaborator class

*/

// LO2
#include "ScrumMaster.h"

/* LO1c
    Constructor for ScrumMaster - calls Collaborator Constructor
*/
ScrumMaster::ScrumMaster(std::string collaboratorName)
    : Collaborator(collaboratorName, "Scrum Master") {}

/**
 *  Adds story to the ScrumMaster's working stories
 *  overrides Collaborator::assignStory
 *  Param:
 *  storyID     integer ID of the UserStory
 */
void ScrumMaster::assignStory(int storyID) {
  storiesWorkingOn.push_back(storyID);
  developers.push_back(Collaborator::collaboratorID);
}