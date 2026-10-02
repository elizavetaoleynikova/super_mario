#include "jumpable_enemy.hpp"

using biv::JumpableEnemy;

JumpableEnemy::JumpableEnemy(
	const Coord& top_left,
	const int width,
	const int height
)
	: Enemy(top_left, width, height) {
	vspeed = 0;
}

void JumpableEnemy::move_horizontally() noexcept {
	if (platform != nullptr) {
		float next_x = top_left.x + hspeed;

		if (hspeed > 0 && next_x + width > platform->get_right()) {
			hspeed = -hspeed;
		}
		else if (hspeed < 0 && next_x < platform->get_left()) {
			hspeed = -hspeed;
		}
	}

	top_left.x += hspeed;
}

void JumpableEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;

		platform = obj;
	}

	if (vspeed == 0) {
		++jump_timer;

		if (jump_timer >= 30) {
			vspeed = -1;
			jump_timer = 0;
		}
	}
}