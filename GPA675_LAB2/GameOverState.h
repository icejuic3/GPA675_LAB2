#pragma once
#include "SnakeGameState.h"
#include "FiniteStateMachine.h"

class GameOverState: public SnakeGameState
{
public:
	GameOverState(FiniteStateMachine* fsm);
	~GameOverState() override;

	void draw(QPainter& painter) override;
	bool isValid() override;
	void entering() override;
	void exiting() override;
	void tic(qreal elapsedTime) override;
	void updateKeys(const PressedKeys& pressedKeys) override;

private:
	FiniteStateMachine* mFsm;
	PressedKeys mPressedKeys;
};