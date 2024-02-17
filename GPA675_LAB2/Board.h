#pragma once
#include<iostream>

enum class State :bool {
	free = 0,
	occupied = 1,
};

using Cellstate = State;
using DataState = Cellstate*;

class Board
{
public:

	Board();
	Board(size_t height, size_t width, Cellstate initValue = State::free);	//initialise initValue avec la premiere valeur de l'enum, soit free
	Board(Board const&) = delete;			//supprime le constructeur de copie par défaut. empeche de  créer un nouvel objet Board en copiant un objet Board existant.
	Board(Board&&) = delete;				//supprime le constructeur de déplacement par défaut. Cela empêche la création d'un objet Board en déplaçant un objet Board existant.
	Board& operator=(Board const&);			//permet d'assigner les valeurs d'un objet Board à un autre objet existant en faisant une copie.
	Board& operator=(Board&&) = delete;		//Cette ligne supprime l'opérateur d'assignation de déplacement par défaut. Elle empêche l'assignation d'un objet Board à un autre en utilisant le déplacement.
	~Board();

	//Accesseurs
	size_t getWidth() const;
	size_t getHeight() const;
	size_t getSize() const;
	Cellstate value(size_t row, size_t column) const;						//accesseur retournant la valeur de la cellule sur la grille

	//Mutateurs
	void setState(size_t row, size_t column, Cellstate value);				//mutateur qui modifie la valeur de la cellule sur la grille

	//buffer
	DataState const& data() const;												// Accesseur en lecture seule sur le "buffer" de la grille.
	DataState& data();															// Accesseur en lecture/écriture sur le "buffer" de la grille.

private:

	size_t mHeight;
	size_t mWidth;
	size_t mSize;
	DataState mBoard;			//pointeur de Cellstate
};