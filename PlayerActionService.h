#ifndef PlayerActionService_H
#define PlayerActionService_H

class RootService;
#include "RootService.h"

class PlayerActionService {
public:
	RootService* rootService;

	PlayerActionService(RootService* _rootService);

	void swapOneCard(Card& playerCard, Card& midCard);
	void swapAllCards();
	void pass();
	void knock();

	void calculateScoreOfCurrentPlayer();
	bool isGameEnded();
	void ontoNextPlayer();
};

#endif