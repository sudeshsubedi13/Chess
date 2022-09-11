#ifndef MOVE_H
#define MOVE_H


#include "cell.h"
#include "player.h"

class Move
{
public:
    Move(Cell *from, Cell *to, Player *player);
    void finalize();

private:
    Cell *m_from, *m_to;
    std::shared_ptr<Piece> m_piece;
    std::shared_ptr<Piece> m_enemy;
    bool m_attacked;
    Player* m_player;
};



#endif // MOVE_H