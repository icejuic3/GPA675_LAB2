#pragma once
#include "State.h"


class FiniteStateMachine
{
public:
	FiniteStateMachine();
	~FiniteStateMachine();

	void tic(qreal elapsedTime);
	State* currentState();
	void changeState(State* nextState);


private:
	
	std::vector<State*> mStates;
	State* mInitialState;
	State* mCurrentState;
};