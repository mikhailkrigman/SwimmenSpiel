#ifndef GameService_CPP
#define GameService_CPP

#include "GameService.h"

GameService::GameService(RootService* _rootService) {
	rootService = _rootService;
}

void GameService::startNewGame(vector<string> playerNames, list<Card> allCards) {
	vector<Player> newPlayers(playerNames.size());
	for (int i = 0; i < (int)playerNames.size(); i++)
		newPlayers[i] = Player(playerNames[i]);

	*(rootService->currentGame) = SwimGame(newPlayers);
}

vector<Player> GameService::calculateEndScores() {
	vector<Player> endScores(rootService->currentGame->players.size());
	for (int i = 0; i < (int)endScores.size(); i++) {
		rootService->playerActionService->calculateScoreOfCurrentPlayer();
		endScores[i] = *(rootService->currentGame->currentPlayer);
		rootService->playerActionService->ontoNextPlayer();
	}

	return endScores;
}

#endif