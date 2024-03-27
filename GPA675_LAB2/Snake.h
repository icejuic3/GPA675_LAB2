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
	Snake(Board& board, QPoint point);
	~Snake() override;
	bool isValid() override;									
	bool isAlive() override;																
	void ticPrepare(real elapsedTime) override;
	void ticExecute() override;
	void draw(QPainter& painter) override;							
	bool isColliding(QPoint const& position) override;			
	QString name();												
	int score();												
	size_t bodyLength();										
	QPoint headPosition();										
	Direction headDirection();									
	SpeedType speed();											
	QColor headColor();											
	QColor bodyColor();											
	Controller* controller();

	void setController(Controller& controller);		
	void updateKeys(const PressedKeys& pressedKeys);
	void setName(QString name);									
	void reset(QPoint headPosition, Direction headDirection, size_t bodyLength, SpeedType initialSpeed);
	void setColors(QColor head, QColor body);					
	void adjustScore(int score);								
	void turnRight();											
	void turnLeft();											
	void goUp();												
	void goRight();												
	void goDown();												
	void goLeft();												
	void goToward(Direction direction);							
	void grow(size_t size = 1);									
	void advance(size_t size = 1);								
	void shrink(size_t size = 1);								
	void setSpeed(SpeedType speed);								
	void increaseSpeed(SpeedType amout);						
	void decreaseSpeed(SpeedType amout);						
	void decelerate(SpeedType percentLess);						
	void accelerate(SpeedType percentMore);						
	void addFirst(QPoint pos);
	void addLast(QPoint pos);
	void removeLast();
};