#include "myapp.hpp"

Circle::Circle()
{
    std::cout << "[Circle] is created!" << std::endl;
}

Circle::~Circle()
{
}

void Circle::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void Circle::setSpeed(float vx, float vy)
{
    speed.x = vx;
    speed.y = vy;
}

void Circle::update()
{
    CircleShape::setPosition(position);
    std::cout << "[Circle]'s position is updated!" << std::endl;
}

void Circle::up()
{
    position.y += speed.y;
}

void Circle::down()
{
    position.y -= speed.y;
}

void Circle::right()
{
    position.x += speed.x;
}

void Circle::left()
{
    position.x -= speed.y;
}

MyApplication::MyApplication()
{
    config();
    std::cout << "[APP] is created!" << std::endl;
}

MyApplication::~MyApplication()
{
    std::cout << "[APP] is destroy!" << std::endl;
}

void MyApplication::config()
{
}

void MyApplication::run()
{
    System::update();
}
