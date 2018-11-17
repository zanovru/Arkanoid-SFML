#include <SFML/Graphics.hpp>
#include "MyClass.h"
using namespace std;
using namespace sf;



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
        ball.update();
        platform.update();
        window.draw(platform.getPlatform());
        window.draw(ball.getCircle());
        window.display();

    }


    return 0;
}
