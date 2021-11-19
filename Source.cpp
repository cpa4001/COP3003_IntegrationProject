/*
        Name: Source.cpp
        Author: Christian Apostoli
        Purpose: Main implementation file for program
*/

#include <fstream>
#include <iostream>

#include "Backlog.h"
#include "Developer.h"
#include "KanbanBoard.h"
#include "Release.h"
#include "ScrumMaster.h"
#include "Sprint.h"
#include "UserStory.h"

// could have some of these functions in a file class
std::ostream& operator<<(std::ostream& out, UserStory& userstory);
UserStory createUserStory(Backlog& backlog);
void saveUserStory(UserStory& userstory, std::ofstream& savedUserStories,
                   Backlog& backlog);
bool is_empty(std::ifstream& pFile);
void createAndSaveStory(std::ofstream& writeToUserStories, Backlog& backlog);
void lookUpProductBackLog(std::ifstream& readFromUserStories);
void createBorder();

int main() {
  std::cout << "Welcome to a user story project managment tool developed by "
               "Christian Apostoli."
            << std::endl;
  std::cout << "You can use this console application to keep track of user "
               "stories in an Agile development team"
            << std::endl;
  createBorder();

  // Open the UserStory file
  // Note: ios is a namespace within std namespace, so use the following
  std::ofstream writeToUserStories("UserStories.csv", std::ios::app);
  std::ifstream readFromUserStories("UserStories.csv");

  // Create the backlog that will act as temp database
  Backlog masterBacklog(readFromUserStories);
  KanbanBoard kanbanBoard;

  // if the file is open and empty populate the header for the csv
  if (writeToUserStories.is_open() && is_empty(readFromUserStories)) {
    writeToUserStories << "Story ID, Story Name, Description, Story Points, "
                          "Status, Current Developers\n";
  }

  // give the menu until the user chooses to exit
  int userInputKey = 0;
  do {
    std::cout << "Please Pick an option(0-5)" << std::endl;
    std::cout << "Add a User Story                   (1)" << std::endl;
    std::cout << "Look up Product Backlog		   (2)" << std::endl;
    std::cout << "Assign a User Story to a developer (3)" << std::endl;
    std::cout << "Create Iteration		   (4)" << std::endl;
    std::cout << "See Kanban Board		   (5)" << std::endl;
    std::cout << "Exit				   (0)" << std::endl;

    std::cin >> userInputKey;
    std::cin.clear();
    std::cin.ignore();
    createBorder();

    /* Will try to implement input validation
    // Input validation to get to an integer
    if (std::cin >> userInputKey) {
      break;
    } else {
      // handles any input that is not an integer
      std::cout << "Please enter an integer (0-5)";
      std::cin.clear();
      std::cin.ignore();
    }

    std::cin.clear();
    std::cin.ignore();
    */

    // Collaborator* collaborator = new Developer("");
    Collaborator* collaborator;

    // variables to hold input
    int inputInt;
    std::string inputString;

    Iteration* iteration;

    switch (userInputKey) {
      case 0:
        break;
      case 1:
        createAndSaveStory(writeToUserStories, masterBacklog);
        createBorder();
        break;
      case 2:
        lookUpProductBackLog(readFromUserStories);
        createBorder();
        break;
      case 3:
        std::cout << "Are you a:\n(1) Scrum Master\n(2) Developer" << std::endl;
        std::cin >> inputInt;

        if (inputInt == 1) {
          std::cout << "What Story ID is the Scrum Master woking on: ";
          std::cin >> inputInt;
          std::cout << "What is the Scrum Master's name?";
          std::cin >> inputString;

          collaborator = new ScrumMaster(inputString);
          collaborator->assignStory(inputInt);

          std::cout << inputString << " is now working on storyID " << inputInt
                    << std::endl;
        } else if (inputInt == 2) {
          std::cout << "What Story ID is the developer woking on: ";
          std::cin >> inputInt;
          // std::cout << std::endl;

          std::cout << "What is this Developer's Name?";
          std::cin >> inputString;
          collaborator = new Developer(inputString);
          collaborator->assignStory(inputInt);

          std::cout << inputString << " is now working on storyID " << inputInt
                    << std::endl;
        }

        createBorder();
        break;
      case 4:
        std::cout << "What is the name of the iteration?";
        std::cin >> inputString;

        std::cout << "Will this iteration be a:\n (1) Release\n(2) Sprint";
        std::cin >> inputInt;

        if (inputInt == 1) {
          iteration = new Release(inputString, 0);
        } else if (inputInt == 2) {
          iteration = new Sprint(inputString, 0);
        }

      case 5:
        std::cout << "This feature has not been devloped yet" << std::endl;

        for (int index = 0; index < masterBacklog.getProductBacklog().size();
             index++) {
          kanbanBoard.addStoryToMap(masterBacklog.getProductBacklog()[index]);
        }
        break;
      default:
        std::cout
            << "You entered in an invalid number please enter an integer (0-5)"
            << std::endl;
    }

  } while (userInputKey);

  // close the csv to clear memmory
  // readFromUserStories.close();
  // writeToUserStories.close();

  return 0;
}

