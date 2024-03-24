#pragma once
#include "SnakeKeyboardController.h"

class SnakeKeyboardAbsoluteController : public SnakeKeyboardController
{
public:
	SnakeKeyboardAbsoluteController(Snake& snake, Qt::Key up, Qt::Key down, Qt::Key left, Qt::Key right);
	~SnakeKeyboardAbsoluteController();

	void control(const PressedKeys& pressedKeys) override;

private:
	Snake& mControlledSnake;
	const Qt::Key	mUp;
	Qt::Key mDown;
	Qt::Key	mLeft;
	Qt::Key	mRight;
};