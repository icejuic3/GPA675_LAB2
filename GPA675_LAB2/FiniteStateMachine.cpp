#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine()
	:mStates{}
	,mInitialState{}
	,mCurrentState{}
{
}

FiniteStateMachine::~FiniteStateMachine()
{
}

void FiniteStateMachine::tic(qreal elapsedTime)
{
}

State* FiniteStateMachine::currentState()
{
	return mCurrentState;
}
