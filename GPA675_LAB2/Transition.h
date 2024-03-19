#pragma once

class State;

class Transition
{
public:
	Transition();
	virtual ~Transition() = default;

	virtual bool isTransiting() = 0;	
	State* state();						//Accesseur
	void setState(State* state);		//Mutateur

private:
	State* mNextState;
};

