#pragma once

#ifndef BOARD_H
#define BOARD_H
#include<iostream>

class Entity;

using CellType = Entity*;													// Correspond au type fondamental de chaque cellule de la grille. 
using DataType = CellType*;

class Board
{
public:

	Board();
	Board(size_t height, size_t width);	//initialise initValue avec la premiere valeur de l'enum, soit free
	Board(Board const&) = delete;			//supprime le constructeur de copie par d?faut. empeche de  cr?er un nouvel objet Board en copiant un objet Board existant.
	Board(Board&&) = delete;				//supprime le constructeur de d?placement par d?faut. Cela emp?che la cr?ation d'un objet Board en d?pla?ant un objet Board existant.
	Board& operator=(Board const&);			//permet d'assigner les valeurs d'un objet Board ? un autre objet existant en faisant une copie.
	Board& operator=(Board&&) = delete;		//Cette ligne supprime l'op?rateur d'assignation de d?placement par d?faut. Elle emp?che l'assignation d'un objet Board ? un autre en utilisant le d?placement.
	~Board();

	//Accesseurs
	size_t getWidth() const;
	size_t getHeight() const;
	size_t getSize() const;
	//Entity* value(size_t row, size_t column) const;						//accesseur retournant la valeur de la cellule sur la grille

	CellType value(int column, int row) const;

	//Mutateurs

	//Fonction de Resize??

	//buffer
	//Entity* const& data() const;												// Accesseur en lecture seule sur le "buffer" de la grille.
	//Entity* data();															// Accesseur en lecture/?criture sur le "buffer" de la grille.

private:

	size_t mHeight;
	size_t mWidth;
	size_t mSize;
	DataType mBoard;
};
#endif