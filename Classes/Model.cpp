// copyright 2016
#include <string>
#include <iostream>
#include "Model.hpp"

Model::Model() {
  theDisplay = NULL;
  vModelDeck_.shuffle();
  if (!buffer.loadFromFile("Media/Hit.wav"))
    std::cout << "could not find Hit.wav" << std::endl;
  sound.setBuffer(buffer);
}

void Model::createPlayers(std::string *name, int count, Display &thisDisplay) {
  Card newCard;
  playerCount_ = count;
  theDisplay = &thisDisplay;

for(int j = 0; j < 2; j++)
  for (int i = 0; i < count; i++) {  // deals one card to each player
    newCard = vModelDeck_.getFront();

    if (i == 0 && j == 1) {
      int temp = total_cards(players_[i]);
      if (temp == 21) {
        newCard.faceDown = false;
      } else {
        newCard.faceDown = true;
    }
  }
    players_[i].name_ = name[i];
    players_[i].vHand_.push_back(newCard);
    vModelDeck_.deleteFront();
    players_[i].cardTotal_ = total_cards(players_[i]);
  }

  thisDisplay.setPlayersCount(players_, count);
}

void Model::hit(int theTurn) {
  // add so dealer doesnt get to play first
if (theTurn != 4) {
  // if the current player isnt bust or has 21 cannot hit
  if (players_[theTurn].cardTotal_ < 21 && players_[theTurn].cardTotal_ > -1) {
  // get the next card in the deck
  Card newCard = vModelDeck_.getFront();
  players_[theTurn].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  // set players total
  players_[theTurn].cardTotal_ = total_cards(players_[theTurn]);
  }

  // if they are bust set bool
  if (players_[theTurn].cardTotal_ > 21) {
    players_[theTurn].isBust = true;
    players_[theTurn].cardTotal_ = -1;
  }

  // update the display
  sound.play();
  theDisplay->setPlayersCount(players_, playerCount_);
  }
}

int Model::total_cards(Player &thePlayer) {
  int i = 0;
  int total = 0;
  for (i = 0; i < thePlayer.vHand_.size(); i++) {
    if (thePlayer.vHand_[i].faceDown) {
      total += 0;
    } else {
      switch (thePlayer.vHand_[i].value_) {
      case 1:
        if (total += 11 > 21)
          total += 1;
        else
          total += 11;
        break;
      case 2:
        total += 2;
        break;
      case 3:
        total += 3;
        break;
      case 4:
        total += 4;
        break;
      case 5:
        total += 5;
        break;
      case 6:
        total += 6;
        break;
      case 7:
        total += 7;
        break;
      case 8:
        total += 8;
        break;
      case 9:
        total += 9;
        break;
      case 10:
        total += 10;
        break;
      case 11:
        total += 10;
        break;
      case 12:
        total += 10;
        break;
      case 13:
        total += 10;
        break;
      }
    }
  }
  return total;
}

void Model::dealerAI() {
  players_[0].vHand_[1].faceDown = false;
  players_[0].cardTotal_ = total_cards(players_[0]);
  theDisplay->setPlayersCount(players_, playerCount_);

  while(players_[0].cardTotal_ < 17) {
    this->hit(0);
    players_[0].cardTotal_ = total_cards(players_[0]);
  }
  if (players_[0].cardTotal_ > 21) {
    players_[0].isBust = true;
    players_[0].cardTotal_ = -1;
  }
  this->Winner();
}

void Model::Winner() {
int winner, a = 0, b = 1;
std::system("clear");

while (b < playerCount_) {
  if (players_[a].cardTotal_ > players_[b].cardTotal_) {
    winner = a;
    b++;
  } else {  // (players_[a].cardTotal_ </== players_[b].cardTotal_)
    winner = b;
    a++;
    b++;
    }
  }
  players_[winner].isWinner = true;
  for (int i = 0; i < playerCount_; i++) {
    if (players_[winner].cardTotal_ == players_[i].cardTotal_) {
      players_[i].isWinner = true;
      std::cout << "Player " << i << " wins!" << std::endl;
    }
  }
  std::cout << "Please click the X on the game window to end program!" << std::endl;
  theDisplay->setPlayersCount(players_, playerCount_);
}
