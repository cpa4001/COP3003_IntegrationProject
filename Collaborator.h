/** @file Collaborator.h
 *  @brief Declaration file for Collaborator class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#ifndef COLLABORATOR_H
#define COLLABORATOR_H
#include <string>
#include <vector>

/**
 * @brief any person that makes changes toward implementing a user story
 */
class Collaborator {
 private:
  std::string collaboratorName;

  std::string role;

 protected:
  /**
   * @brief the story IDs that the collaborator is working on
   */
  std::vector<int> storiesWorkingOn;

 public:
  /**
   * @brief unique ID to track developers
   */
  static int collaboratorID;
  Collaborator();
  Collaborator(std::string collaboratorName, std::string role);

  virtual void assignStory(int storyID);

  auto getcollaboratorName() -> std::string;
};
#endif