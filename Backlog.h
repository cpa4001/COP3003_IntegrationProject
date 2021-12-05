/** @file Backlog.h
 *  @brief Declaration file for Backlog class
 *
 *	attributes and method prototypes for Backlog class
 *
 *	@author Christian Apostoli
 *	@bug No known bugs
 */

#ifndef BACKLOG_H
#define BACKLOG_H
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "UserStory.h"

// LO1a

/**
 * @brief a list of user stories
 */
class Backlog {
 private:
  // vector<UserStory> productBacklog;
  // UserStory* productBacklog = new UserStory[];

  // dynamic collection to hold multiple user stories
  std::vector<UserStory> productBacklog;
  std::vector<std::vector<std::string>> matrix;
  std::vector<std::string> row;

 public:
  explicit Backlog(std::ifstream& readFromUserStories);
  //~Backlog(); needed if using a dynamic array

  void addUserStory(const UserStory& userStory);
  void addToRow(std::string row);
  void printStories();
  void updateStoryStatus(int storyID, int newStatus);
  void updateStoryWithCollaborator(int storyID, std::string CollaboratorName);

  auto getMatrix() -> std::vector<std::vector<std::string>>;
  auto getProductBacklog() -> std::vector<UserStory>;
  auto getRow() -> std::vector<std::string>;

  friend auto operator-(Backlog& backlog) -> std::string;
};
#endif