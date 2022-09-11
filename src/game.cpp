#include "game.h"

Game::Game() {
    player1.setWhite(true);
    player2.setWhite(false);
    active_player = &player1;
    active_cell = nullptr;
    dest_cell = nullptr;
    m_current_state = m_states::waiting;
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

            if(event.type == sf::Event::MouseButtonReleased) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    switch (m_current_state)
                    {
                    case m_states::waiting:
                        std::cout << "test1\n";
                        active_cell = get_cell_under_mouse();
                        std::cout << "test2\n";
                        if( active_cell != nullptr && active_cell->getPiece() != nullptr ) {
                            std::cout << "test3\n";
                            if(active_cell->getPiece().get()->is_white() == active_player->is_white()) {
                                std::cout << "test4\n";
                                active_cell->setFillColor(sf::Color::Cyan); // test purposes
                                m_current_state = m_states::about_to_move;
                            }
                        }
                        break;
                    case m_states::about_to_move:
                        std::cout << "test5\n";
                        dest_cell = get_cell_under_mouse();
                        if (dest_cell == nullptr)
                            break;
                        if( (active_cell->getCol() == dest_cell->getCol()) && (active_cell->getRow() == dest_cell->getRow()) ) {
                            std::cout << "test6\n";
                            dest_cell = nullptr;
                            active_cell->setFillColor(active_cell->getBaseColor());
                            active_cell = nullptr;
                            m_current_state = m_states::waiting;
                        } else if( active_cell->getPiece().get()->canMove(dest_cell->getRow(), dest_cell->getCol(), dest_cell->getPiece().get()) ) {
                            std::cout << "test7\n";
                            m_current_state = m_states::move;
                        } else {
                            std::cout << "test8\n";
                            dest_cell = nullptr;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        if(m_current_state == m_states::move) {
            std::cout << "test9\n";
            m_moves.emplace_back(new Move(active_cell, dest_cell, active_player));
            std::cout << "test9.5\n";
            auto temp = m_moves.back().get(); // ->finalize();
            std::cout << "test9.6\n";
            temp->finalize();
            std::cout << "test10\n";
            active_player = (active_player == &player1)? &player2 : &player1;
            active_cell->setFillColor(active_cell->getBaseColor());
            active_cell = nullptr;
            dest_cell = nullptr;
            m_current_state = m_states::waiting;
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
            m_pieces.back().get()->setPos(6, (i-1) / 2);
            player1.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(6, (i-1) / 2).setPiece( m_pieces.at(m_piece_count++) );
        } else {
            m_pieces.emplace_back(new Pawn(false, true));
            m_pieces.back().get()->setPos(1, (i-1) / 2);
            player2.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(1, (i-1) / 2).setPiece( m_pieces.at(m_piece_count++) );
        }
        // m_piece_count++;
    }

    // king and queens
    m_pieces.emplace_back( new King(true, true) );
    m_pieces.back().get()->setPos(7, 4);
    player1.getPieces().emplace_back( m_pieces.at(m_piece_count) );
    m_board.getCell(7, 4).setPiece( m_pieces.at(m_piece_count++) );
    // m_piece_count++;
    m_pieces.emplace_back( new King(false, true) );
    m_pieces.back().get()->setPos(0, 4);
    player2.getPieces().emplace_back( m_pieces.at(m_piece_count) );
    m_board.getCell(0, 4).setPiece( m_pieces.at(m_piece_count++) );
    m_pieces.emplace_back( new Queen(true, true) );
    m_pieces.back().get()->setPos(7, 3);
    player1.getPieces().emplace_back( m_pieces.at(m_piece_count) );
    m_board.getCell(7, 3).setPiece( m_pieces.at(m_piece_count++) );
    
    m_pieces.emplace_back( new Queen(false, true) );
    m_pieces.back().get()->setPos(0, 3);
    player2.getPieces().emplace_back( m_pieces.at(m_piece_count) );
    m_board.getCell(0, 3).setPiece( m_pieces.at(m_piece_count++) );



    // others
    for(int i=1; i<=4; i++) {
        if(i%2 == 0) {
            // pass the duchie 'pon the left hand side
            m_pieces.emplace_back( new Rook(true, true) );
            m_pieces.back().get()->setPos(7, 0);
            player1.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(7, 0).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Knight(true, true) );
            m_pieces.back().get()->setPos(7, 1);
            player1.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(7, 1).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Bishop(true, true) );
            m_pieces.back().get()->setPos(7, 2);
            player1.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(7, 2).setPiece( m_pieces.at(m_piece_count++) );
            // right side
            m_pieces.emplace_back( new Rook(true, true) );
            m_pieces.back().get()->setPos(7, 7);
            player1.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(7, 7).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Knight(true, true) );
            m_pieces.back().get()->setPos(7, 6);
            player1.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(7, 6).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Bishop(true, true) );
            m_pieces.back().get()->setPos(7, 5);
            player1.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(7, 5).setPiece( m_pieces.at(m_piece_count++) );
        } else {
            // pass the duchie 'pon the left hand side
            m_pieces.emplace_back( new Rook(false, true) );
            m_pieces.back().get()->setPos(0, 0);
            player2.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(0, 0).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Knight(false, true) );
            m_pieces.back().get()->setPos(0, 1);
            player2.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(0, 1).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Bishop(false, true) );
            m_pieces.back().get()->setPos(0, 2);
            player2.getPieces().emplace_back( m_pieces.at(m_piece_count) );
            m_board.getCell(0, 2).setPiece( m_pieces.at(m_piece_count++) );
            // right side
            m_pieces.emplace_back( new Rook(false, true) );
            m_pieces.back().get()->setPos(0, 7);
            m_board.getCell(0, 7).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Knight(false, true) );
            m_pieces.back().get()->setPos(0, 6);
            m_board.getCell(0, 6).setPiece( m_pieces.at(m_piece_count++) );
            m_pieces.emplace_back( new Bishop(false, true) );
            m_pieces.back().get()->setPos(0, 5);
            m_board.getCell(0, 5).setPiece( m_pieces.at(m_piece_count++) );
        }
    }
}




Cell* Game::get_cell_under_mouse() {
    auto mouse_pos = sf::Mouse::getPosition(m_window);
    mouse_pos.x -= origin_x_offset;
    mouse_pos.y -= origin_y_offset;
    if( mouse_pos.x < 0 || mouse_pos.y < 0 )
        return nullptr;
    int row = mouse_pos.y / cell_height;
    int col = mouse_pos.x / cell_width;

    // std::cout << mouse_pos.y << ", " << mouse_pos.x << '\n';
    if(row >= 8 || col >= 8) {
        return nullptr;
    }
    // std::cout << "r, c from mouse pos: " << row << ", " << col << '\n';
    auto temp = &m_board.getCell(row, col);
    return temp;
}