#include "headers/game.h"

Game::Game() : m_window("Timber", sf::Vector2u(900, 1024)) {
    m_asset.init();
    m_player.init();
    m_text.setup(5, 23, 350, sf::Vector2f(150, 0));
    m_text.add("Time Left" + std::to_string(m_time_left), 0);
    m_text.add("Score: 0", 1);
    m_time_left = 8.f;
}

Game::~Game() {}

void Game::update() {

    sf::Vector2u wsize = m_window.get_window_size();

    float timestep = 1.0f / 60.f;


    // 60 frames per second
    if(m_elapsed.asSeconds() >= timestep) {
        if(!m_player.has_lost()) {
            m_asset.update(m_elapsed);
            m_player.update(m_asset, m_elapsed);
            
            if(m_time_left < 0.01f)
                m_player.lose();
            else
                m_time_left -= m_elapsed.asSeconds();
            
            m_text.add("Time Left: " + std::to_string(m_time_left), 1);
            m_elapsed -= sf::seconds(timestep);
        }
        else {
            m_text.clear();
            m_text.add("YOU LOST!", 0);
            m_text.add("Score: " + std::to_string(m_player.get_score()), 1);
        }
    }


    
}

void Game::handle_events() {
    sf::Event event = m_window.get_event();
    while(m_window.get_render_window()->pollEvent(event)) {
        m_window.listen_events(event);
        if(!m_player.has_lost()) {
            m_player.handle_input(event);
            m_asset.handle_input(m_player, m_text, event);
        }
        
        this->handle_input(event);
    }
}

void Game::handle_input(sf::Event event) {
    // input handling

    if(event.type == sf::Event::KeyPressed)
        if((event.key.code == sf::Keyboard::Left || sf::Keyboard::Right) && !m_player.has_lost())
            m_time_left += .21f;
}

void Game::render() {
    m_window.begin_draw();

    m_asset.draw(*m_window.get_render_window());
    m_player.draw(*m_window.get_render_window());
    m_text.draw(*m_window.get_render_window());

    m_window.end_draw();
}

Window* Game::get_window() {
    return(&m_window);
}

sf::Time Game::get_elapsed() {
    return(m_elapsed);
}

void Game::restart_clock() {
    m_elapsed += m_clock.restart();
}
