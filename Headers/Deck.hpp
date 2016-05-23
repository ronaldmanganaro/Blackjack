#ifndef DECK_HPP
#define DECK_HPP
#include "Card.hpp"
#include <vector>
#include <algorithm>
using std::vector;

class Deck
{
public:
	Deck();
	void showDeck();
	void shuffle();
	Card getFront();
	vector<Card> vDeck_;
	void deleteFront();
private:
};

#endif