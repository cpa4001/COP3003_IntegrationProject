/** @file ScrumMaster.cpp
 *  @brief Implementation file for ScrumMaster class
 *         inherits from Collaborator class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

// LO1a
// LO2
#include "ScrumMaster.h"

/**
 * LO1c
 * @brief Constructor for ScrumMaster - calls Collaborator Constructor
 *
 * @param collaboratorName name of the ScrumMaster
 */
ScrumMaster::ScrumMaster(std::string collaboratorName)
    : Collaborator(collaboratorName, "Scrum Master") {}

/** LO5
 *  @brief Adds story to the ScrumMaster's list of stories working on
 *
 *  @param storyID     integer ID of the UserStory
 */
void ScrumMaster::assignStory(int storyID) {
  storiesWorkingOn.push_back(storyID);
  developers.push_back(Collaborator::collaboratorID);
}