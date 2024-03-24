#include "SnakeOrigin.h"
#include "SnakeGameEngine.h"

SnakeOrigin::SnakeOrigin(SnakeGameEngine& engine)
	:SnakeGameScenario(engine)
{
}

SnakeOrigin::~SnakeOrigin()
{
}

void SnakeOrigin::startGame()
{
	mEngine.clearAllEntity();
	mEngine.arene();
	mEngine.addSnake(1);
	mEngine.randomGrowingPellet();
}
