#pragma once

namespace Divbox2D {

	class Input {
	private:
		unsigned char keys_state[256] = {};
		unsigned char prev_keys_state[256] = {};

	public:
		int Update();
		static Input* Get();
	};
}