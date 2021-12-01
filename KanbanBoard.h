/** @file KanbanBoard.h
 *  @brief Declaration file for KanbanBoard class
 *
 *	Declaration for KanbanBoard class and blueprint for
 *	kanban board objects in main. Inherits from Board interface
 *
 *	@author Christian Apostoli
 *	@bug No known bugs
 */

#pragma once
#include <string>
#include <vector>

#include "Board.h"

// LO2
// KanbanBoard inherits from Board interface with public visibility
class KanbanBoard : public Board {
 private:
  std::vector<std::string> toDoUserStoryNames;
  std::vector<std::string> inProgressUserStoryNames;
  std::vector<std::string> doneUserStoryNames;
  std::map<std::string, int> statusMap;
  std::map<std::string, int>::iterator map_iterator;

 public:
  KanbanBoard();
  KanbanBoard(std::vector<std::string> fileRows);
  void printBoard();

  void getDoneUserStory();
  void getInProgressUserStory();
  void getToDoUserStory();
  void addStoryToMap(UserStory& userStory);

  void updateStatus(int storyID, int newStatus);
};
