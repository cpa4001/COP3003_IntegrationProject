#pragma once
#include "Board.h"
class KanbanBoard : public Board {
 public:
  void createBoard();

  UserStory getDoneUserStory();
  UserStory getInProgressUserStory();
  UserStory getToDoUserStory();
};
