#include "move.h"

Move::Move(Cell &from, Cell &to)
    : m_from(from), m_to(to)
{
    m_piece = from.getPiece();
    m_enemy = to.getPiece();
    m_attacked = m_enemy != nullptr;
}

void Move::finalize() {
    m_from.setPiece(nullptr);
    m_to.setPiece(m_piece);
}