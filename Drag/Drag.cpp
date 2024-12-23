#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Arrastrar Sprites");

    // Cargar la textura de rcircle
    sf::Texture rcircleTexture;
    std::string rcirclePath = "C:/Users/Usuario/Desktop/Lu Facultad/MAVI/U4/Unidad4_Assets/rcircle.png";

    if (!rcircleTexture.loadFromFile(rcirclePath)) {
        std::cerr << "Error al cargar la textura de rcircle." << std::endl;
        return -1;
    }

    // Crear los sprites rcircle para cada esquina
    sf::Sprite rcircleSprite1(rcircleTexture);
    sf::Sprite rcircleSprite2(rcircleTexture);
    sf::Sprite rcircleSprite3(rcircleTexture);
    sf::Sprite rcircleSprite4(rcircleTexture);

    // Establecer el origen del sprite en su centro 
    sf::FloatRect bounds = rcircleSprite1.getLocalBounds();
    rcircleSprite1.setOrigin(bounds.width / 2, bounds.height / 2);
    rcircleSprite2.setOrigin(bounds.width / 2, bounds.height / 2);
    rcircleSprite3.setOrigin(bounds.width / 2, bounds.height / 2);
    rcircleSprite4.setOrigin(bounds.width / 2, bounds.height / 2);

    // Definir las posiciones para las cuatro esquinas
    rcircleSprite1.setPosition(0, 0);
    rcircleSprite2.setPosition(window.getSize().x, 0);
    rcircleSprite3.setPosition(0, window.getSize().y);
    rcircleSprite4.setPosition(window.getSize().x, window.getSize().y);

    // Variables para arrastrar
    bool isDragging = false;
    sf::Sprite* draggedSprite = nullptr;
    sf::Vector2i mouseOffset;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Detectar si se ha hecho clic sobre algún sprite
                    if (rcircleSprite1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        isDragging = true;
                        draggedSprite = &rcircleSprite1;
                        mouseOffset = sf::Vector2i(event.mouseButton.x - rcircleSprite1.getPosition().x, event.mouseButton.y - rcircleSprite1.getPosition().y);
                    }
                    else if (rcircleSprite2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        isDragging = true;
                        draggedSprite = &rcircleSprite2;
                        mouseOffset = sf::Vector2i(event.mouseButton.x - rcircleSprite2.getPosition().x, event.mouseButton.y - rcircleSprite2.getPosition().y);
                    }
                    else if (rcircleSprite3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        isDragging = true;
                        draggedSprite = &rcircleSprite3;
                        mouseOffset = sf::Vector2i(event.mouseButton.x - rcircleSprite3.getPosition().x, event.mouseButton.y - rcircleSprite3.getPosition().y);
                    }
                    else if (rcircleSprite4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        isDragging = true;
                        draggedSprite = &rcircleSprite4;
                        mouseOffset = sf::Vector2i(event.mouseButton.x - rcircleSprite4.getPosition().x, event.mouseButton.y - rcircleSprite4.getPosition().y);
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    isDragging = false;
                    draggedSprite = nullptr;
                }
            }

            if (event.type == sf::Event::MouseMoved) {
                if (isDragging && draggedSprite != nullptr) {
                    // Actualizar la posición del sprite arrastrado
                    draggedSprite->setPosition(event.mouseMove.x - mouseOffset.x, event.mouseMove.y - mouseOffset.y);
                }
            }
        }

        window.clear();

        // Dibujar los sprites
        window.draw(rcircleSprite1);
        window.draw(rcircleSprite2);
        window.draw(rcircleSprite3);
        window.draw(rcircleSprite4);

        window.display();
    }

    return 0;
}
