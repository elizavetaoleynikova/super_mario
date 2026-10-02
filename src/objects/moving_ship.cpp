#include "moving_ship.hpp"

using biv::MovingShip;

MovingShip::MovingShip(
    const Coord& top_left,
    const int width,
    const int height,
    const float hspeed,
    const float left_border,
    const float right_border
)
    : MovablePlatform(top_left, width, height, 0, hspeed),
    left_border(left_border),
    right_border(right_border)
{
}

void MovingShip::move_horizontally() noexcept {
    const float old_x = top_left.x;

    top_left.x += hspeed;

    if (top_left.x <= left_border) {
        top_left.x = left_border;
        hspeed = -hspeed;
    }

    if (top_left.x + width >= right_border) {
        top_left.x = right_border - width;
        hspeed = -hspeed;
    }

    last_move_offset = top_left.x - old_x;
}

float MovingShip::get_last_move_offset() const noexcept {
    return last_move_offset;
}

void MovingShip::move_vertically() noexcept {
}

void MovingShip::move_map_left() noexcept {
    top_left.x -= MapMovable::MAP_STEP;
    left_border -= MapMovable::MAP_STEP;
    right_border -= MapMovable::MAP_STEP;
}

void MovingShip::move_map_right() noexcept {
    top_left.x += MapMovable::MAP_STEP;
    left_border += MapMovable::MAP_STEP;
    right_border += MapMovable::MAP_STEP;
}