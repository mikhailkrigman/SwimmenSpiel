#ifndef Card_CPP
#define Card_CPP


#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card(Suit _suit, Value _value) {
	suit = _suit;
	value = _value;
}

Card::Card() {
	suit = Suit::SPADES;
	value = Value::ACE;
}

Card::Card(Card const & other) {
	suit = other.suit;
	value = other.value;
}

Card& Card::operator=(Card const& other) {
	if (this == &other) return *this;
	suit = other.suit;
	value = other.value;
	
	return *this;
}

double Card::getValue() {
	if (value == Value::ACE) return 11.0;
	if (value >= Value::JACK) return 10.0;
	return (double)static_cast<int>(value);
}

void Card::show() {
	string suitName;
	string valueName;
	switch (suit) {
	case Suit::CLUBS:
		suitName = "Clubs";
		break;
	case Suit::SPADES:
		suitName = "Spades";
		break;
	case Suit::HEARTS:
		suitName = "Hearts";
		break;
	case Suit::DIAMONDS:
		suitName = "Diamonds";
		break;
	}

	switch (value) {
	case Value::SEVEN:
		valueName = "Seven";
		break;
	case Value::EIGHT:
		valueName = "Eight";
		break;
	case Value::NINE:
		valueName = "Nine";
		break;
	case Value::TEN:
		valueName = "Ten";
		break;
	case Value::JACK:
		valueName = "Jack";
		break;
	case Value::QUEEN:
		valueName = "Queen";
		break;
	case Value::KING:
		valueName = "King";
		break;
	case Value::ACE:
		valueName = "Ace";
		break;
	}

	cout << valueName + " of " + suitName << endl;
}

#endif