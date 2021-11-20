/*
        Name: ScrumMaster.cpp
        Author: Christian Apostoli
        Purpose: implementation file for ScrumMaster class
                 inherits from Collaborator class

*/

#include "ScrumMaster.h"

/*
    Constructor for ScrumMaster - calls Collaborator Constructor
*/
ScrumMaster::ScrumMaster(std::string collaboratorName)
    : Collaborator(collaboratorName, "Scrum Master") {}

/**
 *  Adds story to the ScrumMaster's working stories
 *  Param:
 *  storyID     integer ID of the UserStory
 */
void ScrumMaster::assignStory(int storyID) {
  storiesWorkingOn.push_back(storyID);
  developers.push_back(Collaborator::collaboratorID);
}