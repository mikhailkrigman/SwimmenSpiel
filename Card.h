#pragma once
#ifndef Card_H
#define Card_H

#include "Suit.h"
#include "Value.h"

class Card{
public:
	Suit suit;
	Value value;

	Card();
	Card(Suit _suit, Value _value);
	Card(Card const & other);
	Card& operator=(Card const& other);

	double getValue();

	void show();
};

#endif