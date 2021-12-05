/** @file Developer.cpp
 *  @brief Implementation file for Developer class inherits from Collaborator
 *         class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#include "Developer.h"
// LO2

/**
 *  @brief constructor for Developer
 *
 *  calls Collaborator constructor
 *
 *  @param name  name of the Developer
 */
Developer::Developer(std::string name) : Collaborator(name, "Developer") {}

/** LO5
 *  @brief Appends storyid to the storiesWorkingOn atribute in Collaborator
 *
 *  @param storyID the integer ID of the UserStory
 */
void Developer::assignStory(int storyID) {
  storiesWorkingOn.push_back(storyID);
}
