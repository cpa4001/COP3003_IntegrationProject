/** @file Source.cpp
 *  @brief Main implementation file for program
 *  @author Christian Apostoli
 *  @bug userstory::storyID will increase by two at times
 *  @bug little input validation
 */

#include <fstream>
#include <gsl/gsl>
#include <iostream>
#include <string>

#include "Backlog.h"
#include "Developer.h"
#include "KanbanBoard.h"
#include "Release.h"
#include "ScrumMaster.h"
#include "Sprint.h"
#include "UserStory.h"

auto operator<<(std::ostream& out, UserStory& userstory) -> std::ostream&;
auto createUserStory(Backlog& backlog) -> UserStory;
void saveUserStory(UserStory& userstory, std::ofstream& savedUserStories,
                   Backlog& backlog, KanbanBoard& kanbanBoard);
auto is_empty(std::ifstream& pFile) -> bool;
void createAndSaveStory(std::ofstream& writeToUserStories, Backlog& backlog,
                        KanbanBoard& kanbanBoard);
void createBorder();
void invokeFunc(void (*func)()) noexcept;
auto replace(std::string& str, const std::string& from, const std::string& to)
    -> bool;
auto validateIntegerInput(int inputInt, std::string errorMessage, 
                          int lowerBound, int upperBound) -> int;

constexpr int EXIT = 0;
constexpr int CREATE_USER_STORY = 1;
constexpr int LOOK_UP_BACKLOG = 2;
constexpr int ADD_COLLABORATOR = 3;
constexpr int ADD_ITERATION = 4;
constexpr int KANBAN_BOARD = 5;
constexpr int MOST_RECENT_USER_STORY = 6;
constexpr int UPDATE_STATUS = 7;

/**
 * @brief implementation of program for user story management tool
 * @return status code for program
 */
