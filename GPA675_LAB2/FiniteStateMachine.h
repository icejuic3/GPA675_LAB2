#pragma once
#include "State.h"

enum class StateType :size_t {
	Home = 0,
	GameOver = 1,
	Pause = 2,
	Gaming = 3,
};

class FiniteStateMachine
{
public:
	FiniteStateMachine();
	~FiniteStateMachine();

	void tic(qreal elapsedTime);
	State* currentState();
	State* getState(StateType stateType);

	const int getGameChoice();
	void setGameChoice(const int choice);
	void resetGame();


private:
	std::vector<State*> mStates;
	State* mInitialState;
	State* mCurrentState;
	int mGameChoice;
};