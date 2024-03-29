#pragma once
#include "SnakeGameState.h"
#include "FiniteStateMachine.h"

class PauseState : public SnakeGameState
{
public:
	PauseState(FiniteStateMachine* fsm);
	~PauseState() override;

	void draw(QPainter& painter) override;
	bool isValid() override;
	void entering() override;
	void exiting() override;
	void tic(qreal elapsedTime) override;
	void updateKeys(const PressedKeys& pressedKeys) override;

private:

	FiniteStateMachine* mFsm;
};

