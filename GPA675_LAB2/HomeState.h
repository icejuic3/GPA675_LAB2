#pragma once
#include "SnakeGameState.h"
#include "GamingState.h"

class HomeState: public SnakeGameState
{
public:
	HomeState();
	~HomeState() override;

	// Inherited via SnakeGameState
	void draw(QPainter& painter) override;
	bool isValid() override;
	void entering() override;
	void exiting() override;
	void tic(qreal elapsedTime) override;
};