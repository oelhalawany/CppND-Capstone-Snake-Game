#include "game.h"
#include <iostream>
#include <thread>
#include "SDL.h"
#include "obstacle.h"
#include <future> 

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height, obstacle),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration, bool bObstacles, bool bSpeed, std::unique_ptr<int> & highscore) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  addObstacles = bObstacles;
  addSpeed = bSpeed;
  currHighScore = *highscore;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, obstacle);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count, currHighScore);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (isEmptyCell(x,y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::PlaceObstacle() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (isEmptyCell(x,y)) {
      std::thread t1 = std::thread(&Obstacle::AddObstacle, &obstacle, x,y);
      t1.join();
      return; 
    }   
  }
}


void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    if(addObstacles){
      for(int i = 0; i< (int)NumberOfObstaclesToAdd ; i++)
      {
        std::async(std::launch::async, &Game::PlaceObstacle, this);
      }
      if(NumberOfObstaclesToAdd<5){
         NumberOfObstaclesToAdd += 0.25;
      }
    }
    if(addSpeed)
    {
        snake.speed += 0.01;
    }
    // Grow snake and increase speed.
    snake.GrowBody();
  }
}

bool Game::isEmptyCell(int x, int y)
{
	if (!snake.SnakeCell(x, y) && !obstacle.ObstacleCell(x,y))
    {
    	return true;
    }
  return false;
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }