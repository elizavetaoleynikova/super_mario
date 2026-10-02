#pragma once

#include "movable.hpp"

namespace biv {

    class MovablePlatform : public Movable {
    protected:
        MovablePlatform(
            const Coord& top_left,
            const int width,
            const int height,
            const float vspeed,
            const float hspeed
        );

    public:
        virtual ~MovablePlatform() = default;

        virtual float get_last_move_offset() const noexcept = 0;
    };

}