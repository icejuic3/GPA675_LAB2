#include "SnakeGameState.h"

SnakeGameState::SnakeGameState()
	:mSnakeEngine{*(new SnakeGameEngine())}
	,mPressedKeys{}
{
}

SnakeGameEngine& SnakeGameState::getEngine() const
{
	return mSnakeEngine;
}
