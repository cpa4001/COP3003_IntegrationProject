/*
	Name: UserStory.h
	Author: Christian Apostoli
	Purpose: Declaration file for UserStory class
*/

#ifndef USERSTORY_H
#define USERSTORY_H
#include <string>
//friend class Collaborator;
class UserStory
{
private:
	std::string storyName;
	std::string storyBody;
	int storyPoints;
	

	enum Status {
		TO_DO,
		IN_PROGRESS,
		DONE
	};

public:
	//Id used to track stories 
	static int storyID;

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
#endif