#include "StateMachine.h"

namespace Aiko {

	StateMachine::StateMachine()
	{
		this->_isAdding = false;
		this->_isReplacing = false;
		this->_isRemoving = false;
	}


	StateMachine::~StateMachine()
	{
	}

	void StateMachine::removeState()
	{
		this->_isRemoving = true;
	}

	void StateMachine::addState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		this->_newState = std::move(newState);
	}

	void StateMachine::processChanges()
	{
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();

			if (!this->_states.empty())
			{
				this->_states.top()->resume();
			}

			this->_isRemoving = false;
		}

		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->pause();
				}
			}

			this->_states.push(std::move(this->_newState));
			this->_states.top()->init();
			this->_isAdding = false;
		}
	}

	StateRef & StateMachine::getActive()
	{
		return this->_states.top();
	}

}