/**
 * Overloaded operator to print out attributes of user story object
 * Parameters:
 * out		ofstream object of output file
 * userstory	userstory object
 * Returns:
 * out		attributes of userstory
 */
std::ostream& operator<<(std::ostream& out, UserStory& userstory) {
  out << userstory.getStoryName() << " " << userstory.getStoryBody() << " "
      << userstory.getStoryPoints();
  return out;
}

/**
 * Prompts user for input and creates userstory object
 * Returns:
 * newStory	new UserStory object created
 */
UserStory createUserStory(Backlog& backlog) {
  std::string storyName;
  std::string storyBody;
  int storyPoints;

  std::cout << "Story Name: ";
  // std::cin >> storyName;
  std::getline(std::cin, storyName);
  std::cout << std::endl;

  std::cin.clear();

  std::cout << "Story Description: ";
  std::getline(std::cin, storyBody);
  std::cout << std::endl;

  std::cout << "Story Points: ";
  std::cin >> storyPoints;
  std::cout << std::endl;
  createBorder();
  std::cout << "You can see your new story in the Userstories.csv file in the "
               "same directory as this project"
            << std::endl;
  UserStory newStory(storyName, storyBody, storyPoints);
  backlog.addUserStory(newStory);
  return newStory;
}

/**
 * Writes UserStory object to csv file
 * Parameters:
 * savedUserStories		ofstream object of output file
 * userstory				userstory object
 */
void saveUserStory(UserStory& userstory, std::ofstream& savedUserStories,
                   Backlog& backlog) {
  if (savedUserStories.is_open()) {
    savedUserStories << userstory.storyID << " ," << userstory.getStoryName()
                     << ", " << userstory.getStoryBody() << ", "
                     << userstory.getStoryPoints() << ", "
                     << userstory.getStatus() << "\n";
  } else
    std::cout << "Unable to open file. You might have the file open in a "
                 "seperate application."
              << std::endl;
}

/*
Code was taken from
* https://newbedev.com/checking-for-an-empty-file-in-c
* sees if a file is empty
* Parameters:
* pFile		ifstream object or input file
* Returns:
* bool
*/
bool is_empty(std::ifstream& pFile) {
  return pFile.peek() == std::ifstream::traits_type::eof();
}

/**
 * calls the saveUserStory function
 * Parameters:
 * writeToUserStories		ofstream object of output file
 */
void createAndSaveStory(std::ofstream& writeToUserStories, Backlog& backlog) {
  // ask for input
  // create userstory based on input
  UserStory newStory = createUserStory(backlog);

  // save to file
  saveUserStory(newStory, writeToUserStories, backlog);
}

void lookUpProductBackLog(std::ifstream& readFromUserStories) {
  // create a buffer for each line
  std::string line;
  if (readFromUserStories.is_open()) {
    while (getline(readFromUserStories, line)) {
      std::cout << line << '\n';
    }
    readFromUserStories.close();
  } else {
    std::cout << "Unable to open file, you might have the file open \nin "
                 "another application,or the file has not been created."
              << std::endl;
  }
}

/**
 * Prints border to screen
 */
void createBorder() {
  std::cout << "---------------------------------------" << std::endl;
}
