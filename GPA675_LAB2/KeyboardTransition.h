#pragma once
#include "Transition.h"
#include <QtWidgets/QWidget>
#include <QKeyEvent>

class KeyboardTransition: public Transition
{
public:
	KeyboardTransition(State* nextState);
	~KeyboardTransition();

	bool isTransiting() override;

private:

	State* mNextState;
};
