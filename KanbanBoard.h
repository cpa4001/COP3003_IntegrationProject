/** @file KanbanBoard.h
 *  @brief Declaration file for KanbanBoard class
 *
 *	Declaration for KanbanBoard class and blueprint for
 *	kanban board objects in main. Inherits from Board interface
 *
 *	@author Christian Apostoli
 *	@bug No known bugs
 */

#ifndef KANBANBOARD_H
#define KANBANBOARD_H
#include <string>
#include <vector>

#include "Board.h"

// LO1a
// LO2
// LO2a

/**
 *	@brief a board that shows user stories in all three statuses
 *	KanbanBoard inherits from Board interface with public visibility
 */
class KanbanBoard : public Board {
 private:
  std::vector<std::string> toDoUserStoryNames;
  std::vector<std::string> inProgressUserStoryNames;
  std::vector<std::string> doneUserStoryNames;
  std::map<std::string, int> statusMap;
  std::map<std::string, int>::iterator map_iterator;

 public:
  KanbanBoard() noexcept = default;
  explicit KanbanBoard(std::vector<std::string> fileRows);
  void printBoard() override;

  void getDoneUserStory() override;
  void getInProgressUserStory() override;
  void getToDoUserStory() override;
  void addStoryToMap(UserStory& userStory) override;

  void updateStatus(int storyID, int newStatus) override;
};
#endif