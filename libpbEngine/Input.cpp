#include "Input.h"
#include <iostream>

int Input::aPressedKeys[GLFW_KEY_LAST];


Input::Input()
{
}


Input::~Input()
{
}

bool Input::isPressed(int keyId)
{
	std::cout << Input::aPressedKeys[keyId];
	return Input::aPressedKeys[keyId] == GLFW_PRESS;
}

bool Input::isReleased(int keyID)
{
	return Input::aPressedKeys[keyID] == GLFW_RELEASE;
}

bool Input::isPressing(int keyID)
{
	return Input::aPressedKeys[keyID] == GLFW_PRESS || Input::aPressedKeys[keyID] == GLFW_REPEAT;
}
