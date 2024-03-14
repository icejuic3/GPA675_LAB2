#include "SnakeKeyboardRelativeController.h"


SnakeKeyboardRelativeController::SnakeKeyboardRelativeController(Snake& snake)
	:SnakeKeyboardController(snake)
    ,mControlledSnake{ snake }
{
}

SnakeKeyboardRelativeController::~SnakeKeyboardRelativeController()
{
}

void SnakeKeyboardRelativeController::control(const PressedKeys& pressedKeys)
{
    
    for (Qt::Key key : pressedKeys) {
        switch (key) {
        case Qt::Key_A: // Supposons que la touche 'A' fasse tourner le serpent à gauche
            mControlledSnake.turnLeft();
            break;
        case Qt::Key_D: // Supposons que la touche 'D' fasse tourner le serpent à droite
            mControlledSnake.turnRight();
            break;
        }
    }
}