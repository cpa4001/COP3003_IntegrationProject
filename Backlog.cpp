/*
	Name: Backlog.cpp
	Author: Christian Apostoli
	Purpose: Main implementation file for Backlog class
*/

#include "Backlog.h"

Backlog::Backlog() {
	productBacklog = {};
}

/*
Backlog::~Backlog() {
	delete[] productBacklog;
}
*/

void Backlog::addUserStory(UserStory& userstory) {
productBacklog.push_back(userstory);
}

void Backlog::printStories() {
	for (int index = 0; index < productBacklog.size(); index++) {
		std::cout << productBacklog[index].getStoryName() << std::endl;
	}
}