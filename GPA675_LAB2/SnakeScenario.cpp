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
	mEngine->arene();
	mEngine->addSnake(1);
	
}

void SnakeScenario::snakeBlockade()
{
	mEngine->clearAllEntity();
	mEngine->arene();
	mEngine->addSnake(2);
}

void SnakeScenario::snakeBoss()
{

}
