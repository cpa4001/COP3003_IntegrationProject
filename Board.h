/*
        Name: Board.h
        Author: Christian Apostoli
        Purpose: Declaration file for Board interface
*/

#pragma once
#include "Backlog.h"
#include "UserStory.h"
class Board {
 public:
  virtual void printBoard() = 0;
  virtual void getDoneUserStory(Backlog& backlog) = 0;
  virtual void getInProgressUserStory(Backlog& backlog) = 0;
  virtual void getToDoUserStory(Backlog& backlog) = 0;

  virtual void addStoryToMap(UserStory& userStory) = 0;
};
