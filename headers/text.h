#if !defined(TEXT_H)
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Text {
public:
    Text();
    Text(int visible, int csize, int width, sf::Vector2f pos);
    ~Text();

    void setup(int visible, int csize, int width, sf::Vector2f pos);
    void add(std::string message, int pos=0);
    void clear();

    void draw(sf::RenderWindow& window);
private:
    std::vector<std::string> m_messages;
    int m_visible;

    sf::Font m_font;
    sf::Text m_content;
};

#endif
