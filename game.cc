#include "headers/game.h"

Game::Game() : m_window("Timber", sf::Vector2u(900, 1024)) {
    m_asset.init();
    m_player.init();
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
        m_player.update(m_asset, m_elapsed);
        m_elapsed -= sf::seconds(timestep);
    }
    
}

void Game::handle_events() {
    sf::Event event = m_window.get_event();
    while(m_window.get_render_window()->pollEvent(event)) {
        m_window.listen_events(event);
        m_player.handle_input(event);
        m_asset.handle_input(m_player, event);
        this->handle_input(event);
    }
}

void Game::handle_input(sf::Event event) {
    // input handling
}

void Game::render() {
    m_window.begin_draw();

    m_asset.draw(*m_window.get_render_window());
    m_player.draw(*m_window.get_render_window());

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
