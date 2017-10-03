#pragma once

#include "Engine.h"
#include "State.h"

namespace Aiko {

	class BasicState : public State
	{
	public:
		BasicState(GameDataRef data);
		~BasicState();

		virtual void resume() override;
		virtual void pause() override;

	protected:
		GameDataRef _data;
	};

}