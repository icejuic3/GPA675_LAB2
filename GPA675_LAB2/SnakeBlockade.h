#pragma once
#include "SnakeGameScenario.h"

class SnakeBlockade : public SnakeGameScenario
{
public:
	SnakeBlockade(SnakeGameEngine& engine);
	~SnakeBlockade() override;

	void startGame() override;

};