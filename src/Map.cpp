#include "Map.hpp"
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include"App.hpp"


int map::getLv(){
  return Level;
};

void App::LoadLevelFromTxt() {
  std::string path="/Level/Lv"+std::to_string(Lv)+".txt";;
  std::ifstream file(RESOURCE_DIR+path);
  std::string line;
  int row = 0;

  while (std::getline(file, line)) {
    for (int col = 0; col < line.size(); ++col) {
      char ch = line[col];
      glm::vec2 pos = {col * 30.0f-240, row * 30.0f-180};
      if (ch !='0'){
      auto floor = std::make_shared<Character>(RESOURCE_DIR"/Image/Wall/concrete_floor.png");
      floor->SetPosition(pos);
      floor->SetZIndex(0);
      Floor_all.push_back(floor);
      m_Root.AddChild(floor);
      switch (ch) {
        case '1': {
          auto wall = std::make_shared<Character>(RESOURCE_DIR"/Image/Wall/black_wall_circle.png");
          wall->SetPosition(pos);
          wall->SetZIndex(5);
          Wall_all.push_back(wall);
          m_Root.AddChild(wall);
          break;
        }
        case '4': {
          auto box = std::make_shared<Character>(RESOURCE_DIR"/Image/Box/blue_box.png");
          box->SetPosition(pos);
          m_Root.AddChild(box);
          box->SetZIndex(5);
          Box_all.push_back(box);
          break;
        }
        case '3': {
          auto goal = std::make_shared<Character>(RESOURCE_DIR"/Image/Box/blue_goal.png");
          goal->SetPosition(pos);
          m_Root.AddChild(goal);
          goal->SetZIndex(4);
          Goal_all.push_back(goal);
          break;
        }
        case '6': {
          m_people->SetPosition(pos);
          break;
          }
        }
      }
    }
    row++;
  }
}