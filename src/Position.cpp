#include "Position.h"

Position& Position::operator+=(Movement const& mov)
{
    x += mov.x;
    y += mov.y;

    return *this;
}

Position operator+(Position const& pos, Movement const& mov)
{
    Position sum;

    sum.x = pos.x + mov.x;
    sum.y = pos.y + mov.y;

    return sum;
}

bool operator==(Position const& posl, Position const& posr)
{
    return ((posl.x == posr.x) && (posl.y == posr.y));
}
