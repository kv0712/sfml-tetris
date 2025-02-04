#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Tetris");
    window.setFramerateLimit(60);
    sf::RectangleShape square(sf::Vector2f(64, 64));
    square.setPosition(sf::Vector2f((window.getSize().x / 2 - square.getSize().x / 2), 0));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            } 
        }


        
        if (square.getPosition().y + square.getSize().x < window.getSize().y)
        {
        	square.move({0, 3});

        	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) && square.getPosition().x > 0)
			{
			    square.move({-10.f, 0.f});
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) && 
			    square.getPosition().x + square.getSize().x < window.getSize().x)
			{
			    square.move({10.f, 0.f});
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
				square.move({0, 7});
        }

        else
        {
        	sf::RectangleShape square(sf::Vector2f(64, 64));
    		square.setPosition(sf::Vector2f((window.getSize().x / 2 - square.getSize().x / 2), 0));

        }

        window.clear(sf::Color::Blue);
        window.draw(square);
        window.display();
    }
}
