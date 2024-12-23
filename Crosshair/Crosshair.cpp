#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "crosshair");

    
    sf::Texture crosshairTexture;
    std::string crosshairPath = "C:/Users/Usuario/Desktop/Lu Facultad/MAVI/U4/Unidad4_Assets/crosshair.png";

    if (!crosshairTexture.loadFromFile(crosshairPath)) {
        std::cerr << "Error al cargar la textura del crosshair." << std::endl;
        return -1;
    }

    
    sf::Sprite crosshairSprite(crosshairTexture);

    
    sf::FloatRect bounds = crosshairSprite.getLocalBounds();
    crosshairSprite.setOrigin(bounds.width / 2, bounds.height / 2);

    
    crosshairSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        
        window.draw(crosshairSprite);

        window.display();
    }

    return 0;
}
