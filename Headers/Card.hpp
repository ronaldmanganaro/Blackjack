// copyright 2016
#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
using std::cout;
using std::endl;

class Card {
 public:
  Card();
  Card(int newSuit, int newValue);
  int value_;
  bool faceDown;
  int suit_;

 private:
};

#endif
