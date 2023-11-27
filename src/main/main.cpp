#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../lib/Plant.h"

using namespace sf;
int main()
{
    const String filename = "Logo.png";

    RenderWindow window(VideoMode(800, 600), "new");
    Image image;
    image.loadFromFile("/Users/ijeong-u/Desktop/univClass/23-2/OOP/gameSample/SFML_Practice/assets/"+filename);

    Texture t;
    t.loadFromImage(image);
    Sprite sprite;
    sprite.setTexture(t);
    Vector2f size = window.getView().getSize();
    sprite.setScale(size.x / sprite.getLocalBounds().width, size.y / sprite.getLocalBounds().height);
    
    while (window.isOpen())
    {
        Event event;

        window.clear(Color(220, 255, 191,255));
        // window.draw(sprite);
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                window.close();
        }
        
        window.display();
    }

    return 0;
}