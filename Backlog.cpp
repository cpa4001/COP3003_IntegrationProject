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
  int i = 0;
  if (readFromUserStories.is_open()) {
    while (getline(readFromUserStories, line)) {
      row.push_back(line);
      std::cout << i << " " << line << std::endl;
      i++;
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
 * adds row from file to the backlog(list of strings)
 * Parameters:
 * newRow		string from csv file
 */
void Backlog::addToRow(std::string newRow) { row.push_back(newRow); }

/**
 * prints names of user stories in the iteration's backolog to console
 */
void Backlog::printStories() {
  for (int index = 0; index < row.size(); index++) {
    std::cout << row[index] << std::endl;
  }
}

/*
    Finds a story based on their ID and then updates their status
*/
void Backlog::updateStoryStatus(int storyID, int newStatus) {
  for (int line = 0; line < row.size(); line++) {
    std::string tempStoryID = row[line].substr(0, row[line].find(","));
    int lineStoryID = std::stoi(tempStoryID);

    std::string previousStatus = "";
    std::string newStatusString = "";

    if (lineStoryID == storyID) {
      // row[line].replace(row[line].find("To Do"), row[line].find(","),
      // newStatus);

      if (row[line].find("To Do") != std::string::npos) {
        previousStatus = "To Do";
      } else if (row[line].find("In Progress") != std::string::npos) {
        previousStatus = "In Progress";

      } else if (row[line].find("Done") != std::string::npos) {
        previousStatus = "Done";
      }
      row[line].replace(row[line].find(previousStatus), row[line].find(","),
                        newStatusString);
    }
  }
}

void Backlog::updateStoryWithCollaborator(int storyID,
                                          std::string CollaboratorName) {
  std::ofstream writeToUserStories("UserStories.csv", std::ios::app);
  std::ifstream readFromUserStories("UserStories.csv");

  readFromUserStories.open("UserStories.csv");

  std::string line = "";
  if (readFromUserStories.is_open()) {
    while (getline(readFromUserStories, line)) {
      if (line.find(storyID) != std::string::npos) {
        writeToUserStories << line << ", " << CollaboratorName;
      }
    }
    readFromUserStories.close();
  } else {
    std::cout << "Unable to open file";
  }

  row[storyID] += (", " + CollaboratorName);
}

std::vector<std::vector<std::string>> Backlog::getMatrix() { return matrix; }

std::vector<UserStory> Backlog::getProductBacklog() { return productBacklog; }

std::vector<std::string> Backlog::getRow() { return row; }

/*  Gets the most recent userstory details(operator on aggregate) Param
    backlog the master backlog
    Param:
    backlog     the master backlog

*/
std::string operator-(Backlog& backlog) {
  int backlogSize = backlog.row.size();

  if (backlogSize > 1) {
    return backlog.row[backlogSize - 1];
  } else {
    return "There are no user stories created";
  }
}
