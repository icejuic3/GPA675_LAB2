#pragma once
#include "Transition.h"

class GameTransition: public Transition
{
public:
	GameTransition(State* sourceState, State* nextState);
	~GameTransition() override;

	// Inherited via Transition
	bool isTransiting() override;

private:
	bool mTransiting;
};