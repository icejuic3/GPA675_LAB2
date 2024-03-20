#pragma once
#include "SnakeGameState.h"
#include "HomeState.h"
#include "GamingState.h"

class PauseState : public SnakeGameState
{
public:
	PauseState();
	~PauseState() override;




	// Inherited via SnakeGameState
	void draw(QPainter& painter) override;

	bool isValid() override;

	void entering() override;

	void exiting() override;

	void tic(qreal elapsedTime) override;

};
