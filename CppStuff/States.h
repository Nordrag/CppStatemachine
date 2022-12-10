#pragma once
#include "Statemachine.h"
#include <iostream>
#define LOG(x) std::cout<< x << std::endl;

//header containing the classes that implement the base State class
class StateOne : public State
{
public:
	StateOne() { }
	~StateOne() { }

	void OnEnter() override
	{
		LOG("entered state one");
	}
	void OnExit() override
	{
		LOG("left state one");
	}
	void Update() override
	{
		LOG("updating state one");
	}
};


class StateTwo : public State
{
public:
	StateTwo() { }
	~StateTwo() { }

	void OnEnter()
	{
		LOG("entered state two");
	}
	void OnExit()
	{
		LOG("left state two");
	}
	void Update()
	{
		LOG("updating state two");
	}
};
