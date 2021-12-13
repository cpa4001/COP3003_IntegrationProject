/** @file UserStory.h
 *   @brief Declaration file for UserStory class
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

// LO1a

/**
 * @brief a feature that is desired to be implemented by team
 */
class UserStory {
 private:
  std::string storyName;
  std::string storyBody;
  int storyPoints;

  /**
   * @brief The status of the
   */
  enum Status { to_do, in_progress, done };

  Status status;

 public:
  /**
   * @brief unique ID to track user stories
   */
  static int storyID;

  // constructors
  UserStory(std::string storyName, std::string storyBody, int storyPoints);
  // UserStory(UserStory& userstory);

  // accessors
  // getters
  auto getStoryName() -> std::string;
  auto getStoryBody() -> std::string;
  auto getStoryPoints() const noexcept -> int;
  auto getStatus() noexcept -> int;
  auto getStatusString() -> std::string;

  // setters
  void setStoryName(std::string value);
  void setStoryBody(std::string value);
  void setStoryPoints(int value) noexcept;

  void completeUserStory() noexcept;
};
#endif