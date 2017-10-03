#include "World.h"

#include <iostream>

namespace Aiko {

	World::World()
		: width(Aiko::Engine::getInstance().getData()->display.getSize().x / CELL_SIZE),
		height(Aiko::Engine::getInstance().getData()->display.getSize().y / CELL_SIZE),
		_paused(false)
	{

		for (unsigned int j = 0; j < height; j++) {
			for (unsigned int i = 0; i < width; i++) {
				Cell cell(i, j);

				cell.setType ( ( (rand() % 2) == 0) ? TYPE::DEAD : TYPE::LIFE);

				_cells.push_back(cell);

				int ind = getIndex(i, j);
			}
		}

		_cells.at(getIndex(5, 5)).setType(TYPE::LIFE);
		_cells.at(getIndex(5, 6)).setType(TYPE::LIFE);
		_cells.at(getIndex(5, 7)).setType(TYPE::LIFE);

	}

	World::~World()
	{
	}

	int World::getIndex(unsigned int x, unsigned int y)
	{
		return x * width + y; 
	}

	void World::step()
	{

		if (this->_paused)
			return;

		std::vector<Cell> _other(_cells);

		for (unsigned int j = 0; j < height; j++) {
			for (unsigned int i = 0; i < width; i++) {

				const int index = getIndex(j, i);
				Cell cell = _cells.at(index);
				TYPE _t = cell.getType();

				const int lifeN = getLifeNeighbours(j, i);

				if(_t == TYPE::LIFE)
				{
					if (lifeN < 2)
					{
						_other.at(index).setType(TYPE::DEAD);
					}
					else if (lifeN == 2 || lifeN == 3)
					{
						_other.at(index).setType(TYPE::LIFE);
					}
					else if (lifeN > 3)
					{
						_other.at(index).setType(TYPE::DEAD);
					}
				}
				else
				{
					if (lifeN == 3)
					{
						_other.at(index).setType(TYPE::LIFE);
					}
				}

			}
		}

		_cells.clear();
		_cells.insert(_cells.begin(), _other.begin(), _other.end());

	}

	void World::render()
	{
		for (unsigned short int i = 0; i < _cells.size(); i++)
		{
			_cells.at(i).render();
		}
	}

	void World::restart()
	{

		for (unsigned int j = 0; j < height; j++)
		{
			for (unsigned int i = 0; i < width; i++)
			{
				const unsigned int index = getIndex(j, i);
				_cells.at(index).setType(TYPE::DEAD);
			}
		}

	}

	void World::togglePause()
	{
		this->_paused = !this->_paused;
	}

	void World::clicked(sf::Vector2i pos)
	{

		if (!this->_paused)
			this->togglePause();

		sf::Vector2f p;
		p.x = pos.x / CELL_SIZE;
		p.y = pos.y / CELL_SIZE;

		const unsigned int index = getIndex(p.y, p.x);

		TYPE type = this->_cells.at(index).getType();

		if (type == TYPE::DEAD)
		{
			type = TYPE::LIFE;
		}
		else
		{
			type = TYPE::DEAD;
		}
		this->_cells.at(index).setType(type);

	}

	int World::getLifeNeighbours(const unsigned int _i, const unsigned int _j)
	{
		int number = 0;

		for (int j = _j - 1; j <= _j + 1; j++)
		{
			for(int i = _i - 1; i <= _i + 1; i++)
			{

				if (i == _i && j == _j)
					continue;
				
				const int index = getIndex(i, j);
				try {

					Cell cell = _cells.at(index);
					if (cell.getType() == TYPE::LIFE)
						number++;

				}
				catch (const std::out_of_range& oor) {
					//std::cout << index << std::endl;
				}
			}
		}

		return number;
	}

}