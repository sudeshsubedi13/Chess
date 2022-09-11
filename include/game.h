#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "defaults.h"
#include "board.h"
#include "piece.h"
#include "move.h"


class Game
{
public:
    Game();
    void setup_piece();
    void gameloop();


private:
    sf::RenderWindow m_window;
    int m_game_width, m_game_height;
    std::vector<std::shared_ptr<Piece>> m_pieces;
    std::vector<Move> moves;
    Board m_board;
    int m_piece_count;

private:
    void draw();
};




#endif // GAME_H