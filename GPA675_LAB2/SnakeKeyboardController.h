#pragma once
#include"Controller.h"


class SnakeKeyboardController: public Controller
{
public:

	SnakeKeyboardController(Snake& snake);
	~SnakeKeyboardController();


	void control(const PressedKeys& pressedKeys) override;

private:

	Snake& mControlledSnake;
};