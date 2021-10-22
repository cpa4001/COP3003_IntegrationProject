/*
	Name: Iteration.cpp
	Author: Christian Apostoli
	Purpose: Main implementation file for Iteration class
*/

#include "Iteration.h"

Iteration::Iteration(std::string iterationName,
	std::string iterationType,
	int iterationLength)  
{
	this->iterationName = iterationName;
	this->iterationLength = iterationLength;
	this->iterationType = iterationType;
	estimatedVelocity = 0;
	productBacklog = {};
}

std::string Iteration::getIterationName() { return iterationName;  }
int Iteration::getIterationLength() { return iterationLength; }
std::string Iteration::getIterationType() { return iterationType; }
int Iteration::getEstimatedVelocity() { return estimatedVelocity; }

void Iteration::setIterationName(std::string value) { iterationName = value; }
void Iteration::setIterationType(std::string value) { iterationType = value; }
void Iteration::setIterationLength(int value) { iterationLength = value; }
void Iteration::setEstimatedVelocity(int value) { estimatedVelocity = value; }

void Iteration::addUserStory(UserStory& userstory) {
	productBacklog.push_back(userstory);
}

void Iteration::printStories() {
	for (int index = 0; index < productBacklog.size(); index++) {
		std::cout << productBacklog[index].getStoryName() << std::endl;
	}
}

Sprint::Sprint(std::string sprintName, int iterationLengthInDays) : Iteration(sprintName, "Sprint", iterationLengthInDays) {

}

Release::Release(std::string releaseName, int iterationLengthInDays) :
	Iteration(releaseName, "Release", iterationLengthInDays) {

}