int main() {
  std::cout << "Welcome to a user story project management \ntool developed by "
               "Christian Apostoli. ";
  std::cout << "You \ncan use this console application to keep \ntrack of user "
               "stories in an Agile development team.\n"
            << std::endl;

  std::cout << "The program will create a csv file (in the same \ndirectory as "
               "this project) for your user stories \nand "
               "give you a series of options to interact \nwith the file"
            << std::endl;
  createBorder();

  // Open the UserStory file
  // Note: ios is a namespace within std namespace, so use the following
  std::ofstream writeToUserStories("UserStories.csv", std::ios::app);
  std::ifstream readFromUserStories("UserStories.csv");

  // LO1
  // Create the backlog that will act as temp database
  Backlog masterBacklog(readFromUserStories);
  KanbanBoard kanbanBoard(masterBacklog.getRow());

  const std::string fileHeader =
      "Story ID, Story Name, Description, Story Points, "
      "Status, Current Developers";

  readFromUserStories.open("UserStories.csv");
  // used for reading from the file in case 4
  std::string line;
  // read in the fist line
  std::getline(readFromUserStories, line);

  // if the fist line is NOT the header add the header
  if (line != fileHeader) {
    writeToUserStories << fileHeader;
    writeToUserStories << "\n";
  }

  // update the storyID so that the next userstory gets the correct storyID
  UserStory::storyID = gsl::narrow_cast<int>(masterBacklog.getRow().size() - 1);

  // give the menu until the user chooses to exit
  // standard length for menu options is 42 character
  int userInputKey = 0;
  bool continueProgramFlag = false;
  do {
    std::cout << "Please Pick an option(Enter an integer 0-7)" << std::endl;
    std::cout << "Add a User Story                      (1)" << std::endl;
    std::cout << "Look up Product Backlog               (2)" << std::endl;
    std::cout << "Assign a User Story to a Collaborator (3)" << std::endl;
    std::cout << "Create Iteration                      (4)" << std::endl;
    std::cout << "See Kanban Board                      (5)" << std::endl;
    std::cout << "Get the most recent User Story        (6)" << std::endl;
    std::cout << "Set User Story Status                 (7)" << std::endl;
    std::cout << "Exit                                  (0)" << std::endl;

    /*
    std::cin >> userInputKey;
    std::cin.clear();
    std::cin.ignore();
    */
    userInputKey =
        validateIntegerInput(userInputKey, "positive integer (0-7)", 0, 7);
    std::cin.clear();
    std::cin.ignore();
    createBorder();

    // LO1
    // declare pointers here because initialization is not allowed within switch
    // we are leaving these unitialized for polymorphism to perform at
    // runtime
    Collaborator* collaborator;
    Iteration* iteration;

    // variables to hold input
    int inputInt = 0;
    std::string inputString;

    int status = 0;

    switch (userInputKey) {
      case EXIT:
        break;
      case CREATE_USER_STORY:
        // collect user input and write to csv file
        createAndSaveStory(writeToUserStories, masterBacklog, kanbanBoard);
        createBorder();
        break;
      case LOOK_UP_BACKLOG:
        // Print out all records of the userstory.csv file
        // lookUpProductBackLog();
        std::cout << "Product Backlog: " << std::endl;
        masterBacklog.printStories();
        createBorder();
        break;
      case ADD_COLLABORATOR:
        // prompt the user about details for the collaborator
        std::cout << "Are you a:\n(1) Scrum Master\n(2) Developer" << std::endl;
        std::cout << "Enter an integer 1-2" << std::endl;

        inputInt = validateIntegerInput(inputInt, "positive integer (1-2)", 1, 2);

        if (inputInt == 1) {
          // prompt the user for an ID until ID is valid
          std::cout << "What Story ID is the Scrum Master woking on: ";

          inputInt = validateIntegerInput(inputInt, "valid story ID", 1, 
                                          UserStory::storyID);

          std::cout << "What is the Scrum Master's name? ";
          std::cin >> inputString;

          // LO5
          // point to the necessary collaborator and assign the story to them
          collaborator = new ScrumMaster(inputString);
          // LO3
          // using polymorphism through dynamic dispatch
          collaborator->assignStory(inputInt);

          std::cout << inputString << " is now working on storyID " << inputInt
                    << std::endl;
        } else if (inputInt == 2) {
          // prompt the user for an ID until ID is valid
          std::cout << "What Story ID is the developer woking on: ";

          inputInt = validateIntegerInput(inputInt, "valid story ID", 1,
                                          UserStory::storyID);
          // std::cout << std::endl;

          std::cout << "What is this Developer's Name? ";
          std::cin >> inputString;

          // LO5
          // point to the necessary collaborator and assign the story to them
          collaborator = new Developer(inputString);
          // LO3
          // using polymorphism through dynamic dispatch
          collaborator->assignStory(inputInt);

          std::cout << inputString << " is now working on storyID " << inputInt
                    << std::endl;
        }

        // update the backlog and the file
        // masterBacklog.updateStoryWithCollaborator(inputInt, inputString);

        createBorder();
        break;
      case ADD_ITERATION:
        // prompt the user for details about the iteration
        std::cout << "What is the name of the iteration? ";
        std::cin >> inputString;

        std::cout << "Will this iteration be a:\n(1) Release\n(2) Sprint"
                  << std::endl;
        std::cout << "(Enter an Integer 1-2)" << std::endl;

        inputInt = validateIntegerInput(inputInt, "positive integer (1-2)", 1, 2);

        // LO1, LO5
        // point the iteration to the correct subclass
        if (inputInt == 1) {
          iteration = new Release(inputString, 0);
        } else if (inputInt == 2) {
          iteration = new Sprint(inputString, 0);
        } else {
          iteration = new Iteration(inputString, "Iteration", 0);
        }

        std::cout << "How long will this Iteration consist of in days? (Enter "
                     "a positive integer) ";

        inputInt =
            validateIntegerInput(inputInt, "a positive integer", 1, INT_MAX);
        // LO3
        // additional use of polymorphism
        iteration->setIterationLength(inputInt);

        createBorder();
        break;

      case KANBAN_BOARD:

        std::cout << "Kanban Board: " << std::endl;
        // print the user story ids with their statuses
        kanbanBoard.printBoard();
        createBorder();
        break;
      case MOST_RECENT_USER_STORY:
        std::cout << " The most recent user story entered was: " << std::endl;
        // get the most recent user story details by using the overloaded -
        // operator
        std::cout << -masterBacklog << std::endl;

        // LO7
        // passing in a the address of createBorder() to return that void
        // function
        invokeFunc(&createBorder);
        break;
      case UPDATE_STATUS:
        std::cout << "This feature is still in development" << std::endl;
        std::cout
            << "What is the ID of the story that you would like to change? "
            << std::endl;

        inputInt = validateIntegerInput(inputInt, "valid story ID", 1,
                                          UserStory::storyID);

        std::cout << "What is its new status? (Enter an positive integer 1-3)"
                  << std::endl;
        std::cout << "(1) To Do \n(2) In Progress \n(3) Done" << std::endl;

        status = validateIntegerInput(status, "postive intger (1-3)", 1, 3);

        // iterate through backlog
        // find row with story ID
        // update to new status
        // masterBacklog.updateStoryStatus(inputInt, status);

        kanbanBoard.updateStatus(inputInt - 1, status);
        std::cout << "Story ID, " << inputInt << ", has been changed to status "
                  << status << std::endl;
        createBorder();
        break;
      default:
        std::cout
            << "You entered in an invalid number please enter an integer (0-7)"
            << std::endl;
        createBorder();
    }

    // avoid narrow conversion warning
    continueProgramFlag = bool(userInputKey);
  } while (continueProgramFlag);

  std::cout << "Program Exited. Have a nice day." << std::endl;

  // close the csv to clear memmory
  // readFromUserStories.close();
  // writeToUserStories.close();

  return 0;
}

