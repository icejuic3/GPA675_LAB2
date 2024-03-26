#pragma once
#include "SnakeGameScenario.h"

class Snakify : public SnakeGameScenario
{
public:
	Snakify(SnakeGameEngine& engine);
	~Snakify() override;

	void startGame() override;

};

