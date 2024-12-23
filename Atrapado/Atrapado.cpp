#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    
    RenderWindow window(VideoMode(800, 600), "Aplicacion con SFML");
    window.setFramerateLimit(60);

    
    Texture textureSquare;
    if (!textureSquare.loadFromFile("C:\\Users\\Usuario\\Desktop\\Lu Facultad\\MAVI\\U4\\Unidad4_Assets\\cuad_yellow.png")) {
        cerr << "Error al cargar la textura del cuadrado" << endl;
        return -1;
    }

    
    Texture textureCircle;
    if (!textureCircle.loadFromFile("C:\\Users\\Usuario\\Desktop\\Lu Facultad\\MAVI\\U4\\Unidad4_Assets\\rcircleg.png")) {
        cerr << "Error al cargar la textura del círculo" << endl;
        return -1;
    }

    
    Sprite sprite;
    sprite.setTexture(textureSquare);

    
    sprite.setOrigin(sprite.getTexture()->getSize().x / 2.f, sprite.getTexture()->getSize().y / 2.f);

    
    sprite.setScale(50.0f / sprite.getTexture()->getSize().x, 50.0f / sprite.getTexture()->getSize().y);

    
    Vector2f initialPosition(400, 300);
    sprite.setPosition(initialPosition);

   
    bool isSquare = true; 

    while (window.isOpen()) {
        
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                if (isSquare) {
                    sprite.setTexture(textureCircle, true); 
                }
                else {
                    sprite.setTexture(textureSquare, true); 
                }
                
                sprite.setOrigin(sprite.getTexture()->getSize().x / 2.f, sprite.getTexture()->getSize().y / 2.f);
                sprite.setScale(50.0f / sprite.getTexture()->getSize().x, 50.0f / sprite.getTexture()->getSize().y);

                isSquare = !isSquare; 
            }
        }

        
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            sprite.move(0, -5);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            sprite.move(0, 5);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            sprite.move(-5, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            sprite.move(5, 0);
        }

        
        FloatRect bounds = sprite.getGlobalBounds();
        if (bounds.left <= 0 || bounds.left + bounds.width >= 800 || bounds.top <= 0 || bounds.top + bounds.height >= 600) {
            sprite.setPosition(initialPosition);
        }

        
        window.clear();

        
        window.draw(sprite);

        
        window.display();
    }

    return 0;
}
