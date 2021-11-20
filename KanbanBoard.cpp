/*
        Name: KanbanBoard.cpp
        Author: Christian Apostoli
        Purpose: implementation file for KanbanBoard class
                 inherits from Board Interface

*/

#include "KanbanBoard.h"

// goals for this class:
// - try to spit out using iterators

/*
    Prints the name of the stories under each category based on their status
*/
void KanbanBoard::createBoard() {
  int maxToDoSpaces = 0;
  int maxInProgressSpaces = 0;
  std::cout << "To Do | In Progress | Done" << std::endl;
  std::string kanbanBoardLine = "";

  std::map<std::string, int>::iterator map_iterator;

  for (map_iterator = statusMap.begin(); map_iterator != statusMap.end();
       map_iterator++) {
    if (map_iterator->second == 0) {
      std::cout << map_iterator->first << " |";

    } else if (map_iterator->second == 1) {
      std::cout << map_iterator->first << " |";

    } else if (map_iterator->second == 2) {
      std::cout << map_iterator->first << std::endl;
    }
    std::cout << map_iterator->first          // string (key)
              << ':' << map_iterator->second  // string's value
              << std::endl;
  }
}

void KanbanBoard::getDoneUserStory(Backlog& backlog) {
  /*
  std::vector<std::vector<std::string>> matrix = backlog.getMatrix();
  */
  std::map<std::string, int>::iterator map_iterator;

  for (map_iterator = statusMap.begin(); map_iterator != statusMap.end();
       map_iterator++) {
    std::cout << map_iterator->first          // string (key)
              << ':' << map_iterator->second  // string's value
              << std::endl;
  }
}
void KanbanBoard::getInProgressUserStory(Backlog& backlog) {}
void KanbanBoard::getToDoUserStory(Backlog& backlog) {}

/*
    Adds a story name and the status of that story to the statusMap hashmap
    Param:
    userStory   userstory object
*/
void KanbanBoard::addStoryToMap(UserStory& userStory) {
  statusMap.insert({userStory.getStoryName(), userStory.getStatus()});
}