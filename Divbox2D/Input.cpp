#include "Utils.h"
#include "Input.h"

namespace Divbox2D {

	Input* Input::Get()
	{
		static Input input;
		return &input;
	}

	int Input::Update()
	{
		// If the key is being pressed, return the ASCII key code

		if (::GetKeyboardState(keys_state))
		{

			for (unsigned int i = 0; i < 256; i++)
			{

				if (keys_state[i] & 0x8000)
				{
					return (char)i;
				}

			}
			::memcpy(prev_keys_state, keys_state, sizeof(unsigned char) * 256);
		}

		return 0;

	}

}