#pragma once
#ifndef SNAKE_GAME_ENGINE
#define SNAKE_GAME_ENGINE
#include <QTimer>
#include <QElapsedTimer>
//#include <QSize>

#include "SnakeGameScenario.h"
//#include "SnakeScenario.h"

#include "SnakeGameScenario.h"

#include "Entity.h"
#include "Snake.h"
#include "Pellet.h"
#include "PressedKeys.h"
#include "control.h"
#include "Obstacle.h"
//Pellet
#include "AcceleratingPellet.h"
#include "GrowingPellet.h"
#include "AddObstaclePellet.h"

class QPainter;

class SnakeGameEngine
{
public:
	//
	//SnakeGameEngine(QSize const& size); 
	SnakeGameEngine();
	~SnakeGameEngine();

	void tic(qreal elapsedTime);
	void draw(QPainter& painter);
	void clearAllEntity();
	void addEntity(Entity* entity);

	void setGameMode(const int gameMode);

	// Fonction random position
	QPoint randomPosition();

	//Gestion des pellets
	void randomPellet();
	void randomGrowingPellet();
	void randomAccPellet();
	void randomObstaclePellet();
	void randomObstacle();
	void deletObstacle();
	//
	void arene();

	void addSnake(int nbSnake);
	void snakeDirection(const PressedKeys& pressedKeys);

	bool deadSnake() const;
	std::list<Snake*> getSnakes() const;

private:

	std::list<Entity*> mEntities;
	std::list<Snake*> mSnakes;
	qreal mSpeed;
	qreal mTotalElapsedTime;
	Board mBoard;
	
	PressedKeys mPressedKeys;
	int mGameMode;
	bool mDeadSnake;
};

#endif