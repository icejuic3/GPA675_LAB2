#include "SnakeBlockade.h"
#include "SnakeGameEngine.h"

SnakeBlockade::SnakeBlockade(SnakeGameEngine& engine)
	:SnakeGameScenario(engine)
{
}

SnakeBlockade::~SnakeBlockade()
{
}

void SnakeBlockade::startGame()
{
	mEngine.clearAllEntity();
	mEngine.arene();
	mEngine.addSnake(2);
	mEngine.randomGrowingPellet();
}
