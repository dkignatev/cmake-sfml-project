#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);


    //background 
    int width = 1024;
    int height = 1024;
    sf::Texture texture;
    sf::Sprite sprite;
   if (!texture.loadFromFile("../../src/green fon.png", sf::IntRect(0, 0, width, height)))
    {
    std::cout << "Error loading\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(420.f, 28.f)); 


    //"player"
    sf::CircleShape shape(40.f);
    shape.setFillColor(sf::Color(250, 50, 50));
    shape.setOutlineThickness(6.f);
    shape.setOutlineColor(sf::Color(250, 100, 50));
    shape.setPosition(sf::Vector2f(432.f, 38.f));

    sf::Event event;

    //main loop
    while (window.isOpen())
    {
        //prevent continuous movement
        //window.setKeyRepeatEnabled(false);

        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(shape);
        window.display();


        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(event.key.scancode == sf::Keyboard::Scan::Left && shape.getPosition().x > 534)
                        shape.move(-102.4f, 0.f);
                    else if(event.key.scancode == sf::Keyboard::Scan::Right && shape.getPosition().x < 1352)
                        shape.move(102.4f, 0.f);
                    else if(event.key.scancode == sf::Keyboard::Scan::Down && shape.getPosition().y < 950)
                        shape.move(0.f, 102.4f);
                    else if(event.key.scancode == sf::Keyboard::Scan::Up && shape.getPosition().y > 140)
                        shape.move(0.f, -102.4f);
                    break;

                default:
                    break;
            }
        }
    }
}
