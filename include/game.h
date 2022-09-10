#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "defaults.h"
#include "board.h"
#include "piece.h"


class Game
{
public:
    Game();
    void init_piece();
    void gameloop();


private:
    sf::RenderWindow m_window;
    int m_game_width, m_game_height;
    std::vector<std::unique_ptr<Piece>> m_pieces;
    Board m_board;

private:
    void draw();
};




#endif // GAME_H