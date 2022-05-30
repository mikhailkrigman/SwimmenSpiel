

#include "RootService.h"


RootService::RootService() {
	currentGame = nullptr;
	*playerActionService = PlayerActionService(this);
	*gameService = GameService(this);
}