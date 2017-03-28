#include "Component.h"

#include <iostream>

Component::Component()
{
	bEnabled = true;
	bCanTick = true;
	bCanDisplay = false;
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

void Component::update()
{

}

void Component::display()
{

}

bool Component::getCanTick()
{
	return bCanTick;
}

bool Component::getCanDisplay()
{
	return bCanDisplay;
}
