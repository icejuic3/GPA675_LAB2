#include "FiniteStateMachine.h"
#include "HomeState.h"
#include "GamingState.h"
#include "GameOverState.h"
#include "PauseState.h"

FiniteStateMachine::FiniteStateMachine()
	:mStates{}
	,mInitialState{nullptr}
	,mCurrentState{nullptr}
{
	mStates.push_back(new HomeState());       // �tat d'accueil
	mStates.push_back(new GamingState());     // �tat de jeu
	mStates.push_back(new GameOverState());   // �tat de fin de jeu
	mStates.push_back(new PauseState());      // �tat de pause

	mInitialState = mStates[0];
	mCurrentState = mInitialState;

	if (mInitialState) {
		mInitialState->entering();
	}
}

FiniteStateMachine::~FiniteStateMachine()
{
	for (State* state : mStates) {
		delete state;	// Lib�ration de la m�moire allou�e � chaque �tat
	}
}

void FiniteStateMachine::tic(qreal elapsedTime)
{
	if (mCurrentState) {
		mCurrentState->tic(elapsedTime);
	}
}

State* FiniteStateMachine::currentState()
{
	return mCurrentState;
}

void FiniteStateMachine::changeState(State* nextState)
{
	if (mCurrentState != nextState) {

		if (mCurrentState) {
			mCurrentState->exiting();
		}

		mCurrentState = nextState;

		if (mCurrentState) {
			mCurrentState->entering();
		}
	}
}