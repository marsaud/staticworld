#ifndef POSITION_H
#define POSITION_H

typedef struct Position Position;
typedef struct Position Movement;

struct Position
{
    signed int x;
    signed int y;

    Position& operator+=(Movement const& mov);

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & x & y;
    }
};

Position operator+(Position const& pos, Movement const& mov);
bool operator==(Position const& posl, Position const& posr);

#endif // POSITION_H
