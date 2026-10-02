#pragma once

#include "jumpable_enemy.hpp"
#include "console_ui_obj_rect_adapter.hpp"

namespace biv {
    class ConsoleJumpableEnemy
        : public JumpableEnemy,
        public ConsoleUIObjectRectAdapter {
    public:
        ConsoleJumpableEnemy(
            const Coord& top_left,
            int width,
            int height
        );

        char get_brush() const noexcept override;
    };
}

