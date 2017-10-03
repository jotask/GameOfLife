#pragma once

#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "Definitions.h"

namespace Aiko {

	enum TYPE {
		LIFE ,
		DEAD
	};

	class Cell
	{
	public:
		Cell(unsigned int x, unsigned int y);
		~Cell();

		void render();

		TYPE& getType();
		void setType(TYPE type);

	private:
		TYPE _type;

		sf::RectangleShape rect;

	};

}