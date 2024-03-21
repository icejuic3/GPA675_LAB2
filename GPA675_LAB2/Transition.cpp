#include "Transition.h"

Transition::Transition(State* nextState)
	:mNextState{nextState}
{
}

State* Transition::state()
{
	return mNextState;		//retourne le prochaine etat
}

void Transition::setState(State* state)
{
	mNextState = state;
}
