#include "SnakeGameState.h"

SnakeGameState::SnakeGameState()
	:mSnakeEngine{*(new SnakeGameEngine())}
	,mPressedKeys{}
{
}
