#ifndef PlayerActionService_CPP
#define PlayerActionService_CPP

#include "PlayerActionService.h"

PlayerActionService::PlayerActionService(RootService* _rootService) {
	rootService = _rootService;
}

void PlayerActionService::swapOneCard(Card& playerCard, Card& midCard) {
	Card temp = playerCard;
	playerCard = midCard;
	midCard = temp;
}

void PlayerActionService::swapAllCards() {
	for (int i = 0; i < 3; i++) {
		Card temp = rootService->currentGame->currentPlayer->handCards[i];
		rootService->currentGame->currentPlayer->handCards[i] = rootService->currentGame->midCards[i];
		rootService->currentGame->midCards[i] = temp;
	}
}

void PlayerActionService::pass() {
	rootService->currentGame->currentPlayer->points = 0;
	rootService->currentGame->currentPlayer = rootService->currentGame->currentPlayer->nextPlayer;
	rootService->currentGame->passCounter++;
}

void PlayerActionService::knock() {
	rootService->currentGame->currentPlayer = rootService->currentGame->currentPlayer->nextPlayer;
	rootService->currentGame->passCounter++;
}

void PlayerActionService::calculateScoreOfCurrentPlayer() {
	Player* _currentPlayer = rootService->currentGame->currentPlayer;
	double sumOfPoints = 0.0;

	if (static_cast<int>(_currentPlayer->handCards[0].suit) == static_cast<int>(_currentPlayer->handCards[1].suit)) {
		if (static_cast<int>(_currentPlayer->handCards[0].suit) == static_cast<int>(_currentPlayer->handCards[2].suit)) {
			for (int i = 0; i < 3; i++)
				sumOfPoints += _currentPlayer->handCards[i].getValue();
		}
		else {
			sumOfPoints = _currentPlayer->handCards[0].getValue() + _currentPlayer->handCards[1].getValue();
		}
	}

	else if (static_cast<int>(_currentPlayer->handCards[0].suit) == static_cast<int>(_currentPlayer->handCards[2].suit)) {
		sumOfPoints = _currentPlayer->handCards[0].getValue() + _currentPlayer->handCards[2].getValue();
	}

	else if (static_cast<int>(_currentPlayer->handCards[1].suit) == static_cast<int>(_currentPlayer->handCards[2].suit)) {
		sumOfPoints = _currentPlayer->handCards[1].getValue() + _currentPlayer->handCards[2].getValue();
	}

	else {
		sumOfPoints = _currentPlayer->handCards[0].getValue();
		for (int i = 1; i < 3; i++)
			if (_currentPlayer->handCards[i].getValue() > sumOfPoints)
				sumOfPoints = _currentPlayer->handCards[i].getValue();
	}

	_currentPlayer->points = sumOfPoints;

}

bool PlayerActionService::isGameEnded() {
	return 
		(rootService->currentGame->passCounter == rootService->currentGame->players.size() || 
			rootService->currentGame->drawPile.size() < 3);
}

void PlayerActionService::ontoNextPlayer() {
	rootService->currentGame->currentPlayer = rootService->currentGame->currentPlayer->nextPlayer;
}

#endif