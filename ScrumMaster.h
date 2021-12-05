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
/**
 *   @brief a collaborator whose role is a Scrum Master (team lead)
 *          Scrum Master inherits from Collaborator
 */
class ScrumMaster : public Collaborator {
 private:
  /**
   * @brief the developers working under the Scrum Master
   */
  std::vector<int> developers;

 public:
  ScrumMaster(std::string collaboratorName);

  void assignStory(int storyID) override;
};
#endif