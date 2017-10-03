#include <iostream>

#include "Engine.h"

int main()
{
	Aiko::Engine& engine = Aiko::Engine::getInstance();
	engine.preccisTime = true;
	engine.start();
	return EXIT_SUCCESS;
}