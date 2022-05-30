#ifndef SwimGame_CPP
#define SwimGame_CPP

#define DEBUG

#include "SwimGame.h"
#include <ctime>
#include <iostream>

using namespace std;

SwimGame::SwimGame() {
	passCounter = 0;
	players = vector<Player>(2);
	currentPlayer = &players[0];
	playerWhoKnocked = nullptr;
	
	setNewDeck();

	//showDrawPile();
	shuffle(drawPile);
}

SwimGame::SwimGame(vector<Player> _players) {
	if (players.size() >= 2 && players.size() <= 4) {
		passCounter = 0;
		players = _players;
		currentPlayer = &players[0];
		
		for (int i = 1; i < (int)players.size(); i++)
			players[i - 1].nextPlayer = &players[i];
		players[(int)players.size() - 1].nextPlayer = &players[0];

		playerWhoKnocked = nullptr;

		setNewDeck();
		shuffle(drawPile);

		for (int i = 0; i < (int)players.size(); i++) {
			for (int j = 0; j < 3; j++) {
				auto it = drawPile.end();
				it--;
				(players[i]).handCards[j] = *it;
				drawPile.pop_back();
			}
		}

	#ifdef DEBUG
		showDrawPile();
		cout << endl;

		for (int i = 0; i < (int)players.size(); i++) {
			cout << "Player [" << i << "]" << endl;
			for (int j = 0; j < 3; j++) {
				((players[i]).handCards[j]).show();
			}
			cout << endl;
		}
	#endif
	}
	else {
		throw "Unvalid number of players";
	}
}

void SwimGame::setNewDeck() {
	for (int suit = static_cast<int>(Suit::First); suit <= static_cast<int>(Suit::Last); suit++) {
		for (int value = static_cast<int>(Value::First); value <= static_cast<int>(Value::Last); value++) {
			Card newCard(static_cast<Suit>(suit), static_cast<Value>(value));
			drawPile.push_back(newCard);
		}
	}
}

void SwimGame::shuffle(list<Card>& _drawPile) {
	srand((unsigned int)time(NULL));
	for (auto it = _drawPile.begin(); it != _drawPile.end(); it++) {
		int j = rand() % _drawPile.size() - 1;
		auto it2 = _drawPile.begin();
		for (j; j >= 1; j--)
			it2++;
		Card temp = *it;
		*it = *it2;
		*it2 = temp;
	}
}

#endif