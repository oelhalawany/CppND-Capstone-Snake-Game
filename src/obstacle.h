#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <vector>
#include "SDL.h"

class Obstacle {
 public:

  Obstacle(){}
  
  Obstacle(int pos_x, int pos_y)
      : obstacle_x(pos_x),
        obstacle_y(pos_y) {}

  bool ObstacleCell(int x, int y);
  void AddObstacle(float x, float y);
  
  std::vector<SDL_Point> obstacle_objs;

 private:
 
    float obstacle_x;
    float obstacle_y;

};

#endif