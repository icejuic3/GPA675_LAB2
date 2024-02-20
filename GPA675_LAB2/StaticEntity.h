#pragma once
#include "Entity.h"


class StaticEntity:Entity
{
public:


	// Inherited via Entity
	bool isValid() override;
	bool isAlive() override;
	void ticPrepare(real elapsedTime) override;
	void ticExecute() override;
	void draw(QPainter& painter) override;
	bool isColliding(QPoint const& position) override;


private:
	//Point

};

