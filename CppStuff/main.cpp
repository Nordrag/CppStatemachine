#pragma once
#include "Statemachine.h"
#include "States.h"


//define a convinient name for the state indexes
unsigned int STATE_ONE = 0;
unsigned int STATE_TWO = 1;

//instantiate the states & machines
StateOne stateOne;
StateTwo stateTwo;
StateMachine statemachine; //note that you can add a statemachine inside a state, to achive sub-states

//return values for the Condition definition
bool firstEntry = false;
bool secondEntry = false;

//example condition definition
bool GetFirstEntry()
{
	return firstEntry;
}

bool GetSecondEntry()
{
	return secondEntry;
}

int main()
{	

	//add states IMPORTANT, you need to add them in order according to the indexes
	//STATE_ONE = 0 therefore I need to add stateOne first
	statemachine.AddState(&stateOne);
	statemachine.AddState(&stateTwo);
	statemachine.AddTransition(STATE_ONE, STATE_TWO, &GetFirstEntry);
	statemachine.AddTransition(STATE_TWO, STATE_ONE, &GetSecondEntry);
	statemachine.SetState(STATE_ONE);

	while (true)
	{
		statemachine.Update(); //call update

		if (firstEntry) //flipping the state entry conditions
		{
			secondEntry = true;
			firstEntry = false;
		}
		firstEntry = true;
	}
}