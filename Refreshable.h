#pragma once
#include "RootService.h"

class Refreshable{
public:
	virtual void refreshAfterStartNewGame() = 0;
	virtual void refreshAfterCalculateScoreOfCurrentPlayer() = 0;
	virtual void refreshAfterSwapOneCard() = 0;
	virtual void refreshAfterSwapAllCards() = 0;
	virtual void refreshAfterPass() = 0;
	virtual void refreshAfterKnock() = 0;
	virtual void refreshAfterCalculateEndScores(vector<Player> scoreOfPlayers) = 0;
	virtual void refreshAfterOnToNextPlayer() = 0;
};

