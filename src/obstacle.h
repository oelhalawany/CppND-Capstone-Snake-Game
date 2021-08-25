#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <vector>
#include "SDL.h"
#include <mutex>

class Obstacle {
 public:

  Obstacle(){}//Constructor
  ~Obstacle(){}//Destructor

  bool ObstacleCell(int x, int y);
  void AddObstacle(float x, float y);
 
  std::vector<SDL_Point> obstacle_objs;
  
 private:
  static std::mutex _mtx; //Mutex to lock access to number of obstacles and vector of obstacles
  void RemoveObstacle();
  int numberOfObstacles{0};

};

#endif