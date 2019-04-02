#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <time.h>


void update_branches(int seed);
const int NUM_BRANCHES = 6;
sf::Sprite branches[NUM_BRANCHES];

enum class side { LEFT, RIGHT, NONE };
side positions[NUM_BRANCHES];


int main(void) {
    sf::VideoMode vm(1920, 1080);

    sf::RenderWindow window(vm, "Timber");
    window.setFramerateLimit(60);

    sf::Texture bg;
    bg.loadFromFile("assets/background.png");

    sf::Sprite bg_s;

    bg_s.setTexture(bg);
    bg_s.setPosition(0, 0);

    sf::Texture tree;
    tree.loadFromFile("assets/tree.png");
    sf::Sprite tree_s;

    tree_s.setTexture(tree);
    tree_s.setPosition(810, 0);

    sf::Texture bee;
    bee.loadFromFile("assets/bee.png");
    sf::Sprite bee_s;

    bee_s.setTexture(bee);
    bee_s.setPosition(0, 800);

    bool bee_moving = false;
    float bee_speed = 0.0f;

    sf::Texture cloud;
    cloud.loadFromFile("assets/cloud.png");

    sf::Sprite cloud_s1;
    sf::Sprite cloud_s2;
    sf::Sprite cloud_s3;

    cloud_s1.setTexture(cloud);
    cloud_s2.setTexture(cloud);
    cloud_s3.setTexture(cloud);

    cloud_s1.setPosition(0, 0);
    cloud_s2.setPosition(0, 250);
    cloud_s3.setPosition(0, 500);

    bool cloud1_moving = false;
    bool cloud2_moving = false;
    bool cloud3_moving = false;

    float cloud1_speed = 0.0f;
    float cloud2_speed = 0.0f;
    float cloud3_speed = 0.0f;

    sf::Clock clock;
    sf::Time dt;

    sf::RectangleShape time_bar;
    float time_bar_width = 480;
    float time_bar_height = 80;
    time_bar.setSize(sf::Vector2f(time_bar_width, time_bar_height));
    time_bar.setFillColor(sf::Color::Red);
    time_bar.setPosition((1920 / 2) - time_bar_width / 2, 980);

    sf::Time time_total;
    float time_remaining = 6.0f;
    float width_per_second = time_bar_width / time_remaining;

    bool paused = true;

    int score = 0;

    sf::Text message_text;
    sf::Text score_text;

    sf::Font font;
    font.loadFromFile("assets/fonts/KOMIKAP_.ttf");

    message_text.setFont(font);
    score_text.setFont(font);

    message_text.setString("Press Enter to start!");
    score_text.setString("Score = 0");

    message_text.setCharacterSize(75);
    score_text.setCharacterSize(100);

    message_text.setFillColor(sf::Color::White);
    score_text.setFillColor(sf::Color::White);

    sf::FloatRect text_rect = message_text.getLocalBounds();
    message_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
                           text_rect.top + text_rect.height / 2.0f);
    message_text.setPosition(1920 / 2.0f, 1080 / 2.0f);
    score_text.setPosition(20, 20);

    sf::Texture branch;
    branch.loadFromFile("assets/branch.png");

    for(int i = 0; i < 6; i++) {
        branches[i].setTexture(branch);
        branches[i].setPosition(-2000, -2000);

        branches[i].setOrigin(220, 20);
    }

    sf::Texture player;
    player.loadFromFile("assets/player.png");
    sf::Sprite player_s;
    player_s.setTexture(player);
    player_s.setPosition(580, 720);

    side player_side = side::LEFT;


    sf::Texture rip;
    rip.loadFromFile("assets/rip.png");
    sf::Sprite rip_s;
    rip_s.setTexture(rip);
    rip_s.setPosition(600, 860);

    sf::Texture axe;
    axe.loadFromFile("assets/axe.png");
    sf::Sprite axe_s;
    axe_s.setTexture(axe);
    axe_s.setPosition(700, 830);

    const float AXE_POSITION_LEFT = 700;
    const float AXE_POSITION_RIGHT = 1075;

    sf::Texture log;
    log.loadFromFile("assets/log.png");
    sf::Sprite log_s;
    log_s.setTexture(log);
    log_s.setPosition(810, 720);

    bool log_active = false;
    float log_speed_x = 1000;
    float log_speed_y = -1500;

    bool accept_input = false;

    sf::SoundBuffer chop_buffer;
    chop_buffer.loadFromFile("assets/sound/chop.wav");
    sf::Sound chop_sound;
    chop_sound.setBuffer(chop_buffer);

    sf::SoundBuffer death_buffer;
    death_buffer.loadFromFile("assets/sound/death.wav");
    sf::Sound death_sound;
    death_sound.setBuffer(death_buffer);

    sf::SoundBuffer oot_buffer;
    oot_buffer.loadFromFile("assets/sound/out_of_time.wav");
    sf::Sound oot;
    oot.setBuffer(oot_buffer);
    

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            
            if(event.type == sf::Event::Closed)
                window.close();
            
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
                else if(event.key.code == sf::Keyboard::Return && paused) {
                    paused = false;
                    score = 0;
                    time_remaining = 6.0f;

                    for(int i = 1; i < 6; i++)
                        positions[i] = side::NONE;

                    rip_s.setPosition(675, 2000);
                    player_s.setPosition(580, 720);

                    accept_input = true;
                    clock.restart();
                }
            }
            if(event.type == sf::Event::KeyReleased && !paused) {
                accept_input = true;
                axe_s.setPosition(2000, axe_s.getPosition().y);
            }

            if(accept_input) {
                if(event.type == sf::Event::KeyPressed) {
                    if(event.key.code == sf::Keyboard::Right) {
                        player_side = side::RIGHT;
                        score++;

                        time_remaining += (2 / score) +.15;

                        axe_s.setPosition(AXE_POSITION_RIGHT, axe_s.getPosition().y);

                        player_s.setPosition(1200, 720);

                        update_branches(score);

                        log_s.setPosition(810, 720);
                        log_speed_x = -5000;
                        log_active = true;

                        accept_input = false;

                        chop_sound.play();
                    }
                    else if(event.key.code == sf::Keyboard::Left) {
                        player_side = side::LEFT;
                        score++;

                        time_remaining += (2 / score) +.15;

                        axe_s.setPosition(AXE_POSITION_LEFT, axe_s.getPosition().y);

                        player_s.setPosition(580, 720);

                        update_branches(score);

                        log_s.setPosition(810, 720);
                        log_speed_x = 5000;
                        log_active = true;

                        accept_input = false;

                        chop_sound.play();
                    }
                }
            }
        }

        std::cout << time_remaining << "\n";

        if(!paused) {
            dt = clock.restart();

            time_remaining -= dt.asSeconds();
            time_bar.setSize(sf::Vector2f(width_per_second * time_remaining, time_bar_height));
            if(time_remaining <= 0.0f) {
                paused = true;
                accept_input = false;

                message_text.setString("Out of time!!");

                sf::FloatRect text_rect = message_text.getLocalBounds();
                message_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
                                       text_rect.top + text_rect.height / 2.0f);
                message_text.setPosition(1920 / 2.0f, 1080 / 2.0f);

                oot.play();
            }
            if(!bee_moving) {
                srand((int)time(0) * 10);
                bee_speed = (rand() % 200) + 200;

                srand((int)time(0) * 10);
                float height = (rand() % 500) + 500;
                bee_s.setPosition(2000, height);
                bee_moving = true;
            }
            else {
                bee_s.setPosition(bee_s.getPosition().x - (bee_speed * dt.asSeconds()),
                                  bee_s.getPosition().y);

                if(bee_s.getPosition().x < -100)
                    bee_moving = false;
            }


            if(!cloud1_moving) {
                srand((int)time(0) * 10);
                cloud1_speed = (rand() % 200);

                srand((int)time(0) * 10);
                float height = (rand() % 150);
                cloud_s1.setPosition(-200, height);
                cloud1_moving = true;
            }
            else {
                cloud_s1.setPosition(cloud_s1.getPosition().x +
                                     (cloud1_speed * dt.asSeconds()),
                                     cloud_s1.getPosition().y);

                if(cloud_s1.getPosition().x > 1920)
                    cloud1_moving = false;
            }
        
            if(!cloud2_moving) {
                srand((int)time(0) * 20);
                cloud2_speed = (rand() % 200);

                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                cloud_s2.setPosition(-200, height);
                cloud2_moving = true;
            }
            else {
                cloud_s2.setPosition(cloud_s2.getPosition().x +
                                     (cloud2_speed * dt.asSeconds()),
                                     cloud_s2.getPosition().y);

                if(cloud_s2.getPosition().x > 1920)
                    cloud2_moving = false;
            }
        
            if(!cloud3_moving) {
                srand((int)time(0) * 30);
                cloud3_speed = (rand() % 200);

                srand((int)time(0) * 30);
                float height = (rand() % 450) - 150;
                cloud_s3.setPosition(-200, height);
                cloud3_moving = true;
            }
            else {
                cloud_s3.setPosition(cloud_s3.getPosition().x +
                                     (cloud3_speed * dt.asSeconds()),
                                     cloud_s3.getPosition().y);

                if(cloud_s3.getPosition().x > 1920)
                    cloud3_moving = false;
            }

            std::stringstream ss;
            ss << "Score = " << score;
            score_text.setString(ss.str());

            for(int i = 0; i < 6; i++) {
                float height = i * 150;

                if(positions[i] == side::LEFT) {
                    // move the sprite to left
                    branches[i].setPosition(610, height);
                    // flip the sprite
                    branches[i].setOrigin(220, 40);
                    branches[i].setRotation(180);
                }
                else if(positions[i] == side::RIGHT) {
                    // move the sprite to right
                    branches[i].setPosition(1330, height);
                    // set the sprite rotation normal
                    branches[i].setOrigin(220, 40);
                    branches[i].setRotation(0);
                }
                else {
                    // hide it
                    branches[i].setPosition(3000, height);
                }
            }

            if(log_active) {
                log_s.setPosition(log_s.getPosition().x + (log_speed_x * dt.asSeconds()),
                                  log_s.getPosition().y + (log_speed_y * dt.asSeconds()));

                // has the insect reached the right hand edge
                if(log_s.getPosition().x < -100 ||
                   log_s.getPosition().x > 2000) {
                    log_active = false;
                    log_s.setPosition(810, 720);
                }
            }

            if(positions[5] == player_side) {
                // death
                paused = true;
                accept_input = false;

                // grave
                rip_s.setPosition(525, 760);

                // hide player
                player_s.setPosition(2000, 660);

                message_text.setString("SQUISHED");
                sf::FloatRect text_rect = message_text.getLocalBounds();
                message_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
                                       text_rect.top + text_rect.height / 2.0f);
                message_text.setPosition(1920 / 2.0f, 1080 / 2.0f);

                death_sound.play();
            }
                    
        }
    
        window.clear();
        window.draw(bg_s);
        window.draw(cloud_s1);
        window.draw(cloud_s2);
        window.draw(cloud_s3);
        for(int i = 0; i < 6; i++)
            window.draw(branches[i]);
        window.draw(tree_s);
        window.draw(player_s);
        window.draw(axe_s);
        window.draw(log_s);
        window.draw(rip_s);
        window.draw(bee_s);
        window.draw(time_bar);

        window.draw(score_text);
        if(paused)
            window.draw(message_text);
        window.display();
    }
    
    return(0);
}

void update_branches(int seed) {

    // move all the branches down one
    for(int j = 6 - 1; j > 0; j--) {
        positions[j] = positions[j - 1];
    }

    srand((int)time(0) + seed);
    int r = (rand() % 5);

    switch(r) {
        case 0:
            positions[0] = side::LEFT;
            break;
        case 1:
            positions[0] = side::RIGHT;
            break;
        default:
            positions[0] = side::NONE;
            break;
    }
}
