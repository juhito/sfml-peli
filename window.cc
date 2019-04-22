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
    m_done = false;
    this->create();
}

void Window::handle_events(sf::Event& event) {
    switch(event.type) {
        case sf::Event::Closed:
            m_done = true;
            break;
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Escape)
                m_done = true;
            break;
    }
}

void Window::create() {
    auto style = sf::Style::Default;
    m_window.create({m_wsize.x, m_wsize.y}, m_wtitle, style);
    
    // NOTE: Manipulate the 2d camera so it fits the screen
    // Textures will look a bit scaled now but its fine for this project.
    m_view.reset(sf::FloatRect(0.f, 0.f, M_VIEW_X, M_VIEW_Y));
    m_view.zoom(1.f);
    m_window.setView(m_view);
}

void Window::destroy() {
    m_window.close();
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
