#pragma once
#include "Collaborator.h"
class Developer : public Collaborator
{
public:
	Developer(std::string name);

	void assignStory(int storyID);

};


