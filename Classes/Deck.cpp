// copyright 2016
#include "Deck.hpp"

Deck::Deck() {
  int j = 0;
  for (int i = 1; i <= 14; i++) {
    if (i == 14 && j < 3) {
      i = 1;
      j += 1;
    }
    vDeck_.push_back(Card(j, i));
  }
}

void Deck::showDeck() {
  for (int i = 1; i <= 52; i++) {
    cout << "Card " << i << ": Value: " << vDeck_[i-1].value_
        << " Suit: " << vDeck_[i-1].suit_ << endl;
  }
}

void Deck::shuffle() {
  srand(time(0));
  std::random_shuffle(vDeck_.begin(), vDeck_.end()-1);
}

Card Deck::getFront() {
  return vDeck_.front();
}

void Deck::deleteFront() {
  vDeck_.erase(vDeck_.begin());
  vDeck_.begin()++;
}
