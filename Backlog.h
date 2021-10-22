/*
	Name: Backlog.h
	Author: Christian Apostoli
	Purpose: Declaration file for Backlog class
*/

#pragma once
#include <iostream>
#include <vector>
#include "UserStory.h"
class Backlog
{
private:
	//vector<UserStory> productBacklog;
	//UserStory* productBacklog = new UserStory[];

	//dynamic collection to hold multiple user stories
	std::vector<UserStory> productBacklog; 
public:
	Backlog();
	//~Backlog(); needed for an actual dynamic array

	void addUserStory(UserStory &userstory);
	void printStories();
};

