#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <fstream>
#include <string>
#include <mutex>
#include <memory>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  
  std::mutex mtx;
  bool bObstacles = false;
  bool bSpeed = false;
  std::string input = "";
  
  std::ofstream highscoreFile;
  std::unique_ptr<int> currentHighscore(new int);
  *currentHighscore = 0;
  std::string line;
  
  //Read current high score
  std::unique_lock<std::mutex> lck(mtx);
  std::ifstream myfile ("Score.txt");
  if (myfile.is_open())
  {
    getline(myfile,line);
    *currentHighscore = std::stoi(line);
    myfile.close();
  }
  lck.unlock();
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  
  //Input from user to choose game mode
  std::cout<<"Choose Mode:"<<std::endl;
  std::cout<<"Speed Increase: Press 'S'"<<std::endl;
  std::cout<<"Adding Obstacles: Press 'X'"<<std::endl;
  std::cout<<"All of the above: Press 'A'"<<std::endl;
  std::cin >> input;
  
  if(input == "X")
  {
    bObstacles = true;
  }
  if(input == "S")
  {
  	bSpeed = true;
  }
  if(input == "A")
  {
  	bObstacles = true;
    bSpeed = true;
  }
  
  
  game.Run(controller, renderer, kMsPerFrame, bObstacles, bSpeed, currentHighscore);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  
  //Check if current score is higher than current highscore to store it as new high score!
  if(*currentHighscore < game.GetScore()){
    lck.lock();
    highscoreFile.open ("Score.txt");
    highscoreFile << game.GetScore();
    highscoreFile.close();
    lck.unlock();
   }
  
  return 0;
}