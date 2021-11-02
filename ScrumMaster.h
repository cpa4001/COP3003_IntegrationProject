#pragma once
#include "Collaborator.h"
class ScrumMaster : public Collaborator
{
public:
	ScrumMaster(std::string collaboratorName);

	void assignStoryToCollaborator(int collaboratorID, int storyID);

};

