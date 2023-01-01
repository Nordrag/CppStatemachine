#pragma once
#include "Statemachine.h"
#include "States.h"


//define a convinient name for the state indexes
unsigned int STATE_ONE;
unsigned int STATE_TWO;

bool firstEntry = false;
bool secondEntry = false;
bool isWorking = true;

//instantiate the states & machines
StateOne stateOne;
StateTwo stateTwo;
StateMachine statemachine; //note that you can add a statemachine inside a state, to achive sub-states

//example condition definition
bool GetFirstEntry()
{
	return firstEntry;
}

bool GetSecondEntry()
{
	return secondEntry;
}

void Initialize()
{
	STATE_ONE = statemachine.AddState(&stateOne);
	STATE_TWO = statemachine.AddState(&stateTwo);
	statemachine.AddTransition(STATE_ONE, STATE_TWO, &secondEntry);
	statemachine.AddTransition(STATE_TWO, STATE_ONE, &firstEntry);
	statemachine.SetState(STATE_ONE);
}

int main()
{
	Initialize();	

	while (isWorking)
	{
		statemachine.Update();
	}
}
