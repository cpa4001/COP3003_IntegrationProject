/** @file Board.h
 *  @brief Declaration file for Board interface
 *
 *	Pure virtual method prototypes for Board Interface
 *
 *	@author Christian Apostoli
 *	@bug No known bugs
 */

#ifndef BOARD_H
#define BOARD_H
#include "Backlog.h"
#include "UserStory.h"
// LO6

/**
 * @brief any type of diagram that can aid in development
 */
class Board {
 public:
  virtual void printBoard() = 0;
  virtual void getDoneUserStory() = 0;
  virtual void getInProgressUserStory() = 0;
  virtual void getToDoUserStory() = 0;

  virtual void addStoryToMap(UserStory& userStory) = 0;
  virtual void updateStatus(int storyID, int newStatus) = 0;
};
#endif BOARD_H