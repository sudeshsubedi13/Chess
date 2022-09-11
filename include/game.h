#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>



#include "defaults.h"
#include "board.h"
#include "piece.h"
#include "move.h"
#include "player.h"


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
    std::vector<std::shared_ptr<Move>> m_moves;
    Board m_board;
    int m_piece_count;
    Player player1, player2;
    Player* active_player;
    Cell* active_cell;
    Cell* dest_cell;

    enum m_states { waiting, about_to_move, move };
    m_states m_current_state;

private:
    void draw();
    Cell* get_cell_under_mouse();
};




#endif // GAME_H