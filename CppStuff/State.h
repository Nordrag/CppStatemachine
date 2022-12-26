#pragma once

//definition for a condition pointer that returns a bool and has no parameters
typedef bool(*Condition)();


//base class that acts as an interface
class State
{
public:
	State() { }
	~State() { }
	//called once when the machine sets this state to be active
	virtual void OnEnter()
	{

	}
	//called once when the machine sets this state to be inactive
	virtual void OnExit()
	{

	}
	//called every time the machine updates
	virtual void Update()
	{

	}
};