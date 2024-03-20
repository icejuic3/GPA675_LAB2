#include "Transition.h"

Transition::Transition(State* sourceState, State* nextState)
	:mNextState{nextState}
{
}

State* Transition::state()
{
	return mNextState;
}

void Transition::setState(State* state)
{
	mNextState = state;
}
