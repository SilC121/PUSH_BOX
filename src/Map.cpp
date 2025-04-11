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

void App::LoadLevelFromTxt(const std::string& path) {
  std::ifstream file(path);
  std::string line;
  int row = 0;

  while (std::getline(file, line)) {
    for (int col = 0; col < line.size(); ++col) {
      char ch = line[col];
      glm::vec2 pos = {col * 30.0f-240, row * 30.0f-30};
      auto floor = std::make_shared<Character>(RESOURCE_DIR"/Image/Wall/concrete_floor.png");
      floor->SetPosition(pos);
      floor->SetZIndex(0);
      Floor_all.push_back(floor);
      m_Root.AddChild(floor);
      switch (ch) {
        case '#': {
          auto wall = std::make_shared<Character>(RESOURCE_DIR"/Image/Wall/black_wall_circle.png");
          wall->SetPosition(pos);
          wall->SetZIndex(5);
          Wall_all.push_back(wall);
          m_Root.AddChild(wall);
          break;
        }
        case '$': {
          auto box = std::make_shared<Character>(RESOURCE_DIR"/Image/Box/blue_box.png");
          box->SetPosition(pos);
          m_Root.AddChild(box);
          box->SetZIndex(5);
          Box_all.push_back(box);
          break;
        }
        case '.': {
          auto goal = std::make_shared<Character>(RESOURCE_DIR"/Image/Box/blue_goal.png");
          goal->SetPosition(pos);
          m_Root.AddChild(goal);
          goal->SetZIndex(5);
          Goal_all.push_back(goal);
          break;
        }
        case '@': {
          m_people->SetPosition(pos);
          break;
        }
      }
    }
    row++;
  }
}