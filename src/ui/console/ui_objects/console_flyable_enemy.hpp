#pragma once

#include "flyable_enemy.hpp"
#include "console_ui_obj_rect_adapter.hpp"

namespace biv {

    class ConsoleFlyableEnemy
        : public FlyableEnemy,
        public ConsoleUIObjectRectAdapter {

    public:

        ConsoleFlyableEnemy(
            const Coord& top_left,
            const int width,
            const int height,
            const int map_width,
            const int map_height
        );

        char get_brush() const noexcept override;
    };

}