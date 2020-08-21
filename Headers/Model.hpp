// copyright 2016
#ifndef MODEL_HPP
#define MODEL_HPP
#include <string>
#include "Display.hpp"
#include "Player.hpp"
#include "Deck.hpp"

class Model {
 public:
  Model();
  void hit(int theTurn);
  int total_cards(Player &thePlayer);
  void dealerAI();
  void Winner();
  void createPlayers(std::string *name, int count, Display &thisDisplay);
 private:
  sf::SoundBuffer buffer;
  sf::Sound sound;
  Display* theDisplay;
  std::string names_[4];
  Player players_[4];
  int playerCount_;
  Deck vModelDeck_;
};

#endif
