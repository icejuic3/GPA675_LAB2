#pragma once
#include "SnakeGameState.h"
#include "HomeState.h"

class GameOverState: public SnakeGameState
{
public:
	GameOverState();
	~GameOverState() override;

	void draw(QPainter& painter) override;
	bool isValid() override;
	void entering() override;
	void exiting() override;
	void tic(qreal elapsedTime) override;

};

