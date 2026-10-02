#include "console_flyable_enemy.hpp"

using biv::ConsoleFlyableEnemy;


ConsoleFlyableEnemy::ConsoleFlyableEnemy(
    const Coord& top_left,
    const int width,
    const int height,
    const int map_width,
    const int map_height
)
    :
    FlyableEnemy(
        top_left,
        width,
        height,
        map_width,
        map_height
    ),
    ConsoleUIObjectRectAdapter(
        top_left,
        width,
        height
    )
{
}


char ConsoleFlyableEnemy::get_brush() const noexcept {
    return 'e';
}