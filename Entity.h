#pragma once


#include <QPoint>
#include <Qpainter>




class Entity
{
protected:

	//Board& mBoard
	bool mAlive;
	double mAge;

public:

	Entity();
	virtual ~Entity();

	double age();
	void setDead();
	
	virtual bool isValid();								//query
	virtual bool isAlive();								//query
	virtual void ticPrepare(real elapsedTime);
	virtual void ticExecute();
	virtual void draw(Qpainter& painter);
	virtual bool isColliding(Qpoint const& position);	//query


private:





};

