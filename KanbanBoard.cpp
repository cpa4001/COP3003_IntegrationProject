/*
        Name: KanbanBoard.cpp
        Author: Christian Apostoli
        Purpose: implementation file for KanbanBoard class
                 inherits from Board Interface

*/

#include "KanbanBoard.h"

// goals for this class:
// - try to spit out using iterators

KanbanBoard::KanbanBoard() {}

/*
    Creates the KanbanBoard and intializes the statusMap
*/
KanbanBoard::KanbanBoard(std::vector<std::string> fileRows) {
  for (int row = 1; row < fileRows.size(); row++) {
    std::string storyID = fileRows[row].substr(0, fileRows[row].find(","));

    /*
    code for the condition in if statement was pulled from
    https://stackoverflow.com/questions/2340281/
    check-if-a-string-contains-a-string-in-c
    */
    if (fileRows[row].find("To Do") != std::string::npos) {
      statusMap.insert(std::pair<std::string, int>(storyID, 0));

    } else if (fileRows[row].find("In Progress") != std::string::npos) {
      statusMap.insert(std::pair<std::string, int>(storyID, 1));

    } else if (fileRows[row].find("Done") != std::string::npos) {
      statusMap.insert(std::pair<std::string, int>(storyID, 2));
    }
  }
}

/*
    Prints the name of the stories under each category based on their status.
   Prints story Ids for now
*/
void KanbanBoard::printBoard() {
  int maxToDoSpaces = 0;
  int maxInProgressSpaces = 0;
  std::string kanbanBoardLine = "";

  getToDoUserStory();
  getInProgressUserStory();
  getDoneUserStory();
  std::cout << std::endl;
}

void KanbanBoard::getDoneUserStory() {
  for (map_iterator = statusMap.begin(); map_iterator != statusMap.end();
       map_iterator++) {
    if (map_iterator->second == 2) {
      std::cout << " DONE : " << map_iterator->first << std::endl;
    }
  }
}
void KanbanBoard::getInProgressUserStory() {
  for (map_iterator = statusMap.begin(); map_iterator != statusMap.end();
       map_iterator++) {
    if (map_iterator->second == 1) {
      std::cout << " IN PROGRESS : " << map_iterator->first << std::endl;
    }
  }
}
void KanbanBoard::getToDoUserStory() {
  for (map_iterator = statusMap.begin(); map_iterator != statusMap.end();
       map_iterator++) {
    if (map_iterator->second == 0) {
      std::cout << " TO DO : " << map_iterator->first << std::endl;
    }
  }
}

/*
    Adds a story name and the status of that story to the statusMap hashmap
    Param:
    userStory   userstory object
*/
void KanbanBoard::addStoryToMap(UserStory& userStory) {
  statusMap.insert(std::pair<std::string, int>(
      std::to_string(userStory.storyID), userStory.getStatus()));
}

/*
    used to update status in the statusMap
*/
void KanbanBoard::updateStatus(int storyID, int newStatus) {
  if (statusMap.find(std::to_string(storyID)) != statusMap.end()) {
    statusMap[std::to_string(storyID)] = newStatus;
  } else {
    std::cout << "This story does not exist";
  }
}