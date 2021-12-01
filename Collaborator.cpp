/** @file Collaborator.cpp
 *  @brief Implementation file for Collaborator class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */


#include "Collaborator.h"

int Collaborator::collaboratorID = 0;
/**
        default constructor - intialize empty Collaborator
*/
Collaborator::Collaborator() {
  collaboratorName = "";

  collaboratorID++;
}

/**
 * Constructor for Collaborator
 * Parameters:
 * collaboratorName	name of the collaborator
 * role				role of collaborator within the project
 */
Collaborator::Collaborator(std::string collaboratorName, std::string role) {
  this->collaboratorName = collaboratorName;
  this->role = role;

  collaboratorID++;
}

std::string Collaborator::getcollaboratorName() { return collaboratorName; }