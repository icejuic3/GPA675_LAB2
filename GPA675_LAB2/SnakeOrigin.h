#pragma once
#include "SnakeGameScenario.h"

class SnakeOrigin: public SnakeGameScenario
{
public:
	SnakeOrigin(SnakeGameEngine& engine);
	~SnakeOrigin() override;

	void startGame() override;



};

