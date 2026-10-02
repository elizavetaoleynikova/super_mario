#pragma once

#include "enemy.hpp"

namespace biv {
	class JumpableEnemy : public Enemy {
	private:
		int jump_timer = 0;
		Rect* platform = nullptr;

	public:
		JumpableEnemy(
			const Coord& top_left,
			const int width,
			const int height
		);

		void move_horizontally() noexcept override;
		void process_vertical_static_collision(Rect*) noexcept override;
	};
}