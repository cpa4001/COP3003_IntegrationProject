/** @file Developer.cpp
 *  @brief Implementation file for Developer class inherits from                 Collaborator  class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#include "Developer.h"
// LO2

/*
    Constructor for Developer - calls Collaborator Constructor
    Param:
    name    name of the Developer
*/
Developer::Developer(std::string name) : Collaborator(name, "Developer") {}

/*
    Assigns story to the vector of Stories that devloper is working on it
    overrides Collaborator::assignStory
    Param:
    storyID the integer ID of the UserStory
*/
void Developer::assignStory(int storyID) {
  storiesWorkingOn.push_back(storyID);
}
