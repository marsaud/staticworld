#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "Position.h"

class Player
{
public:
    Player();
    virtual ~Player();

    Position m_tile;
    Position m_zone;
    std::string m_area;

    void reset();

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_tile & m_zone & m_area;
    }

protected:
private:
};

#endif // PLAYER_H
