/*
	Name: Source.cpp
	Author: Christian Apostoli
	Purpose: Main implementation file for program
*/

#include <iostream>
#include <fstream>
#include "UserStory.h"
#include "Backlog.h"

#include "Sprint.h"
#include "Release.h"

#include "Developer.h"
#include "ScrumMaster.h"

//could have some of these functions in a file class
std::ostream& operator<<(std::ostream& out, UserStory &userstory);
UserStory createUserStory();
void saveUserStory(UserStory& userstory, std::ofstream& savedUserStories);
bool is_empty(std::ifstream& pFile);
void createAndSaveStory(std::ofstream& writeToUserStories);
void lookUpProductBackLog(std::ifstream& readFromUserStories);
void createBorder();


int main() {

	//Open the UserStory file
	//Note: ios is a namespace within std namespace, so use the following
	std::ofstream writeToUserStories("UserStories.csv", std::ios::app);
	std::ifstream readFromUserStories("UserStories.csv");

	

	if (writeToUserStories.is_open() && is_empty(readFromUserStories))
	{
		writeToUserStories << "Story ID, Description, Story Points, Status,";
		writeToUserStories << " Current Developers\n";
	}

	int	userInputKey = 0;
	do {

		std::cout << "Please Pick an option(0-5)" << std::endl;
		std::cout << "Add a User Story                   (1)" << std::endl;
		std::cout << "Look up Product Backlog		   (2)" << std::endl;
		std::cout << "Assign a User Story to a developer (3)" << std::endl;
		std::cout << "Create Iteration		   (4)" << std::endl;
		std::cout << "See Kanban Board		   (5)" << std::endl;
		std::cout << "Exit				   (0)" << std::endl;

		createBorder();
		
		std::cin >> userInputKey;
		std::cin.clear();
		std::cin.ignore();

		Collaborator* collaborator = new Developer("");

		switch (userInputKey) {
			case 0:
				break;
			case 1:
				createAndSaveStory(writeToUserStories);
				createBorder();
				break;
			case 2:
				lookUpProductBackLog(readFromUserStories);
				createBorder();
				break;
			case 3: 
				int inputStoryID;
				std::cout << "What Story ID is the developer woking on: ";
				std::cin >> inputStoryID;
				collaborator->assignStory(inputStoryID);
				std::cout << "The developer is now working on storyID " << inputStoryID << std::endl;
				createBorder();
				break;
			case 4: case 5:
				std::cout << "This feature has not been devloped yet" << std::endl;
				break;
			default:
				std::cout << "You entered in an invalid number please enter an integer (0-5)" << std::endl;
				
		}

	} while (userInputKey);

	//close the csv to clear memmory
	//readFromUserStories.close();
	//writeToUserStories.close();


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
out << userstory.getStoryName() << " " << userstory.getStoryBody() << " " << userstory.getStoryPoints();
	return out;
}

/**
* Prompts user for input and creates userstory object
* Returns:
* newStory	new UserStory object created
*/
UserStory createUserStory() {
	std::string storyName;
	std::string storyBody;
	int storyPoints;

	std::cout << "Story Name: "; 
	//std::cin >> storyName;
	std::getline(std::cin, storyName);
	std::cout << std::endl;
	
	//std::cin.clear();

	std::cout << "Story Description: ";
	std::getline(std::cin, storyBody);
	std::cout << std::endl;

	std::cout << "Story Points: ";
	std::cin >> storyPoints;
	std::cout << std::endl;
	createBorder();
	std::cout << "You can see your new story in the Userstories.csv file in the same directory as this project" << std::endl;
	UserStory newStory(storyName, storyBody, storyPoints);
	return newStory;
}

/**
* Writes UserStory object to csv file
* Parameters:
* savedUserStories		ofstream object of output file
* userstory				userstory object
*/
void saveUserStory(UserStory &userstory, std::ofstream &savedUserStories) {
	
	if (savedUserStories.is_open())
	{
		savedUserStories << userstory.storyID << " ,"  << userstory.getStoryName() << ", " << userstory.getStoryBody() << ", " << userstory.getStoryPoints() << "\n";
	}
	else std::cout << "Unable to open file. You might have the file open in a seperate application.";
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
bool is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

/**
* calls the saveUserStory function
* Parameters:
* writeToUserStories		ofstream object of output file
*/
void createAndSaveStory(std::ofstream& writeToUserStories) {
	//ask for input
	//create userstory based on input
	UserStory newStory = createUserStory();

	//save to file
	saveUserStory(newStory, writeToUserStories);
}

void lookUpProductBackLog(std::ifstream& readFromUserStories) {
	//create a buffer for each line
	std::string line;
	if (readFromUserStories.is_open())
	{
		while (getline(readFromUserStories, line))
		{
			std::cout << line << '\n';
		}
		readFromUserStories.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
		

}

/**
* Prints border to screen 
*/
void createBorder() {
	std::cout << "---------------------------------------" << std::endl;
}

