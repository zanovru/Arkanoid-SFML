#include "MyClass.h"

Ball::Ball(float dx, float dy)
{
    /*Image image;
    image.loadFromFile("/Users/vitalyruzanov/Desktop/imgutility.jpeg");
    Texture texture;
    texture.loadFromImage(image);
    shape.setTexture(&texture);
    shape.setTextureRect(IntRect(0,175,WINDOW_WIDTH,WINDOW_HEIGHT));*/
    shape.setPosition(dx,dy);
    shape.setRadius(BALL_RADIUS);
    shape.setFillColor(Color::Magenta);
    shape.setOrigin(BALL_RADIUS,BALL_RADIUS);
}
void Ball::update()
{
    shape.move(speed);
    if(shape.getPosition().x - BALL_RADIUS < 0)
        speed.x = BALL_SPEED;
    else if(shape.getPosition().x + BALL_RADIUS > WINDOW_WIDTH)
        speed.x = -BALL_SPEED;
    if(shape.getPosition().y - BALL_RADIUS < 0)
        speed.y = BALL_SPEED;
    else if(shape.getPosition().y + BALL_RADIUS > WINDOW_HEIGHT)
        speed.y = -BALL_SPEED;
}

CircleShape Ball::getCircle() const
{
    return shape;
}

Platform::Platform(float dx, float dy)
{
    shape.setPosition(dx, dy);
    shape.setSize({PLATFORM_WIDTH,PLATFORM_HEIGHT});
    shape.setOrigin(PLATFORM_WIDTH/2.f, PLATFORM_HEIGHT/2.f);
    shape.setFillColor(Color::Green);

}

RectangleShape Platform::getPlatform() const
{
    return shape;
}

void Platform::update()
{
    shape.move(speed);
    if(Keyboard::isKeyPressed(Keyboard::Key::Left) &&
            (shape.getPosition().x - shape.getSize().x / 2.f) > 0)
    {
        speed.x = -PLATFORM_SPEED;
    }
    else if(Keyboard::isKeyPressed(Keyboard::Key::Right) &&
            (shape.getPosition().x + shape.getSize().x / 2.f) < WINDOW_WIDTH)
    {
        speed.x = PLATFORM_SPEED;
    }
    else speed.x = 0;


}
