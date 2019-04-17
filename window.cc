#include "headers/window.h"

Window::Window() {
    this->setup("Window", {640, 480});
}

Window::Window(const std::string& title, const sf::Vector2u& size) {
    this->setup(title, size);
}

Window::~Window() {
    this->destroy();
}

void Window::setup(const std::string &title, const sf::Vector2u &size) {
    m_wtitle = title;
    m_wsize = size;
    m_fullscreen = false;
    m_done = false;
    this->create();
}

void Window::listen_events(sf::Event event) {
    switch(event.type) {
        case sf::Event::Closed:
            m_done = true;
            break;
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Escape)
                m_done = true;
            if(event.key.code == sf::Keyboard::F5)
                this->toggle_fullscreen();
            break;
    }
}

void Window::create() {
    auto style = (m_fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_wsize.x, m_wsize.y, 32}, m_wtitle, style);
    
    // NOTE: Manipulate the 2d camera so it fits the screen
    // Textures will look a bit scaled now but its fine for this project.
    m_view.reset(sf::FloatRect(0.f, 0.f, 900.f, 1600.f));
    m_view.zoom(1.f);
    m_window.setView(m_view);
}

void Window::destroy() {
    m_window.close();
}

void Window::toggle_fullscreen() {
    m_fullscreen = !m_fullscreen;
    this->destroy();
    this->create();
}

void Window::toggle_done() {
    m_done = !m_done;
}

void Window::begin_draw() {
    m_window.clear(sf::Color::Black);
}

void Window::end_draw() {
    m_window.display();
}

bool Window::is_done() {
    return(m_done);
}

bool Window::is_fullscreen() {
    return(m_fullscreen);
}

sf::Vector2u Window::get_window_size() {
    return(m_wsize);
}

void Window::draw(sf::Drawable& asset) {
    m_window.draw(asset);
}

sf::RenderWindow* Window::get_render_window() {
    return(&m_window);
}

sf::Event& Window::get_event() {
    return(m_event);
}
