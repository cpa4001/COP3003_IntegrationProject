#pragma once
#include<string>
#include<vector>
class Collaborator
{
private:
	std::string collaboratorName;
	int collaboratorID;
	std::string role;
	std::vector<int> storiesWorkingOn;
public:
	Collaborator();
	Collaborator(std::string collaboratorName, std::string role);
	
};

class ScrumMaster : public Collaborator
{
public:
	ScrumMaster(std::string collaboratorName);

	void assignStoryToCollaborator(int collaboratorID, int storyID);
	
};

class Developer : public Collaborator
{
public:
	Developer();
	

};

