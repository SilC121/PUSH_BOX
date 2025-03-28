#include "Map.hpp"
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int map::getLv(){
  return Level;
};
void map::Chage_To_Map(vmap){
    std::ifstream in;
    std::string a = "Lv";
    std::string b = std::to_string(getLv());
    std::string c = ".txt";
    in.open(a + b + c);

    for (int i = 0; i < maprow; i++) {
      int temp;
      for (int j = 0; j < mapcol; j++) {
        in >> temp;
        vmap[i][j] = temp;
        if (temp == 3) {

      }
    }
  }
  return;}