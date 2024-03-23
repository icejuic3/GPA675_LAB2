#include "KeyboardTransition.h"

KeyboardTransition::KeyboardTransition(State* nextState)
	:Transition(nextState)
	,mNextState{nextState}
{
}

KeyboardTransition::~KeyboardTransition()
{
}

bool KeyboardTransition::isTransiting()
{
	if (mNextState == nullptr) {
		return false;
	}

	return true;
}