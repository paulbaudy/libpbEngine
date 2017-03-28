#pragma once
class Component
{
private: 
	bool bEnabled;

protected:
	bool bCanTick;
	bool bCanDisplay;

public:
	Component();
	~Component();

	virtual void create();
	virtual void start();
	virtual void update();
	virtual void display();

	bool getCanTick();
	bool getCanDisplay();
};

 