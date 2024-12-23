#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Crear la ventana de la aplicación
    sf::RenderWindow window(sf::VideoMode(800, 600), "Círculos de colores");

    // Inicialización de punteros para los círculos
    sf::Sprite* redCircles = nullptr;
    sf::Sprite* blueCircles = nullptr;

    int redCircleCount = 0;  // Contador de círculos rojos
    int blueCircleCount = 0; // Contador de círculos azules

    // Cargar las texturas de los círculos
    sf::Texture redTexture;
    sf::Texture blueTexture;

    if (!redTexture.loadFromFile("C:/Users/Usuario/Desktop/Lu Facultad/MAVI/U4/Unidad4_Assets/rcircle.png")) {
        std::cerr << "Error al cargar rcircle.png" << std::endl;
        return -1;
    }

    if (!blueTexture.loadFromFile("C:/Users/Usuario/Desktop/Lu Facultad/MAVI/U4/Unidad4_Assets/rcircleb.png")) {
        std::cerr << "Error al cargar rcircleb.png" << std::endl;
        return -1;
    }

    
    redTexture.setSmooth(true);
    blueTexture.setSmooth(true);

   
    while (window.isOpen()) {
        sf::Event event;

        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
              
                sf::Sprite* tempRedCircles = new sf::Sprite[redCircleCount + 1];

                
                for (int i = 0; i < redCircleCount; i++) {
                    tempRedCircles[i] = redCircles[i];
                }

                
                sf::Sprite redCircleSprite(redTexture);
                redCircleSprite.setOrigin(redTexture.getSize().x / 2.f, redTexture.getSize().y / 2.f);
                redCircleSprite.setPosition(event.mouseButton.x, event.mouseButton.y);
                tempRedCircles[redCircleCount] = redCircleSprite;

                
                delete[] redCircles;
                redCircles = tempRedCircles;

                
                redCircleCount++;
            }

          
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
                
                sf::Sprite* tempBlueCircles = new sf::Sprite[blueCircleCount + 1];

                
                for (int i = 0; i < blueCircleCount; i++) {
                    tempBlueCircles[i] = blueCircles[i];
                }

               
                sf::Sprite blueCircleSprite(blueTexture);
                blueCircleSprite.setOrigin(blueTexture.getSize().x / 2.f, blueTexture.getSize().y / 2.f);
                blueCircleSprite.setPosition(event.mouseButton.x, event.mouseButton.y);
                tempBlueCircles[blueCircleCount] = blueCircleSprite;

                
                delete[] blueCircles;
                blueCircles = tempBlueCircles;

                
                blueCircleCount++;
            }
        }

        
        window.clear();

        
        for (int i = 0; i < redCircleCount; i++) {
            window.draw(redCircles[i]);
        }

       
        for (int i = 0; i < blueCircleCount; i++) {
            window.draw(blueCircles[i]);
        }

        
        window.display();
    }

    
    delete[] redCircles;
    delete[] blueCircles;

    return 0;
}
