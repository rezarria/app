#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


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

class System : protected Window, protected Event
{
private:
    void config();
public:
    System();
    ~System();
    void update();
};

//===========================
