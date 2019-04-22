#include "headers/game.h"

Game::Game() : m_window("Timber", sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)) {
    m_asset.init();
    m_player.init();
    m_time.setup(23, sf::Vector2f(100, 0));
    m_score.setup(23, sf::Vector2f(100, 24));
    m_time.add("Time Left" + std::to_string(m_time_left));
    m_score.add("Score: 0");
    m_time_left = DEFAULT_GAME_TIME;
}

Game::~Game() {}

void Game::update() {
    sf::Vector2u wsize = m_window.get_window_size();

    float timestep = 1.0f / FRAMES_PER_SECOND;

    // 60 frames per second
    if(m_elapsed.asSeconds() >= timestep) {
        if(!m_player.has_lost()) {
            m_asset.update(m_elapsed);
            m_player.update(m_asset, m_elapsed);
            
            if(m_time_left < 0.01f)
                m_player.lose();
            else
                m_time_left -= m_elapsed.asSeconds();
            
            m_time.add("Time Left: " + std::to_string(m_time_left));
            m_elapsed -= sf::seconds(timestep);
        }
        else {
            m_time.add("YOU LOST!");
            m_score.add("Score: " + std::to_string(m_player.get_score()));
        }
    }
}

void Game::handle_events() {
    sf::Event event = m_window.get_event();
    while(m_window.get_render_window()->pollEvent(event)) {
        m_window.handle_events(event);
        if(!m_player.has_lost()) {
            m_player.handle_input(event);
            m_asset.handle_input(m_player, m_score, event);
        }
        
        this->handle_input(event);
    }
}

void Game::handle_input(sf::Event event) {
    // input handling

    if(event.type == sf::Event::KeyPressed)
        if((event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
           && !m_player.has_lost())
            m_time_left += TIME_INCREMENT;
}

void Game::render() {
    m_window.begin_draw();

    m_asset.draw(*m_window.get_render_window());
    m_player.draw(*m_window.get_render_window());
    m_time.draw(*m_window.get_render_window());
    m_score.draw(*m_window.get_render_window());

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
