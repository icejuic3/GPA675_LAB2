#pragma once
#include "SnakeGameState.h"
#include "SnakeGameScenario.h"
#include "GameOverState.h"
#include "PauseState.h"

class GamingState : public SnakeGameState
{
public:
	GamingState(FiniteStateMachine* fsm);
	~GamingState() override;
	
	void draw(QPainter& painter) override;
	
	bool isValid() override;
	void entering()	override;
	void exiting() override;
	void tic(qreal elapsedTime) override;

private:
	FiniteStateMachine* mFsm;
	SnakeGameScenario* mScenario;
	//GameOverState* mGameOver;
	//PauseState* mPause;
};