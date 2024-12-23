#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

int main(int argc, char* args[]) {

    RenderWindow window(VideoMode(100, 100), "Ventana Redimensionable");


    const Vector2u minSize(100, 100);
    const Vector2u maxSize(1000, 1000);


    Vector2u originalSize = window.getSize();


    window.setFramerateLimit(60);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }


            if (event.type == Event::Resized) {
                unsigned int width = event.size.width;
                unsigned int height = event.size.height;


                if (width < minSize.x) width = minSize.x;
                if (height < minSize.y) height = minSize.y;
                if (width > maxSize.x) width = maxSize.x;
                if (height > maxSize.y) height = maxSize.y;


                window.setSize(Vector2u(width, height));
            }


            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                Vector2u currentSize = window.getSize();


                currentSize.x += 50;
                currentSize.y += 50;


                if (currentSize.x > maxSize.x || currentSize.y > maxSize.y) {
                    currentSize = originalSize;
                }


                window.setSize(currentSize);
            }
        }


        window.clear();


        window.display();
    }

    return 0;
}
