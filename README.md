# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Project Chosen

Extending the functionality of the snake game:
* Adding obstacles class to handle different obstacles and add difficulty to the game.
* Reading and writing from external file to store the highscore and display it at window's title as a motivation for the next player to try and get a new high score.
* Giving the player the option to choose from different modes to play at the start of the game.

## Rubices points addresses

* The project demonstrates an understanding of C++ functions and control structures.
	* obstacles.cpp line 9, 30, 38
    * game.cpp line 120
* The project reads data from a file and process the data, or the program writes data to a file.
	* main.cpp line 32, 75
* The project accepts user input and processes the input.
	* main.cpp line 50 
* The project uses Object Oriented Programming techniques.
	* obstacle.h, obstacle.cpp: class usage to create a new entity encapsulated with it's data and functionality in one class.
* Classes use appropriate access specifiers for class members.
	* obstacle.h, obstacle.cpp: choosing what variable or function members to be private to be accessed only by this class and 		what to be public to be accessed and used outside of this class by other classes.
* The project makes use of references in function declarations.
	* game.cpp line 16
    * snake.h line 12
* The project uses smart pointers instead of raw pointers.
	* main.cpp line 26
* The project uses multithreading.
	* game.cpp line 82, 105
* A mutex or lock is used in the project.
	* main.cpp line 31, 74
    * obstacle.cpp line 11,18,32


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
