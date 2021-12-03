/** @file Collaborator.h
 *  @brief Declaration file for Collaborator class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

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
  std::vector<int> developers;

 public:
  static int collaboratorID;
  Collaborator() noexcept;
  Collaborator(std::string collaboratorName, std::string role);

  virtual void assignStory(int storyID) = 0;

  auto getcollaboratorName() -> std::string;
};
#endif