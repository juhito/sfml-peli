#include "headers/text.h"

Text::Text() {
    this->setup(5, 9, 200, sf::Vector2f(0,0));
}

Text::Text(int visible, int csize, int width, sf::Vector2f pos) {
    this->setup(visible, csize, width, pos);
}

Text::~Text() {
    this->clear();
}

void Text::setup(int visible, int csize, int width, sf::Vector2f pos) {
    m_visible = visible;

    sf::Vector2f offset(2.0f, 2.0f);

    m_font.loadFromFile("assets/FreeMono.ttf");
    m_content.setFont(m_font);
    m_content.setString("");
    m_content.setCharacterSize(csize);
    m_content.setColor(sf::Color::White);
    m_content.setPosition(pos + offset);
}

void Text::add(std::string message, int pos) {
    m_messages.insert(m_messages.begin() + pos, message);
    if(m_messages.size() < 3) return;
    m_messages.erase(m_messages.begin());
}

void Text::clear() {
    m_messages.clear();
}

void Text::draw(sf::RenderWindow& window) {
    std::string content;

    for(auto& itr : m_messages)
        content.append(itr + "\n");

    if(content != "") {
        m_content.setString(content);
        window.draw(m_content);
    }
}
