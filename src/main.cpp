#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
int main(){
   
    RenderWindow window(VideoMode(800,600),"new"); 
    Image image;
    image.loadFromFile("/Users/ijeong-u/Downloads/Logo.png");

    Texture t;
    t.loadFromImage(image);
    Sprite sprite;
    sprite.setTexture(t);


    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){

            window.draw(sprite);

            if(event.type == Event::Closed)
                window.close();

            
        }
        window.clear(Color::Black);
        window.display();

    }


    return 0;
    
}