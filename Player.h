#pragma once
#ifndef Player_H
#define Player_H

#include "Card.h"
#include <string>
#include <vector>

using namespace std;

class Player{
public:
	double points;
	string name;
	vector<Card> handCards;
	Player* nextPlayer;

	Player();
	Player(string _name);
	Player(double _points, string _name, vector<Card> _handCards);
	Player(Player const& other);
};

#endif
