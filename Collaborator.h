#ifndef COLLABORATOR_H
#define COLLABORATOR_H
#include <string>
#include <vector>
class Collaborator {
 private:
  std::string collaboratorName;

  std::string role;

 protected:
  std::vector<int> storiesWorkingOn;

 public:
  static int collaboratorID;
  Collaborator();
  Collaborator(std::string collaboratorName, std::string role);

  virtual void assignStory(int storyID) = 0;

  std::string getcollaboratorName();
};
#endif