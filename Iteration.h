/** @file Iteration.h
 *  @brief Declaration file for Iteration class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#ifndef ITERATION_H
#define ITERATION_H
#include <string>
#include <vector>

#include "Backlog.h"
#include "Collaborator.h"
#include "UserStory.h"

/**
 * @brief a period of time in the development process where a team works on a
 *         set amount of user stories
 */
class Iteration {
 private:
  // Backlog backlog;
  std::string iterationName;

  std::string iterationType;
  int iterationLength;

  int storyPointsComplete;
  int storyPointsLeftToComplete;
  int estimatedVelocity;

  /**
   * @brief vector to hold user story objects in the iteration
   */
  std::vector<UserStory> productBacklog;

  /**
   * @brief Collaborators objects that are working on stories in this iteration
   */
  std::vector<Collaborator> collaborators;

 public:
  // Constructors
  Iteration(std::string iterationName, std::string iterationType,
            int iterationLength);

  // getters
  auto getIterationName() const -> std::string;
  auto getIterationType() const -> std::string;
  auto getIterationLength() const noexcept -> int;
  auto getEstimatedVelocity() const noexcept -> int;

  // setters
  void setIterationName(std::string value);
  void setIterationType(std::string value);
  void setIterationLength(int value) noexcept;
  void setEstimatedVelocity(int value) noexcept;

  void addUserStory(const UserStory& userstory);
  void printStories();
};

#endif