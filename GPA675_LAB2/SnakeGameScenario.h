#pragma once

class SnakeGameEngine;

class SnakeGameScenario
{
public:

	SnakeGameScenario(SnakeGameEngine& engine);
	virtual ~SnakeGameScenario() = 0;

	virtual void startGame() = 0;

	void resetGame();
	bool isGameOver();

protected:
	SnakeGameEngine& mEngine;
};