#include "SnakeKeyboardAbsoluteController.h"

SnakeKeyboardAbsoluteController::SnakeKeyboardAbsoluteController(Snake& snake, Qt::Key up, Qt::Key down, Qt::Key left, Qt::Key right)
	:SnakeKeyboardController(snake)
    ,mControlledSnake{ snake }
    ,mUp{up}
    ,mDown{down}
    ,mLeft{left}
    ,mRight{right}
{
}

SnakeKeyboardAbsoluteController::~SnakeKeyboardAbsoluteController()
{
}

void SnakeKeyboardAbsoluteController::control(const PressedKeys& pressedKeys)
{
    for (Qt::Key key : pressedKeys) {


        if (key == mUp) {

            mControlledSnake.goUp();
        }
        else if (key == mDown) {
            mControlledSnake.goDown();
        }
        else if (key == mLeft) {
            mControlledSnake.goLeft();
        }
        else if (key == mRight) {
            mControlledSnake.goRight();
        }
    }
}