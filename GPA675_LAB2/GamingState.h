#pragma once
#include "SnakeGameState.h"
#include "FiniteStateMachine.h"
#include "SnakeScenario.h"
#include "SnakeGameScenario.h"

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
	void updateKeys(const PressedKeys& pressedKeys) override;

private:
	FiniteStateMachine* mFsm;
	SnakeGameScenario* mScenario;
	PressedKeys mPressedKeys;
	//GameOverState* mGameOver;
	//PauseState* mPause;
};