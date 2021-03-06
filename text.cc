#include "headers/text.h"

Text::Text() {
    this->setup(9, sf::Vector2f(0,0));
}

Text::Text(int csize, sf::Vector2f pos) {
    this->setup(csize, pos);
}

Text::~Text() {
    this->clear();
}

void Text::setup(int csize, sf::Vector2f pos) {   
    sf::Vector2f offset(2.0f, 2.0f);

    m_font.loadFromFile("assets/FreeMono.ttf");
    m_content.setFont(m_font);
    m_content.setString("");
    m_content.setCharacterSize(csize);
    m_content.setFillColor(sf::Color::White);
    m_content.setPosition(pos + offset);
}

void Text::add(std::string message) {
    m_string = message;
}

void Text::clear() {
    m_string = "";
}

void Text::draw(sf::RenderWindow& window) {
    if(m_string != "") {
        m_content.setString(m_string);
        window.draw(m_content);
    }
}
