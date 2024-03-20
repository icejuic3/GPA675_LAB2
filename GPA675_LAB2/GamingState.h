#pragma once
#include "SnakeGameState.h"
#include "SnakeGameScenario.h"
#include "GameOverState.h"
#include "PauseState.h"

class GamingState : public SnakeGameState
{
public:

	GamingState();
	~GamingState();
	
	void draw(QPainter& painter) override;
	
	bool isValid() override;
	void entering()	override;
	void exiting() override;
	void tic(qreal elapsedTime) override;



	void initialiseTransition();

private:
	
	SnakeGameScenario* mScenario;
	GameOverState* mGameOver;
};