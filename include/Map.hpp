
#ifndef MAP_H
#define MAP_H

#include <string>
#include "Util/GameObject.hpp"

class map{
public:
  int Level;
  int mapcol=20;
  int maprow=20;
  int getLv();
  void Draw_Map();
  void Read_Map();
  void Map_to_Vector(map);
};

#endif //MAP_H
