/** @file ScrumMaster.h
 *  @brief Declaration file for ScrumMaster class
           inherits from Collaborator class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#ifndef SCRUMMASTER_H
#define SCRUMMASTER_H
#include "Collaborator.h"

// LO2
// LO2a
// Scrum Master inherits from Collaborator with public visibility
class ScrumMaster : public Collaborator {
 public:
  ScrumMaster(std::string collaboratorName);

  void assignStory(int storyID) override;
};
#endif