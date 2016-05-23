// copyright 2016
#ifndef  CONTROLLER_HPP
#define CONTROLLER_HPP
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Model.hpp"

class Controller {
 public:
  Controller();
  void passInfo(std::string *name, int playerCount, Display &thisDisplay);
  void checkEvent(sf::RenderWindow &window);

 private:
  int turn;
  int pCount;
  sf::SoundBuffer buffer;
  sf::Sound sound;
  Model theModel_;
};

#endif
