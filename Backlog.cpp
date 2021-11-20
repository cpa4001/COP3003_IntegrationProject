/*
        Name: Backlog.cpp
        Author: Christian Apostoli
        Purpose: Main implementation file for Backlog class
*/

#include "Backlog.h"

#include <iostream>

/**
        default constructor - intialize Backlog add all the stories from the
        Userstories.csv to create a temporary backlog
        Param:
        readFromUserStories input stream to read file
*/
Backlog::Backlog(std::ifstream& readFromUserStories) {
  // create a buffer for each line
  std::string line;
  if (readFromUserStories.is_open()) {
    while (getline(readFromUserStories, line)) {
      // std::cout << line << '\n';
      row.push_back(line);
      matrix.push_back(row);
    }
    readFromUserStories.close();
  } else {
    std::cout << "Unable to open file";
  }
}

/*
Backlog::~Backlog() {
        delete[] productBacklog;
}
*/

/**
 * adds UserStory to the backlog(list of userstories)
 * Parameters:
 * userstory		userstory object
 */
void Backlog::addUserStory(UserStory& userStory) {
  productBacklog.push_back(userStory);
}

/**
 * prints names of user stories in the iteration's backolog to console
 */
void Backlog::printStories() {
  for (int index = 0; index < productBacklog.size(); index++) {
    std::cout << productBacklog[index].getStoryName() << std::endl;
  }
}

std::vector<std::vector<std::string>> Backlog::getMatrix() { return matrix; }

std::vector<UserStory> Backlog::getProductBacklog() { return productBacklog; }

/*
std::ostream& operator<<(std::ostream& out, UserStory& userStory) {
  out << userStory.getStoryName();
  return out;
}
*/
