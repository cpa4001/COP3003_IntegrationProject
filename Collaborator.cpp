#include "Collaborator.h"

/**
	default constructor - intialize empty Collaborator
*/
Collaborator::Collaborator() {
	collaboratorName = "";

	collaboratorID++;
}

/**
* Constructor for Collaborator
* Parameters:
* collaboratorName	name of the collaborator
* role				role of collaborator within the project
*/
Collaborator::Collaborator(std::string collaboratorName, std::string role) {
	this->collaboratorName = collaboratorName;
	this->role = role;

	collaboratorID++;
}


ScrumMaster::ScrumMaster(std::string collaboratorName) : Collaborator(collaboratorName, "Scrum Master") {}

/**
* 
*/
void ScrumMaster::assignStoryToCollaborator(int collaboratorID, int storyID) {

}