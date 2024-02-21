#pragma once

#include"DynamicEntity.h"
#include <QString>

enum class Direction : int {
	toUp = 0,
	toRight = 1,
	toDown = 2,
	toLeft = 3
};

using SpeedType = double;

class Controller
{
public:
	
	Controller(Snake& snake);
	virtual ~Controller();
	virtual void control();

private:

	Snake& mControlledSnake;

	class SnakeKeyboardController
	{

	};

	class SnakeKeyboardAbsoluteController
	{
		snakeKeyboardAbsoluteController();

	};

};


class Snake:DynamicEntity
{

public:

	Snake();
	Snake(Snake::DynamicEntity other);
	Snake& operator=(Snake::DynamicEntity other);
	~Snake();

	bool isValid() override;									//Query
	bool isAlive() override;									//Query
	void ticPrepare(real elapsedTime) override;					
	void ticExecute() override;					
	void draw(QPainter& painter) override;					
	bool isColliding(QPoint const& position) override;			//Query

	QString name();												//query
	int score();												//query
	size_t bodyLength();										//query
	QPoint headPosition();										//query
	Direction headDirection();									//query
	SpeedType speed();											//query
	QColor headColor();											//query
	QColor bodyColor();											//query
	bool isReverseProhibited();									//query
	Controller& controller();
	void setName(QString name);
	void reset(QPoint headPosition, Direction headDirection, size_t bodyLength, SpeedType initialSpeed);
	void setSpeed(SpeedType speed);
	void setColors(QColor head, QColor body);
	void prohibitedReverse(bool Prohibited);
	void adjustScore(int score);
	void turnRight();
	void turnLeft();
	void goUp();
	void goRight();
	void goDown();
	void goLeft();
	void goToward(Direction direction);
	void grow(size_t size = 1);
	void shrink(size_t size = 1);
	void setSpeed(SpeedType speed);
	void increaseSpeed(SpeedType amout);
	void decreaseSpeed(SpeedType amout);
	void decelerate(SpeedType percentLess);
	void accelerate(SpeedType percentMore);



private:

	QString mName;
	int mScore = 0;
	Body mBody;
	Direction mHeadDirection = Direction::toUp;
	SpeedType mSpeed;
	size_t mSizeToGrow = 0;
	QColor mHeadColor = QColor(0, 255, 0);
	QColor mBodyColor = QColor(0, 128, 0);
	Controller mController = SnakeKeyboardAbsoluteController();
	bool mReverseProhibited;

	const std::array<Direction, 4> LUTTurnLeftDirection;
	const std::array<Direction, 4> LUTTurnRightDirection;
	const std::array<Direction, 4> LUTOppositeDirection;
	const std::array<QPoint, 4> LUTDirectionDisplacement;
	const std::array<void(Snake::*)(),4> LUTDirectionAction;



};

