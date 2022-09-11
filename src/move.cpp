#include "move.h"

Move::Move(Cell *from, Cell *to, Player *player)
    : m_from(from), m_to(to), m_player(player)
{
    m_piece = from->getPiece();
    m_enemy = to->getPiece();
    m_attacked = m_enemy != nullptr;
}

void Move::finalize() {
    std::cout << "test9.7\n";
    if(m_from == nullptr)
        std::cout << "special test\n";
    m_from->setPiece(nullptr);
    m_to->setPiece(m_piece);
    m_piece.get()->setPos(m_to->getRow(), m_to->getCol());
    std::cout << "test9.8\n";
    if( m_attacked ) {
        std::cout << "test9.9\n";
        m_enemy->setActive(false);
        std::cout << "test9.99\n";
    }
}