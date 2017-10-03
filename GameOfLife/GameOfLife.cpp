#include "GameOfLife.h"

#include <iostream>

namespace Aiko {

	GameOfLife::GameOfLife(GameDataRef data) : BasicState(data)
	{
		this->world = new World();
	}


	GameOfLife::~GameOfLife()
	{

	}

	void GameOfLife::init()
	{
	}

	void GameOfLife::input(sf::Event event)
	{
		if (event.type == sf::Event::KeyPressed) 
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				this->world->restart();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				this->world->togglePause();
			}
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->world->clicked(sf::Mouse::getPosition(this->_data->display));
			}
		}
	}

	void GameOfLife::update(float dt)
	{
		this->world->step();
		if (_clock.getElapsedTime().asSeconds() > SIMULATION_FRAMERATE)
		{
			this->world->step();
			//_clock.restart();
			std::cout << "step" << std::endl;
		}
	}

	void GameOfLife::render(float dt)
	{
		this->world->render();
	}

}