#if !defined(WINDOW_H)
#define WINDOW_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window();
    Window(const std::string& title, const sf::Vector2u& size);
    ~Window();

    void begin_draw();
    void end_draw();

    void draw(sf::Drawable& asset);
    void listen_events(sf::Event event);

    bool is_done();
    bool is_fullscreen();

    sf::Vector2u get_window_size();

    void toggle_fullscreen();
    void toggle_done();

    sf::RenderWindow* get_render_window();
    sf::Event& get_event();

private:
    void setup(const std::string& title, const sf::Vector2u& size);
    void destroy();
    void create();

    sf::RenderWindow m_window;
    sf::Event m_event;
    sf::Vector2u m_wsize;
    std::string m_wtitle;

    bool m_done;
    bool m_fullscreen;
};

#endif
