#include "Collaborator.h"

Collaborator::Collaborator() {
	collaboratorName = "";

	collaboratorID++;
}

Collaborator::Collaborator(std::string collaboratorName, std::string role) {
	this->collaboratorName = collaboratorName;
	this->role = role;

	collaboratorID++;
}

ScrumMaster::ScrumMaster(std::string collaboratorName) : Collaborator(collaboratorName, "Scrum Master") {}

void ScrumMaster::assignStoryToCollaborator(int collaboratorID, int storyID) {

}