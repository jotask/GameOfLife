#pragma once

#include "SFML/Window.hpp"

namespace Aiko
{

	class State
	{
	public:

		virtual void init() = 0;

		virtual void input( sf::Event event ) = 0;
		virtual void update(float dt) = 0;
		virtual void render( float dt ) = 0;

		virtual void resume() = 0;
		virtual void pause() = 0;

	};

}