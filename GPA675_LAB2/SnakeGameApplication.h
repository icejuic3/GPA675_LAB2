#pragma once
#ifndef SNAKE_GAME_APPLICATIONn_H
#define SNAKE_GAME_APPLICATIONn_H

#include <QtWidgets/QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QPainter>
#include "FiniteStateMachine.h"
#include "PressedKeys.h"

//using PressedKeys = std::vector<Qt::Key>;


class SnakeGameApplication : public QWidget
{
	Q_OBJECT
public:
	SnakeGameApplication();
	~SnakeGameApplication() override = default;

protected:
	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;
	void paintEvent(QPaintEvent* event) override;


private slots:

	void tic();

private:

	FiniteStateMachine mFsm;
	PressedKeys mPressedKeys;
	QSize const mWindowSize;
	QTimer mTimer;
	QElapsedTimer mElapsedTimer;

};
#endif //SNAKE_GAME_APPLICATIONn_H