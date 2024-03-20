#include "SnakeScenario.h"

SnakeScenario::SnakeScenario(SnakeGameEngine* engine)
	: mEngine(engine)
{
}

SnakeScenario::~SnakeScenario()
{
}

void SnakeScenario::snakeOrigin()
{
	mEngine->clearAllEntity();
	mEngine->addSnake();
	mEngine->arene();
	mEngine->randomPellet();
}

void SnakeScenario::snakeBlockade()
{
	
}

void SnakeScenario::snakeBoss()
{

}
