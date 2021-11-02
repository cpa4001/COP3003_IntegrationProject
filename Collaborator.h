#pragma once
#include<string>
#include<vector>
class Collaborator
{
private:
	std::string collaboratorName;
	
	std::string role;
	std::vector<int> storiesWorkingOn;
public:
	static int collaboratorID;
	Collaborator();
	Collaborator(std::string collaboratorName, std::string role);
	
};



