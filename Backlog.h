/*
        Name: Backlog.h
        Author: Christian Apostoli
        Purpose: Declaration file for Backlog class
*/

#ifndef BACKLOG_H
#define BACKLOG_H
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "UserStory.h"
class Backlog {
 private:
  // vector<UserStory> productBacklog;
  // UserStory* productBacklog = new UserStory[];

  // dynamic collection to hold multiple user stories
  std::vector<UserStory> productBacklog;
  std::vector<std::vector<std::string>> matrix;
  std::vector<std::string> row;

 public:
  Backlog(std::ifstream& readFromUserStories);
  //~Backlog(); needed for an actual dynamic array

  void addUserStory(UserStory& userStory);
  void printStories();
  std::vector<std::vector<std::string>> getMatrix();
  std::vector<UserStory> getProductBacklog();
};
#endif