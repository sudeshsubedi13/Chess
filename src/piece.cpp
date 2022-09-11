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


Queen::Queen(bool white, bool active)
    : Piece(white, active)
{
    if(white)
        m_texture.loadFromFile("res/queen.png");
    else
        m_texture.loadFromFile("res/queen1.png");

    this->setTexture(m_texture);
}


Rook::Rook(bool white, bool active)
    : Piece(white, active)
{
    if(white)
        m_texture.loadFromFile("res/rook.png");
    else
        m_texture.loadFromFile("res/rook1.png");

    this->setTexture(m_texture);
}


Knight::Knight(bool white, bool active)
    : Piece(white, active)
{
    if(white)
        m_texture.loadFromFile("res/knight.png");
    else
        m_texture.loadFromFile("res/knight1.png");

    this->setTexture(m_texture);
}

Bishop::Bishop(bool white, bool active)
    : Piece(white, active)
{
    if(white)
        m_texture.loadFromFile("res/bishop.png");
    else
        m_texture.loadFromFile("res/bishop1.png");

    this->setTexture(m_texture);
}