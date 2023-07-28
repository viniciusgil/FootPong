#include "FootPong.h"


void FootPong::draw_game()
{
    window->clear(sf::Color::Black);
    window->draw(pitch);
    window->draw(team_a);
    window->draw(team_b);
    window->draw(ball);
    window->draw(text_team_a);
    window->draw(text_team_b);
    window->display();
}

void FootPong::events()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }
    }
}


void FootPong::run()
{
    while (window->isOpen())
    {
        events();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            menu = false;
        }

        if (!menu)
        {
            logic();
            draw_game();
        }
        else
        {
            draw_menu();
        }

    }
}

void FootPong::draw_menu()
{
    window->clear(sf::Color::Black);
    //window->draw( campo );
    window->draw(play);
    window->display();
}