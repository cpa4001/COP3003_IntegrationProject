/*
        Name: UserStory.cpp
        Author: Christian Apostoli
        Purpose: Main implementation file for UserStory class
*/

#include "UserStory.h"

int UserStory::storyID = 0;

/**
        default constructor - intialize empty UserStory
*/
UserStory::UserStory() {
  storyName = "";
  storyBody = "";
  storyPoints = 0;
  status = TO_DO;

  storyID++;
}

/**
        default constructor - intialize empty UserStory
        Parameters:
        storyName	Name of user story
        storyBody	Description of user story
        storyPoints	integer value of points assigned to story

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
  status = TO_DO;

  storyID++;
}

/*
UserStory::UserStory(UserStory& userstory) {
        this->storyName = userstory.storyName;
        this->storyBody = userstory.storyBody;
        this->storyPoints = userstory.storyPoints;

        storyID++;
}
*/

std::string UserStory::getStoryName() { return storyName; }
std::string UserStory::getStoryBody() { return storyBody; }
int UserStory::getStoryPoints() { return storyPoints; }

/*
    Returns the Status meaning as string
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

int UserStory::getStatus() { return status; }

void UserStory::setStoryName(std::string value) { storyName = value; }
void UserStory::setStoryBody(std::string value) { storyBody = value; }
void UserStory::setStoryPoints(int value) { storyPoints = value; }

/**
 * sets the Userstory to complete
 */
void UserStory::completeUserStory() { status = DONE; }