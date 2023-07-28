#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class FootPong {

    // SFML
    std::shared_ptr<sf::RenderWindow> window;
    sf::RectangleShape team_a, team_b;
    sf::Texture t_team_a, t_team_b, tpitch, tball;
    sf::Sprite pitch, ball;
    sf::Vector2f velocity;
    sf::Font font;
    sf::Text text_team_a, text_team_b, play;

    int points_team_a, points_team_b;
    float speed;
    bool start, menu;

protected:
    void events();
    void draw_game();
    void draw_menu();
    void logic();

public:
    FootPong();
    void run();
};
