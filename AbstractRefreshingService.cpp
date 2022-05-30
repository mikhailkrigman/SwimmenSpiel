#ifndef AbstractRefreshingService_CPP
#define AbstractRefreshingService_CPP

#include "AbstractRefreshingService.h"

AbstractRefreshingService::AbstractRefreshingService() {
	refreshables = vector<Refreshable>(0);
}

void AbstractRefreshingService::addRefreshable(Refreshable addRefreshable) {
	refreshables.push_back(addRefreshable);
}

void AbstractRefreshingService::onAllRefreshables(void(*Refreshable)()) {
	for (auto it : refreshables) {
		Refreshable();
	}
}

#endif