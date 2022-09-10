#include "piece.h"

Pawn::Pawn(bool white, bool active)
    : Piece(white, active)
{
    if(white)
        m_texture.loadFromFile("res/pawn.png");
    else
        m_texture.loadFromFile("res/pawn1.png");

    this->setTexture(m_texture);
}

King::King(bool white, bool active)
    : Piece(white, active)
{
    if(white)
        m_texture.loadFromFile("res/king.png");
    else
        m_texture.loadFromFile("res/king1.png");

    this->setTexture(m_texture);
}