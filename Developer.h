/** @file Developer.h
 *  @brief Declaration file for Developer class
           inherits from Collaborator class
 *  @author Christian Apostoli
 *  @bug No known bugs.
 */

#pragma once
#include "Collaborator.h"
// LO2
// LO2a
// Developer inherits from Collaborator with public visibility
class Developer : public Collaborator {
 public:
  Developer(std::string name);

  void assignStory(int storyID);
};
