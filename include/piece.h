#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Piece : public sf::Sprite
{
public:
    Piece(bool white, bool active) : m_white(white), m_active(active) {}

    bool is_white() { return m_white; }
    bool is_active() { return m_active; }
    int getRow() { return m_row; }
    int getCol() { return m_col; }

    void setWhite(bool white) { m_white = white; }
    void setActive(bool active) { m_active = active; }
    void setPos(int row, int col) { m_row = row; m_col = col; }

    bool checkFriendlyFire(Piece* other) {
        return ( other != nullptr ) && ( m_white == other->is_white() ) ;
    }

    virtual bool canMove(int row, int col, Piece* other) = 0;


protected:
    bool m_white, m_active;
    sf::Texture m_texture;
    int m_row, m_col;
};


class Pawn : public Piece
{
public:
    Pawn(bool white, bool active); 
    bool canMove(int row, int col, Piece* other); // dummcol function //TODO
};


class King : public Piece
{
public:
    King(bool white, bool active); 
    bool canMove(int row, int col, Piece* other) { return row < col; } // dummcol function //TODO
};


class Queen : public Piece
{
public:
    Queen(bool white, bool active); 
    bool canMove(int row, int col, Piece* other) { return row > col; } // dummcol function //TODO
};


class Knight : public Piece
{
public:
    Knight(bool white, bool active); 
    bool canMove(int row, int col, Piece* other) { return row > col; } // dummcol function //TODO
};


class Rook : public Piece
{
public:
    Rook(bool white, bool active); 
    bool canMove(int row, int col, Piece* other) { return row > col; } // dummcol function //TODO
};


class Bishop : public Piece
{
public:
    Bishop(bool white, bool active); 
    bool canMove(int row, int col, Piece* other) { return row > col; } // dummcol function //TODO
};


#endif // PIECE_H