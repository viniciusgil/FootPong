#include "FootPong.h"

void FootPong::logic()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (team_a.getPosition().y < window->getSize().y - team_a.getSize().y)
		{
			team_a.move(0, speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (team_a.getPosition().y > 0)
		{
			team_a.move(0, -speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (team_b.getPosition().y < window->getSize().y - team_b.getSize().y)
		{
			team_b.move(0, speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (team_b.getPosition().y > 0)
		{
			team_b.move(0, -speed);
		}
	}
	//Team B (AI)
	if (ball.getPosition().x > 1280 / 2) // Make the machine move when the ball is on the AI side.
	{
		team_b.setPosition(team_b.getPosition().x, ball.getPosition().y);
	}


	if ((ball.getPosition().y > window->getSize().y && velocity.y > 0) ||
		(ball.getPosition().y < 0 && velocity.y < 0))
	{
		velocity.y = -velocity.y;
	}
	//Players collision, team A (left).
	if (team_a.getGlobalBounds().intersects(ball.getGlobalBounds()) && velocity.x < 0)
	{
		velocity.x = -velocity.x;
	}
	//Players collision, team B (Rigth).
	if (team_b.getGlobalBounds().intersects(ball.getGlobalBounds()) && velocity.x > 0)
	{
		velocity.x = -velocity.x;
	}

	ball.setPosition(ball.getPosition() + velocity);

	if (ball.getPosition().x < 0 && !start)
	{
		text_team_a.setString(std::to_string(++points_team_a));
		start = true;
	}
	if (ball.getPosition().x > 1280 && !start)
	{
		text_team_b.setString(std::to_string(++points_team_b));
		start = true;
	}
	//Score
	if (ball.getPosition().x > 1280 || ball.getPosition().x < 0)
	{
		ball.setPosition(
			static_cast<float>(window->getSize().x) / 2 - ball.getGlobalBounds().width / 2,
			static_cast<float>(window->getSize().y) / 2 - ball.getGlobalBounds().height / 2
		);
		start = false;
	}
}