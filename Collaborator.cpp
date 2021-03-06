/** @file Collaborator.cpp
 *  @brief Implementation file for Collaborator class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#include "Collaborator.h"

// intialize collaboratorID where the first one created will be 1
int Collaborator::collaboratorID = 0;

/** @brief default Collaborator constructor given no parameters
 */
Collaborator::Collaborator() {
  collaboratorName = "";

  // Increment every time collaborator is created to have unique id
  collaboratorID++;
}

/**
 * @brief Constructor for Collaborator given parameters
 *
 * @param collaboratorName	name of the collaborator
 * @param role				role of collaborator within the project
 */
Collaborator::Collaborator(std::string collaboratorName, std::string role) {
  this->collaboratorName = collaboratorName;
  this->role = role;

  // Increment every time collaborator is created to have unique id
  collaboratorID++;
}

/**
 *  @brief getter for collaboratorName
 *
 *  @return	collaboratorName the name of the collaborator
 */
auto Collaborator::getcollaboratorName() -> std::string {
  return collaboratorName;
}

/**
 * @brief assigns a user story to a collaborator
 *
 * @param storyID the id of the story the collaborator is working on
 */
void Collaborator::assignStory(int storyID) {}
