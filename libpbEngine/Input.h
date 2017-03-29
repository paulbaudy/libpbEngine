#pragma once
#include "glfw3.h"

class Game;

class Input
{
	friend class Game;

private :
	static int aPressedKeys[GLFW_KEY_LAST];
public:
	Input();
	~Input();

	static bool isPressed(int keyId);
	static bool isReleased(int keyID);
	static bool isPressing(int keyID);
};

