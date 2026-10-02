#include "flyable_enemy.hpp"

using biv::FlyableEnemy;


FlyableEnemy::FlyableEnemy(
    const Coord& top_left,
    const int width,
    const int height,
    const int map_width,
    const int map_height
)
    : Enemy(top_left, width, height),
    map_width(map_width),
    map_height(map_height)
{
    hspeed = 0.2;
    vspeed = 0.2;
}


void FlyableEnemy::move_horizontally() noexcept {

    float next_x = top_left.x + hspeed;

    if (hspeed > 0 && next_x + width >= map_width) {
        hspeed = -hspeed;
    }
    else if (hspeed < 0 && next_x <= 0) {
        hspeed = -hspeed;
    }

    top_left.x += hspeed;
}


void FlyableEnemy::move_vertically() noexcept {

    float next_y = top_left.y + vspeed;

    if (vspeed > 0 && next_y + height >= map_height - 3) {
        vspeed = -vspeed;
    }
    else if (vspeed < 0 && next_y <= 0) {
        vspeed = -vspeed;
    }

    top_left.y += vspeed;
}


void FlyableEnemy::process_horizontal_static_collision(Rect*) noexcept {
    hspeed = -hspeed;
}


void FlyableEnemy::process_vertical_static_collision(Rect*) noexcept {
    vspeed = -vspeed;
}