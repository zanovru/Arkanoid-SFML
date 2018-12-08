#include <SFML/Graphics.hpp>
#include <vector>
#include "MyClass.h"
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arkanoid Game", Style::Default);
    Ball ball(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    Platform platform(WINDOW_WIDTH/2, WINDOW_HEIGHT - 50);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    vector<Brick> bricks;
    bricks.reserve(BRICKS_X*BRICKS_Y);
    for(int i = 0; i < BRICKS_X; ++i)
        for(int j = 0; j < BRICKS_Y; j++)
        {
            bricks.emplace_back((i + 1) * (BRICK_WIDTH + 4) + 110 , (j + 1) * (BRICK_HEIGHT + 4));
        }
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
        if(bricks.size() == 0) window.close();
        window.clear(Color::Black);
        ball.update(window);
        platform.update();
        testIntersection(platform, ball);
        for(auto& brick : bricks) testIntersection(brick, ball);
        bricks.erase(remove_if(begin(bricks), end(bricks), [](Brick& brick){return brick.getIsDestroyed();}),end(bricks));
        window.draw(platform.getShape());
        window.draw(ball.getShape());
        for(auto& brick : bricks) window.draw(brick.getShape());
        window.display();

    }


    return 0;
}


