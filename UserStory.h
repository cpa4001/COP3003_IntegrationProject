/** @file UserStory.h
*   @brief: Declaration file for UserStory class
*	
*	Declaration of Userstory Class and blueprint for
*	user stories in file
* 
*	@author Christian Apostoli
*	@bug No known bugs
*/

#ifndef USERSTORY_H
#define USERSTORY_H
#include <string>
// friend class Collaborator;
class UserStory {
 private:
  std::string storyName;
  std::string storyBody;
  int storyPoints;

  enum Status { to_do, in_progress, done };

  Status status;

 public:
  // Id used to track stories
  static int storyID;

  // constructors
  UserStory();
  UserStory(std::string storyName, std::string storyBody, int storyPoints);
  // UserStory(UserStory& userstory);

  // accessors
  // getters
  std::string getStoryName();
  std::string getStoryBody();
  int getStoryPoints();
  int getStatus();
  std::string getStatusString();

  // setters
  void setStoryName(std::string value);
  void setStoryBody(std::string value);
  void setStoryPoints(int value);

  void completeUserStory();
};
#endif