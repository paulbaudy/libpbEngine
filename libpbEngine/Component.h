#pragma once


class Object;

class Component
{
private: 
	bool bEnabled;

	
protected:
	int iComponentID;

	bool bCanTick;
	bool bCanDisplay;

	Object* oOwner;
public:
	Component();
	~Component();

	virtual void create();
	virtual void start();
	virtual void update();
	virtual void display();

	void setOwner(Object* owner);
	bool getCanTick();
	bool getCanDisplay();
	int getComponentID();
};

 