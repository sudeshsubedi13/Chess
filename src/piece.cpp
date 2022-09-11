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


// moves
bool Pawn::canMove(int row, int col, Piece* other = nullptr) {
    std::cout << "test6.1\n";
    if( this->checkFriendlyFire(other) ) {
        return false;
    }

    // one step only
    // TODO first time two step, en passant
    std::cout << "test6.2\n";
    // std::cout << "r, c from piece: " << m_row << ", " << m_col << " and " << row << ", " << col << '\n';
    if( (m_row-row != 1) && (row-m_row != 1) ) {
        return false;
    }

    // diagonal if enemy present
    std::cout << "test6.3\n";
    if( (m_col-col > 1) || (col-m_col) > 1 ) {
        return false;
    }
    std::cout << "test6.4\n";
    if( m_col != col ) {
        if( other == nullptr ) {
            return false;
        }
        return true;
    }

    if( other && m_white != other->is_white()) {
        return false;
    }

    // white upward move
    std::cout << "test6.5\n";
    if( m_white ) {
        std::cout << "test6.6\n";
        return m_row-row == 1;
    } else {
        std::cout << "test6.7\n";
        return row-m_row == 1; // black downward move
    }
}