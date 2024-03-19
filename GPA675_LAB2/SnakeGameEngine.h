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
	std::list<Entity*> mEntities;
	qreal mSpeed;
	qreal mTotalElapsedTime;
	Board mBoard;
	PressedKeys mPressedKeys;
	QSize mSize;				//deplacer dans gamingState

public:
	//
	SnakeGameEngine(QSize const& size); 
	//SnakeGameEngine();
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