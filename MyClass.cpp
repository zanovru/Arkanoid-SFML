#include "MyClass.h"

Ball::Ball(float dx, float dy)
{
    shape.setPosition(dx,dy);
    shape.setRadius(BALL_RADIUS);
    shape.setFillColor(Color::Magenta);
    shape.setOrigin(BALL_RADIUS,BALL_RADIUS);
}
void Ball::update(RenderWindow &window)
{
    shape.move(speed);
    if(left() < 0)
        speed.x = BALL_SPEED;
    else if(right() > WINDOW_WIDTH)
        speed.x = -BALL_SPEED;
    if(up() < 0)
        speed.y = BALL_SPEED;
    if(down() > WINDOW_HEIGHT)
    {
        window.close();
        emit lose();

    }
}

Platform::Platform(float dx, float dy)
{
    shape.setPosition(dx, dy);
    shape.setSize({PLATFORM_WIDTH,PLATFORM_HEIGHT});
    shape.setOrigin(PLATFORM_WIDTH/2.f, PLATFORM_HEIGHT/2.f);
    shape.setFillColor(Color::Green);

}

void Platform::update()
{
    shape.move(speed);
    if(Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
        speed.x = -PLATFORM_SPEED;
    else if(Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < WINDOW_WIDTH)
        speed.x = PLATFORM_SPEED;
    else speed.x = 0;


}

Brick::Brick(float dx, float dy)
{
    shape.setPosition(dx, dy);
    shape.setSize({BRICK_WIDTH, BRICK_HEIGHT});
    shape.setOrigin(BRICK_WIDTH/2.f, BRICK_HEIGHT/2.f);
    shape.setFillColor(Color::Blue);

}



template <class T1, class T2>
bool isIntersecting(T1& obj1, T2& obj2)
{
    return obj1.left() <= obj2.right() && obj1.right() >= obj2.left()
            && obj1.down() >= obj2.up() && obj1.up() <= obj2.down();
}

void testIntersection(Platform& platf, Ball& ball)
{
    if(!isIntersecting(platf, ball)) return;
    ball.getSpeed().y = -BALL_SPEED;
    if(platf.x() > ball.x())
        ball.getSpeed().x = -BALL_SPEED;
    else ball.getSpeed().x = BALL_SPEED;

}

void testIntersection(Brick& brick, Ball& ball)
{
    if(!isIntersecting(brick, ball)) return;
    brick.getIsDestroyed() = true;
    float intersectLeft = ball.right() - brick.left();
    float intersectRight = brick.right() - ball.left();
    float intersectTop = ball.down() - brick.up();
    float intersectDown = brick.down() - ball.up();
    bool ballFromLeft = abs(intersectLeft) < abs(intersectRight);
    bool ballFromTop = abs(intersectTop) < abs(intersectDown);
    float minIntersectX = ballFromLeft ? intersectLeft : intersectRight;
    float minIntersectY = ballFromTop ? intersectTop : intersectDown;
    if (abs(minIntersectX) < abs(minIntersectY))
        ball.getSpeed().x = ballFromLeft ? -BALL_SPEED : BALL_SPEED;
    else
        ball.getSpeed().y = ballFromTop ? -BALL_SPEED : BALL_SPEED;

}
