#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "moving_ship.hpp"

namespace biv {
	class ConsoleMovingShip
		: public MovingShip,
		public ConsoleUIObjectRectAdapter {
	public:
		ConsoleMovingShip(
			const Coord& top_left,
			const int width,
			const int height,
			const float hspeed,
			const float left_border,
			const float right_border
		);

		char get_brush() const noexcept override;
	};
}