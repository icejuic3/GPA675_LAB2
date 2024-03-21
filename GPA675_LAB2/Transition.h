#pragma once

class State;

class Transition
{
public:
	Transition(State* nextState);
	virtual ~Transition() = default;

	virtual bool isTransiting() = 0;	
	State* state();						//Accesseur retourne le prochain State
	void setState(State* state);		//Mutateur

private:
	State* mNextState;					//
};