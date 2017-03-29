#include "Object.h"



Object::Object()
{
	bRender = true;
}

Object::Object(Scene* currentScene)
{
	bRender = true;
	sCurrentScene = currentScene;
}

Object::Object(std::string ObjectName, Scene* currentScene)
{
	bRender = true;
	sName = ObjectName;
	sCurrentScene = currentScene;
}

Object::~Object()
{
}

void Object::start()
{
	for (Component* currentComponent : vComponents) {
		currentComponent->start();
	}
	for (Object currentChild : vChilds) {
		currentChild.start();
	}
}

void Object::update(float DeltaTime)
{
	for (Component* currentComponent : vComponents) {
		if(currentComponent->getCanTick())
			currentComponent->update();
	}
	for (Object currentChild : vChilds) {
		currentChild.update(DeltaTime);
	}
}


bool Object::isChild()
{
	return bChild;
}

Component* Object::getComponent(int componentID)
{
	return mComponents[componentID];
}

void Object::setIsChild(bool child)
{
	bChild = child;
}

void Object::setParent(Object *parent)
{
	oParent = parent;
}

