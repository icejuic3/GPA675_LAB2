#pragma once

#include <QString>
#include "DynamicEntity.h"
#include "Body.h"
#include "PressedKeys.h"

class Controller;

using SpeedType = double;

enum class Direction : int {
	toUp = 0,
	toRight = 1,
	toDown = 2,
	toLeft = 3
};

class Snake : public DynamicEntity
{
private:

	Controller* mController;
	QString mName;
	int mScore;
	Body mBody;
	Direction mHeadDirection;
	SpeedType mSpeed;
	size_t mSizeToGrow;
	QColor mHeadColor;
	QColor mBodyColor;
	bool mReverseProhibited;
	qreal mTicTime;
	size_t mBodylength;
	bool mAlive;

	const std::array<Direction, 4> LUTTurnLeftDirection;
	const std::array<Direction, 4> LUTTurnRightDirection;
	const std::array<Direction, 4> LUTOppositeDirection;

	const std::array<QPoint, 4> LUTDirectionDisplacement{}; 
	const std::array<void(Snake::*)(), 4> LUTDirectionAction; 

	PressedKeys mPressedKeys;

public:
	Snake(Board& board);
	//Snake(Snake::DynamicEntity other);			//Bonus
	//Snake& operator=(Snake::DynamicEntity other);	//Bonus
	~Snake() override;
	bool isValid() override;									//a terminer
	bool isAlive() override;									//a terminer							
	void ticPrepare(real elapsedTime) override;
	void ticExecute() override;
	void draw(QPainter& painter) override;						//a verifier	
	bool isColliding(QPoint const& position) override;			//fait		
	QString name();												//fait
	int score();												//fait
	size_t bodyLength();										//fait
	QPoint headPosition();										//fait
	Direction headDirection();									//fait
	SpeedType speed();											//fait
	QColor headColor();											//fait
	QColor bodyColor();											//fait
	//bool isReverseProhibited();									//fait
	Controller* controller();								
	void updateKeys(const PressedKeys& pressedKeys);
	void setName(QString name);									//fait
	void reset(QPoint headPosition, Direction headDirection, size_t bodyLength, SpeedType initialSpeed);	//fait
	void setColors(QColor head, QColor body);					//fait
	//void prohibitedReverse();									//fait
	void adjustScore(int score);								//fait
	void turnRight();											//fait
	void turnLeft();											//fait
	void goUp();												//fait
	void goRight();												//fait
	void goDown();												//fait
	void goLeft();												//fait
	void goToward(Direction direction);							//fait
	void grow(size_t size = 1);									//fait
	void advance(size_t size = 1);								//fait
	void shrink(size_t size = 1);								//fait
	void setSpeed(SpeedType speed);								//fait
	void increaseSpeed(SpeedType amout);						//fait
	void decreaseSpeed(SpeedType amout);						//fait
	void decelerate(SpeedType percentLess);						//fait
	void accelerate(SpeedType percentMore);						//fait
	void addFirst(QPoint pos);
	void addLast(QPoint pos);
	void removeLast();
};