// copyright 2016
#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Player.hpp"

class Display {
 public:
  Display();
  void drawPlayers();
  void displayHand();
  void drawUI();
  void setPlayersCount(Player *newPlayers, int count);
  std::string findValue(int value);
  sf::Text theName[4];
  int pCount;
  sf::RenderWindow window;
  Player displayPlayers[4];
 private:
  sf::Music music;

  void createWindow(Display &thisDisplay);
  void promptUser(Display &thisDisplay);
};

#endif  // DISPLAY_HPP
