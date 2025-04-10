#include "Map.hpp"
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int map::getLv(){
  return Level;
};
void map::Read_Map(){
    std::ifstream in;
    std::string a = "Lv";
    std::string b = std::to_string(getLv());
    std::string c = ".txt";
    in.open(a + b + c);
    std::vector<std::vector<char>>Lvmap;
    for (int i = 0; i < maprow; i++) {
      int temp;
      for (int j = 0; j < mapcol; j++) {
        in >> temp;
        Lvmap[i][j] = temp;
        if (temp == 3) {
          
      }
    }
  }
  return;}