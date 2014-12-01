#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "Position.h"

class Player
{
public:
    Player();
    virtual ~Player();

    enum Move
    {
        MOVE_NOT, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, MOVE_LIST_SIZE
    };

    enum Action
    {
        ACTION_NONE, ACTION_ENTER_ZONE, ACTION_LIST_SIZE
    };

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
