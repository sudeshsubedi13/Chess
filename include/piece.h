#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>

class Piece : public sf::Sprite
{
public:
    Piece(bool white, bool active) : m_white(white), m_active(active) {}

    bool is_white() { return m_white; }
    bool is_active() { return m_active; }

    void setWhite(bool white) { m_white = white; }
    void setActive(bool active) { m_active = active; }

    virtual bool canMove(int x, int y) = 0;


protected:
    bool m_white, m_active;
    sf::Texture m_texture;
};


class Pawn : public Piece
{
public:
    Pawn(bool white, bool active); 
    bool canMove(int x, int y) { return x > y; } // dummy function //TODO
};


class King : public Piece
{
public:
    King(bool white, bool active); 
    bool canMove(int x, int y) { return x < y; } // dummy function //TODO
};


class Queen : public Piece
{
public:
    Queen(bool white, bool active); 
    bool canMove(int x, int y) { return x > y; } // dummy function //TODO
};


class Knight : public Piece
{
public:
    Knight(bool white, bool active); 
    bool canMove(int x, int y) { return x > y; } // dummy function //TODO
};


class Rook : public Piece
{
public:
    Rook(bool white, bool active); 
    bool canMove(int x, int y) { return x > y; } // dummy function //TODO
};


class Bishop : public Piece
{
public:
    Bishop(bool white, bool active); 
    bool canMove(int x, int y) { return x > y; } // dummy function //TODO
};


#endif // PIECE_H