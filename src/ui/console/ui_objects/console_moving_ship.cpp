#include "console_moving_ship.hpp"

using biv::ConsoleMovingShip;

ConsoleMovingShip::ConsoleMovingShip(
	const Coord& top_left,
	const int width,
	const int height,
	const float hspeed,
	const float left_border,
	const float right_border
)
	: Rect(top_left, width, height),
	MovingShip(
		top_left,
		width,
		height,
		hspeed,
		left_border,
		right_border
	) {
}

char ConsoleMovingShip::get_brush() const noexcept {
	return '#';
}