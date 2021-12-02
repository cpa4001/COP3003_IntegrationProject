/** @file UserStory.cpp
 *   @brief: Implementation file for UserStory class
 *
 *	Implementation of Userstory Class and blueprint for
 *	user stories in file, all method definitions 
 * 
 *	@author Christian Apostoli
 *	@bug No known bugs
 */

#include "UserStory.h"

// LO4: Include a comment in which you compare and contrast the procedural/functional
// approach and the object-oriented approach
/*
    The object-oriented approach utlizes classes to store the data
    and behaviors of a UserStory and objects to implement the functionality of
    the UserStory class. The functional/procedural approach could use structs to
    hold data and multiple functions would need to be made to implement the
    behaviors.
*/

int UserStory::storyID = 0;

/**
    @brief default constructor - intialize empty UserStory
*/
UserStory::UserStory() {
  storyName = "";
  storyBody = "";
  storyPoints = 0;
  status = to_do;

  storyID++;
}

//LO1b
/**
*  @brief default constructor - intialize empty UserStory
*  @param storyName	Name of user story
*  @param storyBody	Description of user story
*  @param storyPoints	integer value of points assigned to story
*
*/
UserStory::UserStory(std::string storyName, std::string storyBody,
                     int storyPoints) {
  this->storyName = storyName;
  this->storyBody = storyBody;
  // Ensure story points are positive
  if (storyPoints < 0) {
    this->storyPoints = 1;
  } else {
    this->storyPoints = storyPoints;
  }
  status = to_do;

  storyID++;
}


/**
*   @brief getter for storyName attribute
*   
*   @return storyName name of the story as a string
*/
std::string UserStory::getStoryName() { return storyName; }

/**
 *   @brief getter for storyBody attribute
 *
 *   @return storyBody the description of the story as a string
 */
std::string UserStory::getStoryBody() { return storyBody; }

/**
 *   @brief getter for storyPoints attribute
 *
 *   @return storyPoints the amount of points the story holds as an int
 */
int UserStory::getStoryPoints() { return storyPoints; }

/**
 *   @brief getter for status attribute
 *
 *   @return status the status of the user story
 */
int UserStory::getStatus() { return status; }


/**
 *   @brief returns the meaning of the status enum
 *
 *   @return the meaning of the status enum value: To Do, Inprogress, or Done
 */
std::string UserStory::getStatusString() {
  switch (status) {
    case 0:
      return "To Do";
    case 1:
      return "In Progress";
    case 2:
      return "Done";
  }
}


/**
 *   @brief setter for storyName attribute
 *
 *   @param value the name of the user story
 */
void UserStory::setStoryName(std::string value) { storyName = value; }

/**
 *   @brief setter for storyBody attribute
 *
 *   @param value the body of the user story
 */
void UserStory::setStoryBody(std::string value) { storyBody = value; }

/**
 *   @brief setter for storyPoints attribute
 *
 *   @param value the body of the user story
 */
void UserStory::setStoryPoints(int value) { storyPoints = value; }

/**
 *   @brief sets the user story status to done
 */
void UserStory::completeUserStory() { status = done; }