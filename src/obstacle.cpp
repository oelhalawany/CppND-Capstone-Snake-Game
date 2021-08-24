#include "obstacle.h"
#include <cmath>
#include <iostream>

void Obstacle::AddObstacle(float x, float y) {
  
   	  SDL_Point obstacle_obj;
      obstacle_obj.x = static_cast<int>(x);
      obstacle_obj.y = static_cast<int>(y);
  	  obstacle_objs.push_back(obstacle_obj);
}

// Inefficient method to check if cell is occupied by Obstacle.
bool Obstacle::ObstacleCell(int x, int y) {
  
  for (SDL_Point const &obstacle_obj : obstacle_objs) {
    if(obstacle_obj.x == x && obstacle_obj.y == y)
       {
         return true;
       }
     }
  return false;
}