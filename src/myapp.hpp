#pragma once
#include <rezlib.hpp>

class Circle : public KeyFunction, public sf::CircleShape
{
private:
    sf::Vector2f position, speed;
protected:
    void up(), down(), right(), left();
    void update();
public:
    Circle();
    ~Circle();
    void setPosition(float x, float y);
    void setSpeed(float vx, float vy);
};

class MyApplication : private System
{
private:
    void config();
public:
    MyApplication();
    ~MyApplication();
    void run();
};