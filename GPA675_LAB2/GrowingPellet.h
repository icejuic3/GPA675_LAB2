#pragma once
#ifndef GROWING_PELLET_H
#define GROWING_PELLET_H

#include"Pellet.h"


class GrowingPellet : public Pellet
{
public:

	// Changement de couleur en rouge
	GrowingPellet(Board& board);

};

#endif //GROWING_PELLET_H