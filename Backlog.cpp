/*
	Name: Backlog.cpp
	Author: Christian Apostoli
	Purpose: Main implementation file for Backlog class
*/

#include "Backlog.h"

/**
	default constructor - intialize empty Backlog
*/
Backlog::Backlog() {
	productBacklog = {};
}

/*
Backlog::~Backlog() {
	delete[] productBacklog;
}
*/


/**
* adds UserStory to the backlog(list of userstories)
* Parameters:
* userstory		userstory object
*/
void Backlog::addUserStory(UserStory& userstory) {
productBacklog.push_back(userstory);
}


/**
* prints names of user stories in the iteration's backolog to console
*/
void Backlog::printStories() {
	for (int index = 0; index < productBacklog.size(); index++) {
		std::cout << productBacklog[index].getStoryName() << std::endl;
	}
}