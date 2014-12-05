#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::reset()
{
    m_area.clear();
    m_tile = {0,0};
    m_zone = {0,0};
}
