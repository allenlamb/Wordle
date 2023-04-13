#include "Wordle.h"
#include "ColorSelector.h"
int main() {
    srand(time(nullptr));
    Wordle project;
    ColorSelector color("Background Color",{1150,5},sf::Color(31,32,33));
    sf::RenderWindow window(sf::VideoMode(1600, 1500), "Wordle");
    window.setFramerateLimit(30);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            project.addEventHandler(window,event);
            color.addEventHandler(window,event);
        }
        color.update();
        project.update();
        window.clear(color.getColor());
        window.draw(project);
        window.draw(color);
        window.display();
    }
    return 0;
}

