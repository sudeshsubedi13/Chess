#ifndef MOVE_H
#define MOVE_H


#include "cell.h"

class Move
{
public:
    Move(Cell &from, Cell &to);
    void finalize();

private:
    Cell &m_from, &m_to;
    std::shared_ptr<Piece> m_piece;
    std::shared_ptr<Piece> m_enemy;
    bool m_attacked;
};



#endif // MOVE_H