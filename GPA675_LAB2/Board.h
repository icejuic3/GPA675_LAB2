#pragma once

#ifndef BOARD_H
#define BOARD_H
#include<iostream>

class Entity;

using CellType = Entity*;						// Correspond au type fondamental de chaque cellule de la grille. 
using DataType = CellType*;

class Board
{
public:

	Board();
	Board(size_t height, size_t width);		//initialise initValue avec la premiere valeur de l'enum, soit free
	Board(Board const&) = delete;			//supprime le constructeur de copie par defaut. empeche de  creer un nouvel objet Board en copiant un objet Board existant.
	Board(Board&&) = delete;				//supprime le constructeur de deplacement par defaut. Cela empeche la creation d'un objet Board en deplacant un objet Board existant.
	Board& operator=(Board const&);			//permet d'assigner les valeurs d'un objet Board ? un autre objet existant en faisant une copie.
	Board& operator=(Board&&) = delete;		//Cette ligne supprime l'operateur d'assignation de d?placement par defaut. Elle empeche l'assignation d'un objet Board ? un autre en utilisant le deplacement.
	~Board();

	//Accesseurs
	size_t getWidth() const;
	size_t getHeight() const;
	size_t getSize() const;

	CellType value(int column, int row) const;

	//Mutateurs
	CellType setValue(int column, int row, CellType ptr);
	void reset(int column, int row);

private:

	size_t mHeight;
	size_t mWidth;
	size_t mSize;
	DataType mBoard;
};
#endif