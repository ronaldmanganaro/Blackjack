// copyright 2016
#include "Controller.hpp"
#include <string>

Controller::Controller() {
  turn = 1;
  pCount = 0;
  if(!buffer.loadFromFile("Media/Stay.wav"))
    std::cout << "could not find Stay.wav" << std::endl;
  sound.setBuffer(buffer);
}

void Controller::passInfo(std::string *name, int count, Display &thisDisplay) {
  pCount = count;
  theModel_.createPlayers(name, count, thisDisplay);
}

void Controller::checkEvent(sf::RenderWindow &window) {
  sf::Event newEvent;
  while (window.pollEvent(newEvent)) {
  if (newEvent.type == sf::Event::Closed)
    window.close();

  if (newEvent.type == sf::Event::MouseButtonPressed) {
    if ((sf::Mouse::getPosition(window).x > 25)
    && (sf::Mouse::getPosition(window).x < 75)
    && (sf::Mouse::getPosition(window).y > 50)
    && (sf::Mouse::getPosition(window).y < 115)) {
        theModel_.hit(turn);
    }

    if ((sf::Mouse::getPosition(window).x > 80)
    && (sf::Mouse::getPosition(window).x < 150)
    && (sf::Mouse::getPosition(window).y > 50)
    && (sf::Mouse::getPosition(window).y < 115)) {
      turn++;
      sound.play();
      if (turn == pCount) {
          theModel_.dealerAI();
        }
      }
    }
  }
}
