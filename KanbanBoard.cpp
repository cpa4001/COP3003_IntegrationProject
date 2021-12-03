/** @file KanbanBoard.cpp
 *  @brief Implementation file for KanbanBoard class
 *
 *	Implementation file for KanbanBoard class
    inherits from Board Interface
 *
 *	@author Christian Apostoli
 *	@bug kanban board only prints all columns in 1 vertical line
 *       instead of three columns side by side
 */

#include "KanbanBoard.h"

// LO2

KanbanBoard::KanbanBoard() noexcept {}

/**
 *   @brief Creates the KanbanBoard and intializes the statusMap
 *
 *   Iterates through vector and finds the status meaning and inserts
 *   into statusMap besed on meaning
 *
 *   @param fileRows vector of strings from the file
 */
KanbanBoard::KanbanBoard(std::vector<std::string> fileRows) {
  for (size_t row = 1; row < fileRows.size(); row++) {
    std::string storyID = fileRows.at(row).substr(0, fileRows.at(row).find(","));

    /*
    code for the condition in if statement was pulled from
    https://stackoverflow.com/questions/2340281/
    check-if-a-string-contains-a-string-in-c
    */
    if (fileRows.at(row).find("To Do") != std::string::npos) {
      statusMap.insert(std::pair<std::string, int>(storyID, 0));

    } else if (fileRows.at(row).find("In Progress") != std::string::npos) {
      statusMap.insert(std::pair<std::string, int>(storyID, 1));

    } else if (fileRows.at(row).find("Done") != std::string::npos) {
      statusMap.insert(std::pair<std::string, int>(storyID, 2));
    }
  }
}

/* LO5
    @brief Prints the name of the stories under each category based on their
    status.
*/
void KanbanBoard::printBoard() {
  // Variables could be used in formatting text
  // int maxToDoSpaces = 0;
  // int maxInProgressSpaces = 0;
  std::string kanbanBoardLine;

  getToDoUserStory();
  getInProgressUserStory();
  getDoneUserStory();
  std::cout << std::endl;
}

/** LO5
 * @brief iterates through statusMap and prints all storyids with done status
 */
void KanbanBoard::getDoneUserStory() {
  for (map_iterator = statusMap.begin(); map_iterator != statusMap.end();
       map_iterator++) {
    if (map_iterator->second == 2) {
      std::cout << " DONE : " << map_iterator->first << std::endl;
    }
  }
}

/** LO5
 * @brief iterates through statusMap and prints all storyids with in progress
 *  status
 */
void KanbanBoard::getInProgressUserStory() {
  for (map_iterator = statusMap.begin(); map_iterator != statusMap.end();
       map_iterator++) {
    if (map_iterator->second == 1) {
      std::cout << " IN PROGRESS : " << map_iterator->first << std::endl;
    }
  }
}

/** LO5
 * @brief iterates through statusMap and prints all storyids with to do status
 */
void KanbanBoard::getToDoUserStory() {
  for (map_iterator = statusMap.begin(); map_iterator != statusMap.end();
       map_iterator++) {
    if (map_iterator->second == 0) {
      std::cout << " TO DO : " << map_iterator->first << std::endl;
    }
  }
}

/** LO5
*   @brief Adds a story name and the status of that story to the statusMap 
*    hashmap
*   
*   @param userStory   userstory object
*/
void KanbanBoard::addStoryToMap(UserStory& userStory) {
  statusMap.insert(std::pair<std::string, int>(
      std::to_string(userStory.storyID), userStory.getStatus()));
}


/** LO5
 *   @brief used to update status in the statusMap
 *
 *   @param storyID     the id of the story that needs to be changed
 *   @param newStatus   the new status of the story
 */
void KanbanBoard::updateStatus(int storyID, int newStatus) {
  if (statusMap.find(std::to_string(storyID)) != statusMap.end()) {
    statusMap[std::to_string(storyID)] = newStatus;
  } else {
    std::cout << "This story does not exist";
  }
}