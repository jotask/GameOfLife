#include "Engine.h"

#include "GameOfLife.h"

#include <iostream>

namespace Aiko {

	void Engine::start()
	{

		sf::ContextSettings setting;

		this->_data->display.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE, sf::Style::Default, setting);

		this->_data->gsm.addState(StateRef(new GameOfLife(_data)));

		if (this->preccisTime)
		{
			this->run();
		}
		else
		{
			this->basicRun();
		}

	}

	GameDataRef& Engine::getData()
	{
		return this->_data;
	}

	void Engine::basicRun()
	{
		while (this->_data->display.isOpen())
		{

			this->_data->gsm.processChanges();

			StateRef& state = this->_data->gsm.getActive();

			sf::Event event;
			while (this->_data->display.pollEvent(event)) {

				switch (event.type)
				{
				case sf::Event::Closed:
					this->_data->display.close();
					break;
				}

				state->input(event);

			}
			state->update(dt);

			this->_data->display.clear(sf::Color::Red);
			state->render(dt);
			this->_data->display.display();

		}
	}

	void Engine::run()
	{
		float newTime = 0.0f;
		float frameTime = 0.0f;
		float interpolation = 0.0f;

		float currentTime = _clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->display.isOpen())
		{

			this->_data->gsm.processChanges();

			StateRef& state = this->_data->gsm.getActive();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				sf::Event event;
				while (this->_data->display.pollEvent(event)) {

					switch (event.type)
					{
					case sf::Event::Closed :
						this->_data->display.close();
						break;
					}

					state->input(event);
					
				}
				state->update( dt );
				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			
			this->_data->display.clear(sf::Color::Red);
			state->render(interpolation);
			this->_data->display.display();

		}

	}

}