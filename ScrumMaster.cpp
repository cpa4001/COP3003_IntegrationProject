#include "ScrumMaster.h"
ScrumMaster::ScrumMaster(std::string collaboratorName)
    : Collaborator(collaboratorName, "Scrum Master") {}

/**
 *
 */
void ScrumMaster::assignStory(int storyID) {
  storiesWorkingOn.push_back(storyID);
  developers.push_back(Collaborator::collaboratorID);
}