#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "Definitions.h"
#include "StateMachine.h"

namespace Aiko {

	struct GameData
	{
		StateMachine gsm;
		sf::RenderWindow display;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Engine
	{

	public:
		static Engine& getInstance()
		{
			static Engine    instance;
			return instance;
		}

		Engine(Engine const&) = delete;
		void operator=(Engine const&) = delete;

		void start();

		GameDataRef& getData();

		bool preccisTime = true;

	private:
		Engine() {}

		GameDataRef _data = std::make_shared<GameData>();

		const float dt = 1.0f / 60.0f;

		void run();
		void basicRun();
		sf::Clock _clock;


	};

}