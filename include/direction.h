#ifndef DIRECTION_H
#define DIRECTION_H

#include <map>

enum Direction{Up, Right, Down, Left, NDirections};

const std::map<Direction, Direction> REVERSE_DIRECTION = {
    {Direction::Up, Direction::Down},
    {Direction::Right, Direction::Left},
    {Direction::Left, Direction::Right},
    {Direction::Down, Direction::Up},
};

#endif // DIRECTION_H