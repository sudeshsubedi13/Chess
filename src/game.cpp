#include "game.h"

Game::Game() {
    init_piece();
}

void Game::gameloop() {
    m_window.create(sf::VideoMode( winWidth, winHeight ), "Chess", sf::Style::Close | sf::Style::Titlebar );

    while( m_window.isOpen() )
    {
        sf::Event event;
        while( m_window.pollEvent(event) ) {
            if(event.type == sf::Event::Closed) {
                m_window.close();
            }
        }

        m_window.clear(sf::Color(150, 111, 51));

        // draw stuff
        draw();


        m_window.display();


    }
}

void Game::draw() {
    m_board.drawBoard(m_window);
}


void Game::init_piece() {
    for(int i=1; i<= 16; i++) {
        if(i%2 == 0) {
            //Pawn temp(true, true);
            m_pieces.emplace_back(new Pawn(true, true));
            // King temp_king(true, true);
            m_pieces.emplace_back(new King(true, true));
        } else {
            // Pawn temp(false, true);
            m_pieces.emplace_back(new Pawn(false, true));
            // King temp_king(false, true);
            m_pieces.emplace_back(new King(false, true));
        }

    }
}