#pragma once
#include "Backlog.h"
#include "UserStory.h"
class Board {
 public:
  virtual void createBoard() = 0;
  virtual void getDoneUserStory(Backlog& backlog) = 0;
  virtual void getInProgressUserStory(Backlog& backlog) = 0;
  virtual void getToDoUserStory(Backlog& backlog) = 0;
};
