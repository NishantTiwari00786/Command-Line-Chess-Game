# Online Multiplayer Chess Game


## Authors: [Attila Koksal](https://github.com/attilakoksal), [Rushil Mohandas](https://github.com/RushilM), [Ray Wang](https://github.com/swang433), [Nishant Tiwari](https://github.com/NishantTiwari00786)

=====================================================================================

## PHASE I

### Project Description: 
The goal of the project is to implement a chess game that will allow users to play game against other human player. Our goal is make a game that will be implemented using Graphical interface, along with maintaning the rules and regulations. It will be 1 vs 1 game against a human opponent. User will also have option to customize their names. The user have ability to move the chess pieces as per the rules, and output will displayed on the chess board as the result.  The game will end, if king is captured either by user or by opponent. Each and every move will differ in its output, so extreme concrete outputs are essential as per the game rules. Finally, game will end, giving an option to user to play again. 

### Why is it important:

Aside from the fact that all of us find chess interesting, we also believe that a chess game would properly demonstrate our ability to manipulate inputs and outputs. It will help us to understand the technological complexity of building a physical game to digital software. Moreover, building a chess game form scratch help us to display our learning and knowledge and expose us to complexity of working on large projects in team which will be essential in future. 


### Languages/Tools/Technologies:

* [C++](https://en.wikipedia.org/wiki/C%2B%2B) - This project will be programmed primarily using C++. 

* [Visual Studio Code](https://en.wikipedia.org/wiki/Visual_Studio_Code) - This is a text and code editor that we will use to write and test code in Windows/Mac OS.

* [Git](https://en.wikipedia.org/wiki/Git) - This is a version control system that allows us to make changes to the Github project repository, through either Linux or Windows using Git bash.

* [Valgrind](https://en.wikipedia.org/wiki/Valgrind) - This is a Linux tool which detects errors and memory management bugs in C++ code. We utilize this tool to fix memory leaks in our project code.

* [Vim](https://en.wikipedia.org/wiki/Vim_(text_editor)) - This is a text editor that enables us to edit code in Linux.

* [Programming Language and Graphics](https://en.wikipedia.org/wiki/Programming_language): We plan to use C++, an object oriented language, to develop this project. We also need a chess rulebook of some form and a game engine to ensure the game is developed properly. We aim to create an app with a PVP (player vs player) game   interface. With the current time constraints, we will also try to add additional graphics or sound systems to make the game experience more engaging. 

* [CMake](https://cmake.org/): A platform that we plan to use for compiling our files, it makes compiling easier as all files can be compiled at one time. 

* [Google Test Framework](https://github.com/google/googletest): Utilizing the google test framework, to test our functions and following the google framework syntax. 

* [Unity](https://unity.com/): We plan to use unity software more making graphical interface for chess game. More features will be added if time permits. 


### What will be the input/output of our project?

Majority of inputs of the computer will involve operating the chess pieces, as given according to the algorithm. The output will be more focused on the result of those particular moves. Mainly, the input will also contain the current situation of the chess board, track of scores of both players. On the other hand, output should have the future situation after the move, keeping track of new scores and checking to see if the result of the game needed to be declared (win, loss, or draw).  Moreover, we also need to keep track of any killed pieces while playing the chess game. 


### What are the features that the project provides?

Playing chess with engaging experience will be the first utmost feature required. Players can enjoy the 2D UI chess game. An accurate chess board representation is also important. Accurate movement of chess pieces as according to physical game rules. Along with that, user interface of input/output is definitely required. If time permits, sound and visual graphics will be added and we have also incorportated the plan of deploying an Artificial Intelligence interface that will enable users to test their capabilities against computer. 

=====================================================================================

## PHASE II

### Navigation Diagram 
The Navigation diagram provides a layout of the chess game we plan to implement. It consists of multiple screens/windows that will be essential in laying the fundamentals. Such a beginning will display the "Welcome to Chess" message. Along with it, the next movement will shift towards the main menu, and that will provide the user with multiple options such as Start Game (which will prompt the user to begin the game), How to Play (paragraphic guidelines), and Settings (which gives the the user the ability to, for example, change the background color). The Start Game option will initiate the program to run, and the screen will shift from displaying a chess board and will update according to the given movements, captures, checkmates, and restrictions. Finally, the program will end, thus prompting the user to return to the main menu. Each and every screen will signify extreme details that will make gaming experience more memorable. 

![Navigation diagram - Chess project drawio-1](https://user-images.githubusercontent.com/129913303/237000256-ffd5b38c-e532-41e7-9e06-c4d78be98667.png)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

### Screens Display
Layout of each display or screens while user plays the chess game. (Screens will be updated when GUI is implied). 
![layoutproj1](https://github.com/cs100/final-project-rmoha023-ntiwa006-akoks002-swang433-1/assets/129913303/4957ff56-69d9-4e86-950f-209809bf9905)
![layoutporj2](https://github.com/cs100/final-project-rmoha023-ntiwa006-akoks002-swang433-1/assets/129913303/ef1fe7a5-cb31-408e-a652-3575b17f5384)


### Class Diagram 
The Class diagram represents the number of classes implemented in the program. This porgram consists of 5 classes: ChessSquare, ChessBoard, Color, Piece, and Controller. The Piece and Color are both objects that are contained in one ChessSquare object, meaning each Square contains one color and one piece. This Square object can be called and referenced as a pointer from other classes like ChessBoard, which consists of an array of multiple Squares; this is sometime referred to as an iterator in SOLID principles. The ChessBoard is also able to move pieces around and make then capture each other as long as they're valid according to the rules.  Moreover, since we didn't implememnt any unnecessary functions, our program and calsses fit the model of Interface Segregation Principle within the SOLID principles of OOP. 

![classdiag](![UMLDIAGRAM](https://github.com/cs100/final-project-rmoha023-ntiwa006-akoks002-swang433-1/assets/86499369/bd1c1d14-f80a-4f65-b80c-16b557daccd0)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

=====================================================================================

## PHASE III 
Feature Branches for each member ✔️
Pull request for a branch ✔️
Have issues for features and bugs ✔️
Update Kanban board ✔️
Have daily meetings to keep up with work ✔️
Update all diagrams if necessary ✔️
4

