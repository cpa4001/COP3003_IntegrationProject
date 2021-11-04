#include "Developer.h"

Developer::Developer(std::string name) : Collaborator(name, "Developer") {}


void Developer::assignStory(int storyID) {
	storiesWorkingOn.push_back(storyID);
}
