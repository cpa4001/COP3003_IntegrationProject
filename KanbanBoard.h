/*
        Name: KanbanBoard.h
        Author: Christian Apostoli
        Purpose: Declaration file for KanbanBoard class
                         inherits from Board Interface
*/

#pragma once
#include <string>
#include <vector>

#include "Board.h"

// KanbanBoard inherits from Board interface with public visibility
class KanbanBoard : public Board {
 private:
  std::vector<std::string> toDoUserStoryNames;
  std::vector<std::string> inProgressUserStoryNames;
  std::vector<std::string> doneUserStoryNames;
  std::map<std::string, int> statusMap;

 public:
  KanbanBoard();
  KanbanBoard(std::vector<std::string> fileRows);
  void printBoard();

  void getDoneUserStory(Backlog& backlog);
  void getInProgressUserStory(Backlog& backlog);
  void getToDoUserStory(Backlog& backlog);
  void addStoryToMap(UserStory& userStory);

  void updateStatus(int storyID, int newStatus);
};
