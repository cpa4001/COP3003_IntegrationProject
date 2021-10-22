/*
	Name: UserStory.h
	Author: Christian Apostoli
	Purpose: Declaration file for UserStory class
*/

#pragma once
#include <string>
class UserStory
{
private:
	std::string storyName;
	std::string storyBody;
	int storyPoints;
	//Id used to track stories 
	int storyID;
	bool isFinished;

public:
	//constructors
	UserStory();
	UserStory(std::string storyName, std::string storyBody, int storyPoints);
	//UserStory(UserStory& userstory);

	//accessors
	//getters
	std::string getStoryName(); 
	std::string getStoryBody(); 
	int getStoryPoints();

	//setters
	void setStoryName(std::string value);
	void setStoryBody(std::string value);
	void setStoryPoints(int value);

	void completeUserStory();
	
};

