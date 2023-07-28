#include "FootPong.h"

FootPong::FootPong()
{

    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(1280, 720),
        "FootPong",
        sf::Style::Titlebar | sf::Style::Close
    );

    window->setPosition(sf::Vector2i(0, 0));

    points_team_a = points_team_b = {};
    speed = 0.4f;
    start = false;
    menu = true;

    team_a.setSize(sf::Vector2f(50.f, 72.f));
    team_b.setSize(sf::Vector2f(50.f, 72.f));
    team_a.setPosition(0, 20.f);
    team_b.setPosition(window->getSize().x - team_b.getSize().x, 20.f);

    tball.loadFromFile("./assets/img/ball64.png");
    tpitch.loadFromFile("./assets/img/campo.jpg");
    t_team_a.loadFromFile("./assets/img/player1.png");
    t_team_b.loadFromFile("./assets/img/player2.png");

    ball.setTexture(tball);
    pitch.setTexture(tpitch);

    team_a.setTexture(&t_team_a);
    team_b.setTexture(&t_team_b);

    velocity = sf::Vector2f(speed, speed);

    font.loadFromFile("./assets/font/font.ttf");

    // Team A(left)
    text_team_a.setFont(font);
    text_team_a.setString(std::to_string(points_team_a));
    text_team_a.setPosition(static_cast<float>(1280) / 2 - 50, 10);
    text_team_a.setCharacterSize(50);
    text_team_a.setOutlineThickness(3);

    // Team B(Right)
    text_team_b.setFont(font);
    text_team_b.setString(std::to_string(points_team_b));
    text_team_b.setPosition(static_cast<float>(1280) / 2 + 10, 10);
    text_team_b.setCharacterSize(50);
    text_team_b.setOutlineThickness(3);

    // Start Screen
    play.setFont(font);
    play.setString("START THE GAME");
    play.setPosition(static_cast<float>(1280) / 2 - 180, 300);
    play.setCharacterSize(50);
    play.setOutlineThickness(3);
}