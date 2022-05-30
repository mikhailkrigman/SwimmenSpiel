#ifndef RootService_H
#define RootService_H

class PlayerActionService;
class GameService;

#include "SwimGame.h"
#include "PlayerActionService.h"
#include "GameService.h"

class RootService {
public:
	PlayerActionService* playerActionService;
	GameService* gameService;
	SwimGame* currentGame;

	RootService();
};

#endif