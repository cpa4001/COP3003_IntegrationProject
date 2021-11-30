/*
        Name: Iteration.cpp
        Author: Christian Apostoli
        Purpose: Main implementation file for Iteration class
*/

#include "Iteration.h"

/**
 * Constructor for Iteration
 * Parameters:
 * iterationName		Name of the iteration
 * iterationType		Type of iteration: sprint, release, iteration,
 * etc. iterationLength	Lenght of iteration in days
 */
Iteration::Iteration(std::string iterationName, std::string iterationType,
                     int iterationLength) {
  this->iterationName = iterationName;
  this->iterationLength = iterationLength;
  this->iterationType = iterationType;
  estimatedVelocity = 0;
  productBacklog = {};
}

std::string Iteration::getIterationName() { return iterationName; }
int Iteration::getIterationLength() { return iterationLength; }
std::string Iteration::getIterationType() { return iterationType; }
int Iteration::getEstimatedVelocity() { return estimatedVelocity; }

void Iteration::setIterationName(std::string value) { iterationName = value; }
void Iteration::setIterationType(std::string value) { iterationType = value; }
void Iteration::setIterationLength(int value) { iterationLength = value; }
void Iteration::setEstimatedVelocity(int value) { estimatedVelocity = value; }

/**
 * adds UserStory to the backlog(list of userstories)
 * Parameters:
 * userstory		userstory object
 */
void Iteration::addUserStory(UserStory& userstory) {
  productBacklog.push_back(userstory);
}

/**
 * prints names of user stories in the iteration's backolog to console
 */
void Iteration::printStories() {
  for (size_t index = 0; index < productBacklog.size(); index++) {
    std::cout << productBacklog[index].getStoryName() << std::endl;
  }
}
