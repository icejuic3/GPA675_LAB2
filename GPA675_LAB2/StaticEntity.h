#pragma once
#ifndef STATIC_ENTITY_H
#define STATIC_ENTITY_H
#include "Entity.h"


class StaticEntity : public Entity
{
public:
	StaticEntity(Board& board);
	~StaticEntity();

	// Inherited via Entity
	bool isValid() override;
	bool isAlive() override; // S'assure d'etre en vie
	void ticPrepare(real elapsedTime) override;
	void ticExecute() override; // Execution d'un coupe de 
	void draw(QPainter& painter) override; //
	bool isColliding(QPoint const& position) override; // renvoie si l'objet est a cette position

	//Accesseurs
	QPoint position() const;
	QColor color() const;
	//Mutateurs
	void setPosition(QPoint position);
	void setColor(QColor color);

private:

	QPoint mPosition;
	QColor mColor;
	qreal  mRadius;
};

#endif //STATIC_ENTITY_H