/** LO7
 * @brief Overloaded operator to print out user story atributes
 *  @param out		    ofstream object of output file userstory
 *  @param              userstory object
 *
 *  @returns out		output stream
 */
auto operator<<(std::ostream& out, UserStory& userstory) -> std::ostream& {
  out << userstory.getStoryName() << " " << userstory.getStoryBody() << " "
      << userstory.getStoryPoints();
  return out;
}

/**
 * @brief prompts user for input and creates userstory object
 *
 * Had to create a function since the switch does not allow intialization
 *
 * @param backlog       backlog object that holds user stories
 *
 * @return newStory	    new UserStory object created
 */
auto createUserStory(Backlog& backlog) -> UserStory {
  std::cout << "Enter User Story details as a sequence of words (Please do not "
               "use commas)\n";
  std::string storyName;
  std::string storyBody;
  int storyPoints = 0;

  std::cout << "Enter the Story Name: ";
  // std::cin >> storyName;
  std::getline(std::cin, storyName);
  std::cout << std::endl;
  std::cin.clear();

  // strips away all commas so values can be in one cell in csv
  replace(storyName, ",", "");

  std::cout << "Enter the Story Description: ";
  std::getline(std::cin, storyBody);
  std::cout << std::endl;

  // strips away all commas so values can be in one cell in csv
  replace(storyBody, ",", "");

  std::cout << "Enter the Story Points as a positive integer: ";
  std::cin >> storyPoints;
  std::cout << std::endl;

  storyPoints =
      validateIntegerInput(storyPoints, "enter a positive integer", 1, INT_MAX);
  createBorder();

  std::cout << storyName << " has been added to Userstories.csv" << std::endl;
  std::cout
      << "You can see your new story in the \nUserstories.csv file in the "
         "same directory as this project"
      << std::endl;
  // LO1
  UserStory newStory(storyName, storyBody, storyPoints);
  return newStory;
}

/**
 * @brief writes UserStory object to csv
 *
 * adds string to backlogs vector and adds story to kanbanboard's hashmap
 *
 * @param userstory				userstory object
 * @param savedUserStories		ofstream object of output file
 * @param backlog               backlog object that holds use stories
 * @param kanbanBoard           kanbanboard object
 */
