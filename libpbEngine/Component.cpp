#include "Component.h"

#include <iostream>

Component::Component()
{
	bEnabled = true;
	bCanTick = true;
	bCanDisplay = false;
	iComponentID = -1;
}


Component::~Component()
{
}

void Component::create()
{

}

void Component::start()
{

}

void Component::update(float deltaTime)
{

}

void Component::display()
{

}

void Component::setOwner(Object* owner)
{
	oOwner = owner;
}

bool Component::getCanTick()
{
	return bCanTick;
}

bool Component::getCanDisplay()
{
	return bCanDisplay;
}

int Component::getComponentID()
{
	return iComponentID;
}
