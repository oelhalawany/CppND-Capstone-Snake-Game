#include "obstacle.h"
#include <cmath>
#include <iostream>
#include <thread>
#include <chrono>

std::mutex Obstacle::_mtx;

void Obstacle::AddObstacle(float x, float y) {
  	
  	  std::unique_lock<std::mutex> lck(_mtx);
      lck.unlock();
  
  	  SDL_Point obstacle_obj;
      obstacle_obj.x = static_cast<int>(x);
      obstacle_obj.y = static_cast<int>(y);
  	  
  	  lck.lock();
      obstacle_objs.push_back(obstacle_obj);
  	  numberOfObstacles++;
  	  lck.unlock();
  
  	 if(numberOfObstacles>=10)
     {
     	RemoveObstacle();
     }
}


void Obstacle::RemoveObstacle()
{
    std::unique_lock<std::mutex> lck(_mtx);
  	obstacle_objs.erase(obstacle_objs.begin());
    numberOfObstacles--;
}

//Method to check if cell is occupied by Obstacle.
bool Obstacle::ObstacleCell(int x, int y) {
  
  for (SDL_Point const &obstacle_obj : obstacle_objs) {
    if(obstacle_obj.x == x && obstacle_obj.y == y)
       {
         return true;
       }
     }
  return false;
}