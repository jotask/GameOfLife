#pragma once

#include <vector>
#include <stdexcept>

#include "Cell.h"

namespace Aiko {

	class World
	{
	public:
		World();
		~World();

		int getIndex(unsigned int x, unsigned int y);

		void step();

		void render();

		void restart();
		void togglePause();

		void clicked(sf::Vector2i pos);

	private:

		const unsigned int width;
		const unsigned int height;

		bool _paused;

		std::vector<Cell> _cells;

		int getLifeNeighbours(const unsigned int i, const unsigned int j);

	};

}