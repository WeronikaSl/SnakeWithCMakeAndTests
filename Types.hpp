#pragma once
#include <array>

using Position = std::array<uint16_t, 2>;
using Length = uint16_t;
enum class Direction { UP, DOWN, LEFT, RIGHT };
using BoardComponent = uint8_t;

