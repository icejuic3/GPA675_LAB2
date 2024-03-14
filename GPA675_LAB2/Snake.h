#pragma once

#include <QString>
#include "DynamicEntity.h"
#include "Body.h"
//#include "Controller.h"
//#include "SnakeKeyboardController.h"
//#include "SnakeKeyboardAbsoluteController.h"
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
	int mScore = 0;
	Body mBody;
	Direction mHeadDirection;
	SpeedType mSpeed;
	size_t mSizeToGrow = 0;
	QColor mHeadColor;
	QColor mBodyColor;
	bool mReverseProhibited;

	const std::array<Direction, 4> LUTTurnLeftDirection{ Direction::toLeft,Direction::toUp, Direction::toRight,Direction::toDown };
	const std::array<Direction, 4> LUTTurnRightDirection{ Direction::toRight,Direction::toDown, Direction::toLeft,Direction::toUp };
	const std::array<Direction, 4> LUTOppositeDirection{ Direction::toDown, Direction::toLeft,Direction::toUp,Direction::toRight };

	const std::array<QPoint, 4> LUTDirectionDisplacement{}; //teleport?
	const std::array<void(Snake::*)(), 4> LUTDirectionAction; //a revoir

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
	bool isReverseProhibited();									//fait
	Controller* controller();								
	void setName(QString name);									//fait
	void reset(QPoint headPosition, Direction headDirection, size_t bodyLength, SpeedType initialSpeed);	//fait
	void setColors(QColor head, QColor body);					//fait
	void prohibitedReverse(bool Prohibited);					//fait
	void adjustScore(int score);								//fait
	void turnRight();											//fait
	void turnLeft();											//fait
	void goUp();												//fait
	void goRight();												//fait
	void goDown();												//fait
	void goLeft();												//fait
	void goToward(Direction direction);							//fait
	void grow(size_t size = 1);									//fait
	void shrink(size_t size = 1);								//fait
	void setSpeed(SpeedType speed);								//fait
	void increaseSpeed(SpeedType amout);						//fait
	void decreaseSpeed(SpeedType amout);						//fait
	void decelerate(SpeedType percentLess);						//fait
	void accelerate(SpeedType percentMore);						//fait
};