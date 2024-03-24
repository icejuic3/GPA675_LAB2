#include "SnakeGameScenario.h"
#include "SnakeGameEngine.h"


SnakeGameScenario::SnakeGameScenario(SnakeGameEngine& engine)
	:mEngine(engine)
{
}

void SnakeGameScenario::resetGame()
{
}

bool SnakeGameScenario::isGameOver()
{
	return false;
}
}
