#include "stdafx.h"
#include "App.h"

void App::run()
{
    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    sf::ContextSettings settings = window.getSettings();
    printf("OpenGL Version: %d.%d", settings.majorVersion, settings.minorVersion);
   
    //printf("%s", getResourcePath().c_str());
    
    sf::Texture texture;
    if (!texture.loadFromFile(getResourcePath() + "cute_image.jpg")) {
        //return EXIT_FAILURE;
        assert(false);
    }
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
     */
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    sf::Image icon;
    if (!icon.loadFromFile(getResourcePath() + "icon.png")) {
        assert(false);
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    sf::Texture texture;
    if (!texture.loadFromFile(getResourcePath() + "cute_image.jpg")) {
        assert(false);
    }
    sf::Sprite sprite(texture);
    
    sf::Font font;
    if (!font.loadFromFile(getResourcePath() + "sansation.ttf")) {
        assert(false);
    }
    sf::Text text("Hello SFML", font, 50);
    text.setColor(sf::Color::Black);
    
    sf::Music music;
    if (!music.openFromFile(getResourcePath() + "nice_music.ogg")) {
        assert(false);
    }
    
    music.play();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();
    }

}