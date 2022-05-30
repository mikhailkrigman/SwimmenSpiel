#ifndef Player_CPP
#define Player_CPP

#include "Player.h"

Player::Player() {
	name = "invalid name";
	points = 0;
	handCards = vector<Card>(3);
	nextPlayer = nullptr;
}

Player::Player(string _name) {
	name = _name;
	points = 0;
	handCards = vector<Card>(3);
	nextPlayer = nullptr;
}

Player::Player(double _points, string _name, vector<Card> _handCards) {
	points = _points;
	handCards = _handCards;
	name = _name;
	nextPlayer = nullptr;
}

Player::Player(Player const& other) {
	points = other.points;
	name = other.name;
	handCards = other.handCards;
	nextPlayer = other.nextPlayer;
}

#endif