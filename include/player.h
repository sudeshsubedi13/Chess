#ifndef PLAYER_H
#define PLAYER_H

#include "piece.h"
#include <memory>
#include <vector>
#include <string>


class Player
{
public:
    // std::string getName() { return m_name; }
    bool is_white() { return m_white; }
    std::vector<std::shared_ptr<Piece>>& getPieces() { return m_pieces; }

    // void setName(std::string name) { m_name = name; }
    void setWhite(bool white) { m_white = white; }

private:
    std::vector<std::shared_ptr<Piece>> m_pieces;
    // std::string m_name;
    bool m_white;
};




#endif // PLAYER_H