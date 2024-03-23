#pragma once
#include "SnakeGameState.h"
#include "FiniteStateMachine.h"

class HomeState: public SnakeGameState
{
public:
	HomeState(FiniteStateMachine* fsm);
	~HomeState() override;

	// Inherited via SnakeGameState
	void draw(QPainter& painter) override;
	bool isValid() override;
	void entering() override;
	void exiting() override;
	void tic(qreal elapsedTime) override;

private:
	FiniteStateMachine* mFsm;
};