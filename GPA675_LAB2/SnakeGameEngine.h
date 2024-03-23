#pragma once
#ifndef SNAKE_GAME_ENGINE
#define SNAKE_GAME_ENGINE


#include <list>
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QSize>

#include "Entity.h"
#include "Snake.h"
#include "Pellet.h"
#include "PressedKeys.h"
#include "control.h"
#include "Obstacle.h"
#include "AcceleratingPellet.h"
#include "GrowingPellet.h"

class QPainter;

class SnakeGameEngine
{
private:
	QSize mSize;
	qreal mSpeed;
	qreal mTotalElapsedTime;
	std::list<Entity*> mEntities;
	Board mBoard;
	PressedKeys mPressedKeys;

public:
	//
	SnakeGameEngine(QSize const& size);
	~SnakeGameEngine();

	void tic(qreal elapsedTime);
	void draw(QPainter& painter);
	void clearAllEntity();
	void addEntity(Entity* entity);

	// Fonction random position
	QPoint randomPosition();

	//Gestion des pellets
	void randomPellet();
	void randomGrowingPellet();
	void randomAccPellet();
	//
	void arene();
	void addSnake(int nbSnake);
	void snakeDirection(const PressedKeys& pressedKeys);

};

#endif