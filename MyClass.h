#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

constexpr int WINDOW_WIDTH      = 800;
constexpr int WINDOW_HEIGHT     = 600;
constexpr float BALL_RADIUS     = 10.f;
constexpr float BALL_SPEED      = 5.f;
constexpr float PLATFORM_WIDTH  = 60.f;
constexpr float PLATFORM_HEIGHT = 20.f;
constexpr float PLATFORM_SPEED  = 8.f;


class Ball
{
private:
    CircleShape shape;
    Vector2f speed = {BALL_SPEED,-BALL_SPEED};
public:
    CircleShape getCircle() const;
    Ball(float dx, float dy);
    void update();
};

class Platform
{
private:
    RectangleShape shape;
    Vector2f speed;
public:
    Platform(float dx, float dy);
    RectangleShape getPlatform() const;

};
