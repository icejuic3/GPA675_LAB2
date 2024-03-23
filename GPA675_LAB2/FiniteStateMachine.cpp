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

	mStates.push_back(new HomeState(this));       // �tat d'accueil
	mStates.push_back(new GamingState(this));     // �tat de jeu
	mStates.push_back(new GameOverState());   // �tat de fin de jeu
	mStates.push_back(new PauseState());      // �tat de pause

	mInitialState = mStates[0];

	if (mInitialState) {
		mInitialState->entering();
	}
	mCurrentState = mInitialState;
}

FiniteStateMachine::~FiniteStateMachine()
{
	for (State* state : mStates) {
		delete state;	// Lib�ration de la m�moire allou�e � chaque �tat
	}
}

void FiniteStateMachine::tic(qreal elapsedTime)
{
	//mCurrentState = mInitialState;

	mCurrentState->tic(elapsedTime);	//fait le tic pour l'etat present

	State* nextState = dynamic_cast<State*>(mCurrentState->isTransiting());
	
	if (mCurrentState != nextState && nextState!=nullptr) {	//valide si le prochain etat n'est pas semblable

		if (mCurrentState) {			//si non null
			mCurrentState->exiting();	//sortir de l'etat
		}
			mCurrentState = nextState;	//met a jour l'etat

		if (mCurrentState) {			//si non null
			mCurrentState->entering();	//rentrer dans l'etat
		}
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