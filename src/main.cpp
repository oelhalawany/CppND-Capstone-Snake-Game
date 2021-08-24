#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  
  bool bObstacles = false;
  bool bSpeed = false;
  std::string input = "";
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  
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
  
  
  game.Run(controller, renderer, kMsPerFrame, bObstacles, bSpeed);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}