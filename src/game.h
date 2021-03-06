#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "obstacle.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration, bool addObstacles, bool bSpeed, std::unique_ptr<int> & highscore);
  int GetScore() const;
  int GetSize() const;

 private:
  Obstacle obstacle;
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  float NumberOfObstaclesToAdd = 1;
  
  bool addObstacles{false};
  bool addSpeed{false};
  int currHighScore{0};

  void PlaceFood();
  void PlaceObstacle();
  void Update();
  bool isEmptyCell(int x, int y);
};

#endif