void saveUserStory(UserStory& userstory, std::ofstream& savedUserStories,
                   Backlog& backlog, KanbanBoard& kanbanBoard) {
  if (savedUserStories.is_open()) {
    savedUserStories << UserStory::storyID << ", " << userstory.getStoryName()
                     << ", " << userstory.getStoryBody() << ", "
                     << userstory.getStoryPoints() << ", "
                     << userstory.getStatusString() << "\n";
  } else {
    std::cout << "Unable to open file. You might have the file open in a "
                 "seperate application."
              << std::endl;
  }

  // adds the user story to backlog and the kanbanBoard
  backlog.addToRow(std::to_string(UserStory::storyID) + ", " +
                   userstory.getStoryName() + "," + userstory.getStoryBody() +
                   ", " + std::to_string(userstory.getStoryPoints()) + ", " +
                   userstory.getStatusString() + "\n");

  kanbanBoard.addStoryToMap(userstory);
}

/**
 * @brief sees if a file is empty
 *
 * Code was taken from
 * https://newbedev.com/checking-for-an-empty-file-in-c
 *
 * @param pFile		ifstream object or input file
 *
 * @return bool
 */
auto is_empty(std::ifstream& pFile) -> bool {
  return pFile.peek() == std::ifstream::traits_type::eof();
}

/**
 * @brief creates UserStory object and calls the saveUserStory function
 *
 * @param writeToUserStories		ofstream object of output file
 * @param backlog                   backlog object that holds user stories
 * @param kanbanBoard               kanbanBoard object
 */
void createAndSaveStory(std::ofstream& writeToUserStories, Backlog& backlog,
                        KanbanBoard& kanbanBoard) {
  // LO1
  // ask for input
  // create userstory based on input
  UserStory newStory = createUserStory(backlog);

  // save to file
  saveUserStory(newStory, writeToUserStories, backlog, kanbanBoard);
}

/**
 * @brief Prints border to screen
 */
void createBorder() {
  std::cout << "---------------------------------------" << std::endl;
}

/**  LO7
 *   @brief demonstration of passing functions as parameters
 *
 *   can call any void function with no parameters in main
 *
 *   @param (*func)()   the memory location of a function
 */
void invokeFunc(void (*func)()) noexcept { return func(); }

/**
 * @brief replaces all occurances of a string with another string
 *
 *  uses recursion to replace a substring until substring can not be found
 *  code was found at https://stackoverflow.com/questions/3418231/replace-
    part-of-a-string-with-another-string
 *
 * @param str   string to be edited
 * @param from  substring to be replaced
 * @param to    substring that will replace from
 * @return
 */
auto replace(std::string& str, const std::string& from, const std::string& to)
    -> bool {
  const size_t start_pos = str.find(from);
  if (start_pos == std::string::npos) {
    return false;
  }
  str.replace(start_pos, from.length(), to);
  return true;
}

/**
 * @brief verifies the integer the user inputs
 * 
 * Continuosly
 * https://stackoverflow.com/questions/16934183/integer-validation-for-input
 *
 * @param inputInt       the input that needs to validated
 * @param errorMessage   the message that goes with the prompt
 * @param lowerBound     the smallest value the integer input coule be
 * @param upperBound     the biggest value the integer input could be
 */
auto validateIntegerInput(int inputInt, std::string errorMessage, 
                          int lowerBound, int upperBound) -> int {
  bool valid = false;
  do {
    std::cin >> inputInt;
    if (std::cin.good() && inputInt >= lowerBound && inputInt <= upperBound) {
      // everything went well, we'll get out of the loop and return the value
      valid = true;
    } else {
      // something went wrong, we reset the buffer's state to good
      std::cin.clear();
      // and empty it
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input; please enter a " << errorMessage
                << std::endl;
    }
  } while (!valid);

  return (inputInt);
}