#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
void test();

class ObjectDraw : public std::vector<sf::Drawable>
{
private:
protected:
    sf::RenderWindow *window;
public:
    void draw();
};

class KeyFunction
{
protected:
    virtual void up() = 0;
    virtual void down() = 0;
    virtual void right() = 0;
    virtual void left() = 0;
};

class Window
{
protected:
    sf::RenderWindow* window;
    void update();
    void setup(sf::VideoMode videoMode, std::string name);
public:
    Window();
    ~Window();
};

class Event
{
private:
    void process();
protected:
    KeyFunction* function;
    sf::Event* event;
    sf::RenderWindow* window;
    void update();
public:
    Event();
    ~Event();
};

class System : protected Window, protected Event, protected ObjectDraw
{
private:
    void config();
public:
    System();
    ~System();
    void update();
};

//===========================
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