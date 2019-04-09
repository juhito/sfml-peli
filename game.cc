#include "headers/game.h"

Game::Game() : m_window("Timber", sf::Vector2u(900, 1600)) {
    m_asset.init();
    m_score = 0;
    m_input = true;
}

Game::~Game() {}

void Game::update() {

    sf::Vector2u wsize = m_window.get_window_size();

    float timestep = 1.0f / 60.f;

    // 60 frames per second
    if(m_elapsed.asSeconds() >= timestep) {
        m_asset.update(m_elapsed);
        m_elapsed -= sf::seconds(timestep);
    }
    
}

void Game::handle_events() {
    sf::Event event = m_window.get_event();
    while(m_window.get_render_window()->pollEvent(event)) {
        m_window.listen_events(event);
        this->handle_input(event);
    }
}

void Game::handle_input(sf::Event event) {
    switch(event.type) {
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Left && m_input) {
                m_asset.log_active = true;
                m_score++;
                m_asset.update_branches(m_score);
                m_input = false;
            }
            else if(event.key.code == sf::Keyboard::Right && m_input) {
                m_asset.log_active = true;
                m_score++;
                m_asset.update_branches(m_score);
                m_input = false;
            }
            break;
        case sf::Event::KeyReleased:
            m_input = true;
            break;
    }
}

void Game::render() {
    m_window.begin_draw();

    m_asset.draw(*m_window.get_render_window());

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
