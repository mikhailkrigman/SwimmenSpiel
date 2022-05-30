#pragma once
#include "Refreshable.h"

class NewGameMenuScene : public Refreshable {
public:
	NewGameMenuScene(RootService* _rootService);

	void refreshAfterStartNewGame() override;
	void refreshAfterCalculateScoreOfCurrentPlayer() override;
	void refreshAfterSwapOneCard() override;
	void refreshAfterSwapAllCards() override;
	void refreshAfterPass() override;
	void refreshAfterKnock() override;
	void refreshAfterCalculateEndScores(vector<Player> scoreOfPlayers) override;
	void refreshAfterOnToNextPlayer() override;
private:
	RootService* rootService;
};

