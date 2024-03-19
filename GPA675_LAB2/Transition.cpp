#include "Transition.h"

Transition::Transition()
	:mNextState{nullptr}
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
