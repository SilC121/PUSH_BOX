
#ifndef MAP_H
#define MAP_H

#include <string>
#include "Util/GameObject.hpp"

class map{
public:
  int Level;
  int mapcol;
  int maprow;
  int getLv();
  void Chage_To_Map(map);
  void Map_to_Vector(map);

};

#endif //MAP_H
