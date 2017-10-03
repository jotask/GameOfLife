#include "Cell.h"

#include <iostream>

namespace Aiko {

	Cell::Cell(unsigned int x, unsigned int y) : _type( TYPE::DEAD )
	{
		rect.setPosition((float)(x * CELL_SIZE), (float)(y * CELL_SIZE));
		rect.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));

		rect.setOutlineThickness(1);
		rect.setOutlineColor(sf::Color(250, 150, 100));

	}

	Cell::~Cell()
	{
	}

	void Cell::render()
	{
		sf::RenderWindow& rw = Aiko::Engine::getInstance().getData()->display;
		if (_type == TYPE::LIFE)
		{
			rect.setFillColor(sf::Color(0, 0, 0));
		}
		else
		{
			rect.setFillColor(sf::Color(255, 255, 255));
		}
		rw.draw(this->rect);
	}

	TYPE & Cell::getType()
	{
		return this->_type;
	}

	void Cell::setType(TYPE type)
	{
		this->_type = type;
	}

}