#pragma once
#include <vector>
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QSize>
#include "Transition.h"

class State
{
public:
	State();
	virtual ~State() = default;

	Transition* isTransiting();
	virtual bool isValid() = 0;
	virtual void entering() = 0;
	virtual void exiting() = 0;
	virtual void tic(qreal elapsedTime) = 0;

protected:
	std::vector<Transition*> mTransitions;
};