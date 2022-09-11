#include "game.h"

Game::Game() {
    setup_piece();
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


void Game::setup_piece() {
    m_piece_count = 0;
    // pawns
    for(int i=1; i<= 16; i++) {
        if(i%2 == 0) {
            m_pieces.emplace_back(new Pawn(true, true));
            m_board.getCell(6, (i-1) / 2).setPiece( m_pieces.at(m_piece_count++) );
        } else {
            m_pieces.emplace_back(new Pawn(false, true));
            m_board.getCell(1, (i-1) / 2).setPiece( m_pieces.at(m_piece_count++) );
        }
        // m_piece_count++;
    }

    // king and queens
    m_pieces.emplace_back( new King(true, true) );
    m_board.getCell(7, 4).setPiece( m_pieces.at(m_piece_count++) );
    // m_piece_count++;
    m_pieces.emplace_back( new King(false, true) );
    m_board.getCell(0, 4).setPiece( m_pieces.at(m_piece_count++) );
    m_pieces.emplace_back( new Queen(true, true) );
    m_board.getCell(7, 3).setPiece( m_pieces.at(m_piece_count++) );
    m_pieces.emplace_back( new Queen(false, true) );
    m_board.getCell(0, 3).setPiece( m_pieces.at(m_piece_count++) );


    // others
    for(int i=1; i<=4; i++) {
        if(i%2 == 0) {
            // pass the duchie 'pon the left hand side
            m_pieces.emplace_back( new Rook(true, true) );
            m_board.getCell(7, 0).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Knight(true, true) );
            m_board.getCell(7, 1).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Bishop(true, true) );
            m_board.getCell(7, 2).setPiece( m_pieces.at(m_piece_count++) );
            // right side
            m_pieces.emplace_back( new Rook(true, true) );
            m_board.getCell(7, 7).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Knight(true, true) );
            m_board.getCell(7, 6).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Bishop(true, true) );
            m_board.getCell(7, 5).setPiece( m_pieces.at(m_piece_count++) );
        } else {
            // pass the duchie 'pon the left hand side
            m_pieces.emplace_back( new Rook(false, true) );
            m_board.getCell(0, 0).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Knight(false, true) );
            m_board.getCell(0, 1).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Bishop(false, true) );
            m_board.getCell(0, 2).setPiece( m_pieces.at(m_piece_count++) );
            // right side
            m_pieces.emplace_back( new Rook(false, true) );
            m_board.getCell(0, 7).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Knight(false, true) );
            m_board.getCell(0, 6).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Bishop(false, true) );
            m_board.getCell(0, 5).setPiece( m_pieces.at(m_piece_count++) );
        }
    }
}

