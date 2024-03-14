#pragma once
#include "SnakeKeyboardController.h"

class SnakeKeyboardAbsoluteController : public SnakeKeyboardController
{
public:
	SnakeKeyboardAbsoluteController(Snake& snake);
	~SnakeKeyboardAbsoluteController();

	void control(const PressedKeys& pressedKeys) override;

private:

	Snake& mControlledSnake;
};