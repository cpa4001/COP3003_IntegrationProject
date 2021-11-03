/*
	Name: Iteration.h
	Author: Christian Apostoli
	Purpose: Declaration file for Iteration class
*/

#ifndef ITERATION_H
#define ITERATION_H
#include <string>
#include <vector>
#include "Backlog.h"
#include "Collaborator.h"
#include "UserStory.h"
class Iteration
{
private:
	Backlog backlog;
	std::string iterationName;

	//we could have type and length left blank
	//and subclasses itnitalize
	std::string iterationType;
	int iterationLength;


	int storyPointsComplete;
	int storyPointsLeftToComplete;
	int estimatedVelocity;

	std::vector<UserStory> productBacklog;
	std::vector<Collaborator> collaborators;

public:
	//Constructors
	Iteration(std::string iterationName,
	std::string iterationType,
	int iterationLength);

	//getters
	std::string getIterationName();
	std::string getIterationType();
	int getIterationLength();
	int getEstimatedVelocity();

	//setters
	void setIterationName(std::string value);
	void setIterationType(std::string value);
	void setIterationLength(int value);
	void setEstimatedVelocity(int value);

	void addUserStory(UserStory& userstory);
	void printStories();
};
#endif