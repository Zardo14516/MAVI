#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>


class SpriteManager {
private:
    sf::Texture texture; 
    sf::Sprite sprite; 
    int clickCount; 
    sf::Clock clock; 

public:
    
    SpriteManager() : clickCount(0) {
        
        if (!texture.loadFromFile("C:\\Users\\Usuario\\Desktop\\Lu Facultad\\MAVI\\U4\\Unidad4_Assets\\et.png")) {
            std::cerr << "Error: No se pudo cargar la textura et.png" << std::endl;
            exit(-1);
        }

        
        sprite.setTexture(texture);

       
        sprite.setScale(80.f / texture.getSize().x, 80.f / texture.getSize().y);

        
        setOriginToCenter();

       
        respawnSprite();

        
        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    
    void update() {}

    
    bool handleMouseClick(const sf::Vector2i& mousePosition, sf::RenderWindow& window) {
        if (sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            
            clickCount++;

           
            if (clickCount >= 5) {
                window.close();
                std::cout << "Game Over!" << std::endl;
                return true;
            }

            respawnSprite();
        }
        return false;
    }

    
    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    
    void respawnSprite() {
        float x = static_cast<float>(std::rand() % 800);
        float y = static_cast<float>(std::rand() % 600);
        sprite.setPosition(x, y);
    }

    
    void setOriginToCenter() {
        sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
    }
};

int main() {
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mi Ventana");

    
    window.setFramerateLimit(60);

    
    window.setMouseCursorVisible(false);

    
    sf::Texture crosshairTexture;
    if (!crosshairTexture.loadFromFile("C:\\Users\\Usuario\\Desktop\\Lu Facultad\\MAVI\\U4\\Unidad4_Assets\\crosshair.png")) {
        std::cerr << "Error: No se pudo cargar el archivo crosshair.png" << std::endl;
        return -1;
    }

    
    sf::Sprite crosshairSprite;
    crosshairSprite.setTexture(crosshairTexture);

    
    crosshairSprite.setScale(20.f / crosshairTexture.getSize().x, 20.f / crosshairTexture.getSize().y);

   
    SpriteManager spriteManager;

    
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                std::cout << "Game Over!" << std::endl;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                spriteManager.handleMouseClick(mousePosition, window);
            }
        }

      
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        
        crosshairSprite.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

        
        spriteManager.update();

        
        window.clear(sf::Color::Black);

        
        spriteManager.draw(window);

        
        window.draw(crosshairSprite);

        
        window.display();
    }

    return 0;
}
