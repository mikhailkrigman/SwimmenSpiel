#ifndef GameService_h
#define GameService_h

#include "RootService.h"

class GameService {
public:
	RootService* rootService;

	GameService(RootService* _rootService);

	void startNewGame(vector<string> playerNames, list<Card> allCards);
	vector<Player> calculateEndScores();
};

#endif
