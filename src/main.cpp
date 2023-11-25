#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
int main()
{
    const String filename = "";

    RenderWindow window(VideoMode(800, 600), "new");
    Image image;
    image.loadFromFile("/Users/ijeong-u/Desktop/univClass/23-2/OOP/gameSample/SFML_Practice/assets/");

    Texture t;
    t.loadFromImage(image);
    Sprite sprite;
    sprite.setTexture(t);
    Vector2f size = window.getView().getSize();
    sprite.setScale(size.x / sprite.getLocalBounds().width, size.y / sprite.getLocalBounds().height);

    while (window.isOpen())
    {
        Event event;

        window.clear(Color(220, 255, 191, 255));
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                window.close();
        }
        window.draw(sprite);
        window.display();
    }

    return 0;
}