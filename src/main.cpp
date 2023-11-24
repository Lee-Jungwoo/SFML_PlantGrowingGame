#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 1280u, 720u }, "CMake SFML Project" };
    // sf::RenderWindow window;
    
    window.setFramerateLimit(144);
    
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                
                window.close();
            }
        }

        window.clear();
        window.display();
    }
}