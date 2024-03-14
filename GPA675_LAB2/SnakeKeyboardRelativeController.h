#pragma once
#include "SnakeKeyboardController.h"

class SnakeKeyboardRelativeController : public SnakeKeyboardController
{
public:
	SnakeKeyboardRelativeController(Snake& snake);
	~SnakeKeyboardRelativeController();

	void control(const PressedKeys& pressedKeys) override;

private:

	Snake& mControlledSnake;
};