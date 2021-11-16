#pragma once
#include "UserStory.h"
class Board {
 public:
	 virtual void createBoard() = 0;
	 virtual UserStory getDoneUserStory() = 0;
	 virtual UserStory getInProgressUserStory() = 0;
	 virtual UserStory getToDoUserStory() = 0;


};
