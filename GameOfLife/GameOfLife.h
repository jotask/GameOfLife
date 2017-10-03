#pragma once

#include "BasicState.h"
#include "World.h"

namespace Aiko {

	class GameOfLife : public BasicState
	{
	public:
		GameOfLife(GameDataRef data);
		~GameOfLife();

		void init();

		void input(sf::Event event) override;
		void update( float dt ) override;
		void render( float dt) override;

	private:

		sf::Clock _clock;

		World* world;

	};

}