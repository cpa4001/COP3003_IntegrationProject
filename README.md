# COP3003_IntegrationProject
An application that offers a project management tool to create and track user stories for teams that use AGILE methodologies. A user story is a description of a feature for an application that is usually less than three sentences long. The collection of user stories for a product is called the product backlog and this can be broken down to releases, and releases can be broken down to short iterations called sprints. This project is designed to make creating, tracking, and allocating user stories to sprints simple and easy.

A basic layout for a user story looks like: <br>
As a who      (**Who** wants to accomplish something) <br>
I want a what (**What** I want to accomplish)         <br>
So that       (**Why** I want to accomplish)          <br>
 
 ## Learning Objectives
- 1. Design and implement a class. [Usage]
  - Shown in the use of multiple classes and seperating class declaration in a header file and class implementation in a cpp file
  - Comparison of OO aproach and procedural approach on top of UserStory.cpp
   
- 2. Use subclassing to design simple class hierarchies that allow code to be reused for distinct subclasses. [Usage]

- 3. Correctly reason about control flow in a program using dynamic dispatch. [Usage]


- 4. Explain the relationship between object-oriented inheritance (code-sharing and overriding) and subtyping (the idea of a subtype being usable in a context that expects the supertype). [Familiarity]

- 5. Use object-oriented encapsulation mechanisms such as interfaces and private members. [Usage]

- 6. Define and use iterators and other operations on aggregates, including operations that take functions as arguments. [Usage]
 
 ## Milestones

Milestone 1:
- Users shall be able to create user stories
- Users shall be able to look up user stories created
- System shall be able to save user stories to a csv file
- Users should be able to continuously perform the above until exiting the program

Milestone 2:
- Users shall be able to create iterations
- Users shall be able to enter Developers or Scrum Masters
- StoryIDs shall correctly reflect how many user story objects there are
- Users shall be able to see a Kanban Board (stories that are To Do, In Progress,  Done)
- Program shall have status in csv (To Do, In Progress, or Done) instead of integer
- User shall be able to get the most recent userstory


## Getting Started
``` sh
> git clone https://github.com/cpa4001/COP3003_IntegrationProject UserStoryApp
```


## Software

- Visual Studio
- C++

## Current Challenges 
- Getting overloaded operators to a non-ambiguous definition
- Creating a function that accepts a function pointer 
- Implementing the KanbanBoard feature

## Future Goals
- Create a frontend using a GUI or website

## Acknowledgments

* https://github.com/jfg357
* https://github.com/jehna/readme-best-practices/edit/master/README-default.md
* https://gist.github.com/PurpleBooth/109311bb0361f32d87a2
