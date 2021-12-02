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
  int i = 0;
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
 *  @param userstory		userstory object
 */
void Backlog::addUserStory(UserStory& userStory) {
  productBacklog.push_back(userStory);
}

/** @brief appends to row attribute (vector of rows)
 *
 *  @param newRow string to append to vector
 */
void Backlog::addToRow(std::string newRow) { row.push_back(newRow); }

/** @brief Iterates through row vector and prints each element on seperate      
           lines
 */
void Backlog::printStories() {
  for (size_t index = 0; index < row.size(); index++) {
    std::cout << row[index] << std::endl;
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
  for (size_t line = 0; line < row.size(); line++) {
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

/** @brief getter for matrix attribute
 * 
 *  @return matrix      2D vector of strings
 */
std::vector<std::vector<std::string>> Backlog::getMatrix() { return matrix; }

/** @brief getter for productBacklog attribute
 *
 *  @return productBacklog      vector of UserStory objects
 */
std::vector<UserStory> Backlog::getProductBacklog() { return productBacklog; }

/** @brief getter for row attribute
 *
 *  @return row      vector of strings
 */
std::vector<std::string> Backlog::getRow() { return row; }

/** @brief overloaded unary minus operator
 *
 *  returns the most recent created user story if backlog has been created
 *  otherwise returns error message
 * 
 *  @param backlog  backlog object
 * 
 *  @return the most recently created User Story 
 */
std::string operator-(Backlog& backlog) {
  int backlogSize = backlog.row.size();

  if (backlogSize > 1) {
    return backlog.row[backlogSize - 1];
  } else {
    return "There are no user stories created";
  }
}
