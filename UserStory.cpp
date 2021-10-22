/*
	Name: UserStory.cpp
	Author: Christian Apostoli
	Purpose: Main implementation file for UserStory class
*/

#include "UserStory.h"

UserStory::UserStory() {
	storyName = "";
	storyBody = "";
	storyPoints = 0;
	isFinished = false;

	storyID++;
}

UserStory::UserStory(std::string storyName, std::string storyBody, int storyPoints) {
	this->storyName = storyName;
	this->storyBody = storyBody;
	//Ensure story points are positive 
	if (storyPoints < 0) {
		this->storyPoints = 1;
	}
	else {
		this->storyPoints = storyPoints;
	}
	isFinished = false;

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


void UserStory::setStoryName(std::string value) { storyName = value; }
void UserStory::setStoryBody(std::string value) { storyBody = value; }
void UserStory::setStoryPoints(int value) { storyPoints = value; }

void UserStory::completeUserStory() { isFinished = true; }