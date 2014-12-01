#include "Position.h"

/*Position::Position()
{
    x = 0;
    y = 0;
}

Position::Position(signed int iX, signed int iY) :
    x(iX),
    y(iY)
{

}

Position::~Position()
{

}*/

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
