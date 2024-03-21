#pragma once
#include "SnakeGameEngine.h"


class SnakeScenario
{
public:
	SnakeScenario(SnakeGameEngine* engine);
	~SnakeScenario();
	//Scenario
	void snakeOrigin();
	void snakeBlockade();
	void snakeBoss();

private:
	// Principe de dependance
	SnakeGameEngine* mEngine;

};

