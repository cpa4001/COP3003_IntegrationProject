/** @file Backlog.cpp
 *  @brief Implementation file for Backlog class
 *
 *	Method definitions for Backlog class
 *
 *	@author Christian Apostoli
 *	@bug No way found to update file with updated status
 *  @bug No way found to update file with collaborators
 */

#include "Backlog.h"

#include <gsl/gsl>
#include <iostream>

/** @brief default Backlog constructor
 *
 *  Intialize Backlog and add all the stories from the Userstories.csv to
 *   create a temporary backlog as a vector of strings where each element is a
 *   line from the file
 *
 *  @param readFromUserStories input file stream opject
 */
Backlog::Backlog(std::ifstream& readFromUserStories) {
  // create a buffer for each line
  std::string line;
  if (readFromUserStories.is_open()) {
    while (getline(readFromUserStories, line)) {
      row.push_back(line);
    }
    readFromUserStories.close();
  } else {
    std::cout << "Unable to open file";
  }
}

/** @brief adds UserStory to the productBacklog attribute
 *
 *  Appends to a vector of UserStory objects
 *
 *  @param userStory		userstory object
 */
void Backlog::addUserStory(const UserStory& userStory) {
  productBacklog.push_back(userStory);
}

/** @brief appends to row attribute (vector of rows)
 *
 *  @param newRow string to append to vector
 */
void Backlog::addToRow(std::string newRow) { row.push_back(newRow); }

/** @brief Iterates through row vector and prints each element on seperate
 *         lines
 */
void Backlog::printStories() {
  for (auto& fileLine : row) {
    std::cout << fileLine << std::endl;
  }
}

/** @brief updates the status of a user sotry in UserStories.csv
 *
 *   Iterates through the csv file and finds the line with the storyID
 *   and updates it to the new status. Currently there is no way to edit
 *   a specific location in the file
 *
 *   @param storyID    the id of the story that needs to be changed
 *   @param newStatus  the new status of the selected story
 */
void Backlog::updateStoryStatus(int storyID, int newStatus) {
  for (size_t line = 0; line < row.size(); ++line) {
    std::string tempStoryID = row.at(line).substr(0, row.at(line).find(","));
    const int lineStoryID = std::stoi(tempStoryID);

    std::string previousStatus;
    std::string newStatusString;

    if (lineStoryID == storyID) {
      // row[line].replace(row[line].find("To Do"), row[line].find(","),
      // newStatus);

      if (row.at(line).find("To Do") != std::string::npos) {
        previousStatus = "To Do";
      } else if (row.at(line).find("In Progress") != std::string::npos) {
        previousStatus = "In Progress";

      } else if (row.at(line).find("Done") != std::string::npos) {
        previousStatus = "Done";
      }
      row.at(line).replace(row.at(line).find(previousStatus),
                           row.at(line).find(","), newStatusString);
    }
  }
}

/** @brief updates user sotry in UserStories.csv with the collaborators
 *
 *   Iterates through the csv file and finds the line with the storyID
 *   and writes collaborators that are working on the story. Currently
 *   there is no way to edit a specific location in the file
 *
 *   @param storyID           the id of the story that needs to be changed
 *   @param CollaboratorName  the name of the
 *
 */
void Backlog::updateStoryWithCollaborator(int storyID,
                                          std::string CollaboratorName) {
  std::ofstream writeToUserStories("UserStories.csv", std::ios::app);
  std::ifstream readFromUserStories("UserStories.csv");

  readFromUserStories.open("UserStories.csv");

  std::string line;
  if (readFromUserStories.is_open()) {
    while (getline(readFromUserStories, line)) {
      if (line.find(gsl::narrow_cast<char>(storyID)) != std::string::npos) {
        writeToUserStories << line << ", " << CollaboratorName;
      }
    }
    readFromUserStories.close();
  } else {
    std::cout << "Unable to open file";
  }

  row.at(storyID) += (", " + CollaboratorName);
}

/** @brief getter for matrix attribute
 *
 *  @return matrix      2D vector of strings
 */
auto Backlog::getMatrix() -> std::vector<std::vector<std::string>> {
  return matrix;
}

/** @brief getter for productBacklog attribute
 *
 *  @return productBacklog      vector of UserStory objects
 */
auto Backlog::getProductBacklog() -> std::vector<UserStory> {
  return productBacklog;
}

/** @brief getter for row attribute
 *
 *  @return row      vector of strings
 */
auto Backlog::getRow() -> std::vector<std::string> { return row; }

/** LO7
 *  @brief overloaded unary minus operator
 *
 *  returns the most recent created user story if backlog has been created
 *  otherwise returns error message
 *
 *  @param backlog  backlog object
 *
 *  @return the most recently created User Story
 */
auto operator-(Backlog& backlog) -> std::string {
  const int backlogSize = gsl::narrow_cast<int>(backlog.row.size());

  std::string returnString;

  if (backlogSize > 1) {
    returnString = backlog.row.at(backlogSize - 1);
  } else {
    returnString = "There are no user stories created";
  }
  return returnString;
}
