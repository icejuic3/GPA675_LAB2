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

	const std::vector<State*>& getStates() const;

private:
	
	std::vector<State*> mStates;
	State* mInitialState;
	State* mCurrentState;
};