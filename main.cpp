#include <SFML/Graphics.hpp>
#include <vector>
#include "MyClass.h"
using namespace std;
using namespace sf;

//#TODO
//1. Окно Game over
//2. Окно Начальной заставки
//3. Загрузка текстур блоков, мяча и платформы

int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arkanoid Game", Style::Close);
    Ball ball(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    Platform platform(WINDOW_WIDTH/2, WINDOW_HEIGHT - 50);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }
        window.clear(Color::Black);
        ball.update(window);
        platform.update();
        testIntersection(platform, ball);
        window.draw(platform.getShape());
        window.draw(ball.getShape());
        window.display();

    }


    return 0;
}


