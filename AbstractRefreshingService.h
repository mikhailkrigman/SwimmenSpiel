#ifndef AbstractRefreshingService_H
#define AbstractRefreshingService_H

#include <vector>
#include "Refreshable.h"

using namespace std;

class AbstractRefreshingService {
public:
	vector<Refreshable> refreshables;

	AbstractRefreshingService();

	void addRefreshable(Refreshable newRefreshable);
	void onAllRefreshables(void(*Refreshable)());
};

#endif

