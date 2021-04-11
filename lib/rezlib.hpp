#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Base
{
protected:
    sf::RenderWindow *window;

public:
    Base();
};

class KeyBoard : protected Base
{
protected:
    KeyFunction *function;

public:
    KeyBoard();
    ~KeyBoard();
    void released();
    void pressed();
};

class KeyFunction
{
protected:
    virtual void up() = 0;
    virtual void down() = 0;
    virtual void right() = 0;
    virtual void left() = 0;
};

class Window : protected Base
{
protected:
    void update();
    void setup(sf::VideoMode videoMode, std::string name);

public:
    Window();
    ~Window();
};

class Event : protected KeyBoard
{
private:
    void process();

protected:
    sf::Event *event;
    sf::RenderWindow *window;
    void update();

public:
    Event();
    ~Event();
};

class ShapeDraw : public std::vector<sf::Shape *>, protected Base
{
protected:
public:
    void draw();
    sf::CircleShape &circle(size_t x = -1);
    sf::ConvexShape &convex(size_t x = -1);
    sf::RectangleShape &rectangle(size_t x = -1);
};

class System : protected Window, protected Event, protected ShapeDraw
{
private:
    void config();

public:
    System();
    ~System();
    void update();
};

//===========================
