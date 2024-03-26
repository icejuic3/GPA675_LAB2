#include "Snakify.h"
#include "SnakeGameEngine.h"

Snakify::Snakify(SnakeGameEngine& engine)
	:SnakeGameScenario(engine)
{
}

Snakify::~Snakify()
{
}

void Snakify::startGame()
{
	mEngine.clearAllEntity();
	mEngine.arene();
	mEngine.addSnake(1);
	mEngine.randomGrowingPellet();
}
