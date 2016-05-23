// copyright 2016
#include "Card.hpp"
Card::Card() {
  faceDown = false;
  value_ = -1;
  suit_ = -1;
}

Card::Card(int newSuit, int newValue)
: suit_(newSuit), value_(newValue) {
  faceDown = false;
}
