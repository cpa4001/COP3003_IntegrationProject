#ifndef SCRUMMASTER_H
#define SCRUMMASTER_H
#include "Collaborator.h"
class ScrumMaster : public Collaborator {
 public:
  ScrumMaster(std::string collaboratorName);

  void assignStoryToCollaborator(int collaboratorID, int storyID);
};
#endif