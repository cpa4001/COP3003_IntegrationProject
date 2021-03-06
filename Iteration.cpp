/** @file Iteration.cpp
 *  @brief Implementation file for Iteration class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#include "Iteration.h"

/**
 * @brief Constructor for Iteration
 * @param iterationName		Name of the iteration
 * @param iterationType		Type of iteration: sprint, release, iteration
 * @param iterationLength	Lenght of iteration in days
 */
Iteration::Iteration(std::string iterationName, std::string iterationType,
                     int iterationLength) {
  this->iterationName = iterationName;
  this->iterationLength = iterationLength;
  this->iterationType = iterationType;
  estimatedVelocity = 0;
  productBacklog = {};
  storyPointsComplete = 0;
  storyPointsLeftToComplete = 0;
}

// getters are made const to not modify object

/**
 * @brief getter for iterationName attribute
 *
 * @return iterationName the name of the iteration as a string
 */
auto Iteration::getIterationName() const -> std::string {
  return iterationName;
}

/**
 * @brief getter for iterationLength attribute
 *
 * @return iterationLength the length of the iteration in days as an int
 */
auto Iteration::getIterationLength() const noexcept -> int {
  return iterationLength;
}

/**
 * @brief getter for iterationType attribute
 *
 * @return iterationType the type of iteration as a string
 */
auto Iteration::getIterationType() const -> std::string {
  return iterationType;
}

/**
 * @brief getter for estimatedVelocity attribute
 *
 * @return estimatedVelocity the estimated velocity for an iteration
 * (story points completed / total points for an iteration)
 */
auto Iteration::getEstimatedVelocity() const noexcept -> int {
  return estimatedVelocity;
}

/**
 * @brief setter for iterationName attribute
 *
 * @param value the name of the iteration as a string
 */
void Iteration::setIterationName(std::string value) { iterationName = value; }

/**
 * @brief setter for iterationType attribute
 *
 * @param value the type of the iteration as a string
 */
void Iteration::setIterationType(std::string value) { iterationType = value; }

/**
 * @brief setter for iterationLength attribute
 *
 * @param value the length of the iteration as an int
 */
void Iteration::setIterationLength(int value) noexcept {
  iterationLength = value;
}

/**
 * @brief setter for estimatedVelocity attribute
 *
 * @param value the estimated velocity of the iteration
 */
void Iteration::setEstimatedVelocity(int value) noexcept {
  estimatedVelocity = value;
}

/**
 * @brief adds UserStory to the backlog(list of userstories)
 *
 * @param userstory		userstory object to be added
 */
void Iteration::addUserStory(const UserStory& userstory) {
  productBacklog.push_back(userstory);
}

/**
 * @brief prints the stories that are in the iteration
 *
 * @param prints names of user stories in the iteration's backolog to console
 */
void Iteration::printStories() {
  for (auto& userStory : productBacklog) {
    std::cout << userStory.getStoryName() << std::endl;
  }
}
