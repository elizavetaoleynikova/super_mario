#pragma once

#include "enemy.hpp"

namespace biv {

    class FlyableEnemy : public Enemy {
    private:
        int map_width;
        int map_height;

    public:
        FlyableEnemy(
            const Coord& top_left,
            const int width,
            const int height,
            const int map_width,
            const int map_height
        );

        void move_horizontally() noexcept override;
        void move_vertically() noexcept override;

        void process_horizontal_static_collision(Rect*) noexcept override;
        void process_vertical_static_collision(Rect*) noexcept override;
    };

}