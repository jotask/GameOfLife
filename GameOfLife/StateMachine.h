#pragma once

#include <memory>
#include <stack>

#include "State.h"

namespace Aiko {

	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:

		StateMachine();
		~StateMachine();

		void removeState();
		void addState(StateRef newState, bool isReplacing = true);

		void processChanges();

		StateRef& getActive();

	private:

		std::stack<StateRef> _states;

		StateRef _newState;

		bool _isAdding;
		bool _isReplacing;
		bool _isRemoving;

	};

}