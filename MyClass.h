#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace sf;

constexpr int WINDOW_WIDTH      = 800;
constexpr int WINDOW_HEIGHT     = 600;
constexpr float BALL_RADIUS     = 10.f;
constexpr float BALL_SPEED      = 5.f;
constexpr float PLATFORM_WIDTH  = 100.f;
constexpr float PLATFORM_HEIGHT = 20.f;
constexpr float PLATFORM_SPEED  = 8.f;
constexpr float BRICK_WIDTH     = 60.f;
constexpr float BRICK_HEIGHT    = 20.f;
constexpr int BRICKS_X          = 8;
constexpr int BRICKS_Y          = 4;


class Ball
{
private:
    CircleShape shape;
    Vector2f speed = {BALL_SPEED, -BALL_SPEED};
public:
    CircleShape& getShape() { return this->shape; }
    Vector2f& getSpeed()  { return this->speed; }
    Ball(float dx, float dy);
    void update(RenderWindow &window);
    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getRadius(); }
    float right() { return x() + shape.getRadius(); }
    float up() { return y() - shape.getRadius(); }
    float down() { return y() + shape.getRadius(); }
};

class Rectangle
{
protected:
    RectangleShape shape;
public:
    RectangleShape& getShape()  { return this->shape; }
    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getSize().x / 2.f; }
    float right() { return x() + shape.getSize().x / 2.f ; }
    float up() { return y() - shape.getSize().y / 2.f; }
    float down() { return y() + shape.getSize().y / 2.f; }
};

class Brick:public Rectangle
{
private:
    bool isDestroyed = false;
public:
    Brick(float dx, float dy);
    bool& getIsDestroyed() { return isDestroyed;}
};

class Platform:public Rectangle
{
private:
    Vector2f speed;
public:
    Platform(float dx, float dy);
    Vector2f& getSpeed() { return this->speed; }
    void update();
};



bool isIntersecting(class A& obj1, class B& obj2);
void testIntersection(Platform& platf, Ball &ball);
void testIntersection(Brick& brick, Ball& ball);
