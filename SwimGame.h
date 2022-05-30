#pragma once
#ifndef SwimGame_H
#define SwimGame_H

#define DEBUG

#include "Card.h"
#include "Player.h"
#include <vector>
#include <list>

class SwimGame{
public:
	int passCounter;

	Player* playerWhoKnocked; //Knock - klopfen/schlagen
	Player* currentPlayer;
	vector<Player> players;

	list<Card> drawPile;
	vector<Card> midCards;

	SwimGame();
	SwimGame(vector<Player> _players);

	#ifdef DEBUG
	void showDrawPile() {
		for (auto it = drawPile.begin(); it != drawPile.end(); it++)
			(*it).show();
	}
	#endif // DEBUG

private:
	void shuffle(list<Card>& _drawPile);
	void setNewDeck();
};

#endif
