#pragma once
#include "SnakeGameState.h"

class PauseState : public SnakeGameState
{
public:
	PauseState();
	~PauseState() override;

	void draw(QPainter& painter) override;
	bool isValid() override;
	void entering() override;
	void exiting() override;
	void tic(qreal elapsedTime) override;
	void updateKeys(const PressedKeys& pressedKeys) override;

private:
	PressedKeys mPressedKeys;
};

