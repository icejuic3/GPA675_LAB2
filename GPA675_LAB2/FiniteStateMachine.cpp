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

	mStates.push_back(new HomeState(this));       // État d'accueil
	mStates.push_back(new GamingState(this));     // État de jeu
	mStates.push_back(new GameOverState(this));   // État de fin de jeu
	mStates.push_back(new PauseState());      // État de pause

	mInitialState = mStates[0];

	if (mInitialState) {
		mInitialState->entering();
	}
	mCurrentState = mInitialState;
}

FiniteStateMachine::~FiniteStateMachine()
{
	for (State* state : mStates) {
		delete state;	// Libération de la mémoire allouée à chaque état
	}
}

void FiniteStateMachine::tic(qreal elapsedTime)
{
	//mCurrentState = mInitialState;

	mCurrentState->tic(elapsedTime);	//fait le tic pour l'etat present

	State* nextState = dynamic_cast<State*>(mCurrentState->isTransiting());
	
	if (mCurrentState != nextState && nextState!=nullptr) {	//valide si le prochain etat n'est pas semblable

		mCurrentState->exiting();	//sortir de l'etat present
		mCurrentState = nextState;	//met a jour l'etat
		mCurrentState->entering();	//rentrer dans le prochain etat
	}
}

State* FiniteStateMachine::currentState()
{
	return mCurrentState;
}

State* FiniteStateMachine::getState(StateType stateType)
{
	if (static_cast<size_t>(stateType) < mStates.size()) {
		return mStates[static_cast<size_t>(stateType)];
	}
	return nullptr;											
}

const int FiniteStateMachine::getGameChoice()
{
	return mGameChoice;
}

void FiniteStateMachine::setGameChoice(const int choice)
{
	mGameChoice = choice;
}
