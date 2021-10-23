/*
	Name: Source.cpp
	Author: Christian Apostoli
	Purpose: Main implementation file for program
*/

#include <iostream>
#include <fstream>
#include "UserStory.h"
#include "Backlog.h"
#include "Iteration.h"

std::ostream& operator<<(std::ostream& out, UserStory &userstory);
UserStory createUserStory();
void saveUserStory(UserStory& userstory, std::ofstream& savedUserStories);
bool is_empty(std::ifstream& pFile);
void createAndSaveStory(std::ofstream& writeToUserStories);

int main() {

	//Open the UserStory file
	std::ofstream writeToUserStories("UserStories.csv");
	std::ifstream readFromUserStories("UserStories.csv");

	if (writeToUserStories.is_open() && is_empty(readFromUserStories))
	{
		writeToUserStories << "Story ID, Story Body, Story Description, Status,";
		writeToUserStories << " Current Developers\n";
	}
	else std::cout << "Unable to open file";

	int	userInputKey = 0;
	do {

		std::cout << "Add a User Story                   (1)" << std::endl;
		std::cout << "Look up Product Backlog		   (2)" << std::endl;
		std::cout << "Assign a developer to a User Story (3)" << std::endl;
		std::cout << "Create Iteration		   (4)" << std::endl;
		std::cout << "See Kanban Board					(5)" << std::endl;
		std::cout << "Exit								(0)" << std::endl;
		
		std::cin >> userInputKey;
		std::cin.clear();
		//cin.ignore();


		switch (userInputKey) {
			case 1:
				createAndSaveStory(writeToUserStories);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}

	} while (userInputKey);

	//close the csv to clear memmory
	writeToUserStories.close();

	return 0;
}

std::ostream& operator<<(std::ostream& out, UserStory& userstory) {
out << userstory.getStoryName() << " " << userstory.getStoryBody() << " " << userstory.getStoryPoints();
	return out;
}

UserStory createUserStory() {
	std::string storyName;
	std::string storyBody;
	int storyPoints;

	std::cout << "Story Name: "; 
	std::cin >> storyName;
	std::cout << std::endl;
	//std::cin.clear();

	std::cout << "Story Description: ";
	std::cin >> storyBody;
	std::cout << std::endl;

	std::cout << "Story Points: ";
	std::cin >> storyPoints;
	std::cout << std::endl;

	UserStory newStory(storyName, storyBody, storyPoints);
	return newStory;
}

void saveUserStory(UserStory &userstory, std::ofstream &savedUserStories) {
	
	if (savedUserStories.is_open())
	{
		savedUserStories << userstory.getStoryName() << ", " << userstory.getStoryBody() << ", " << userstory.getStoryPoints() << "\n";
	}
	else std::cout << "Unable to open file";
}

/*
Code was taken from 
https://newbedev.com/checking-for-an-empty-file-in-c
*/
bool is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void createAndSaveStory(std::ofstream& writeToUserStories) {
	//ask for input
	//create userstory based on input
	UserStory newStory = createUserStory();

	//save to file
	saveUserStory(newStory, writeToUserStories);
}