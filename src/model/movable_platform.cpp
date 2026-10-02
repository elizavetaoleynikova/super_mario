
#include "movable_platform.hpp"

using biv::MovablePlatform;

MovablePlatform::MovablePlatform(
    const Coord& top_left,
    const int width,
    const int height,
    const float vspeed,
    const float hspeed
)
    : Movable(top_left, width, height, vspeed, hspeed)
{
}