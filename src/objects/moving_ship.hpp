#pragma once

#include "movable_platform.hpp"
#include "map_movable.hpp"

namespace biv {

    class MovingShip : public MovablePlatform, public MapMovable {
    private:
        float left_border;
        float right_border;

        float last_move_offset = 0;

    public:
        MovingShip(
            const Coord& top_left,
            const int width,
            const int height,
            const float hspeed,
            const float left_border,
            const float right_border
        );

        float get_last_move_offset() const noexcept override;

        void move_horizontally() noexcept override;
        void move_vertically() noexcept override;

        void move_map_left() noexcept override;
        void move_map_right() noexcept override;
    };

}