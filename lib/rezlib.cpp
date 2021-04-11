#include "rezlib.hpp"

Window::Window()
{
    window = new sf::RenderWindow;
    std::cout << "[Window] -->" << std::hex << window << std::endl;
    std::cout << "[Window] is created!" << std::endl;
}

Window::~Window()
{
    if (window)
        delete window;
}

void Window::update()
{
    window->display();
    window->clear();
}

void Window::setup(sf::VideoMode videoMode, std::string name)
{
    std::cout << "[Window] Setting up..." << std::endl;
    window->create(videoMode, name);
    std::cout << "[Window] Res : " << window->getSize().x << "x" << window->getSize().y << std::endl;
    std::cout << "[Window] Title : " << name << std::endl;
    std::cout << "[Window] is modfied!" << std::endl;
}

KeyBoard::KeyBoard()
{
    window = NULL;
}

KeyBoard::~KeyBoard()
{

}

void KeyBoard::released()
{
    
}

void KeyBoard::pressed()
{

}

Event::Event()
{
    event = new sf::Event;
    function = NULL;
    std::cout << "[Event] -->" << std::hex << event << std::endl;
    std::cout << "[Event] Event is created!" << std::endl;
}

Event::~Event()
{
    if (event)
        delete event;
}

void Event::update()
{
    window->pollEvent(*event);
    process();
}

void Event::process()
{
    switch (event->type)
    {
    case sf::Event::Closed:
        window->close();
        std::cout << "[Event] Window is closing.." << std::endl;
        break;
    case sf::Event::KeyPressed:
        break;
    case sf::Event::KeyReleased:
        break;
    }
}

void ShapeDraw::draw()
{
    for (sf::Shape *object : *this)
        window->draw(*object);
}

sf::CircleShape &ShapeDraw::circle(size_t x)
{
    if (x == -1)
        return *(sf::CircleShape *)back();
    else
        return *(sf::CircleShape *)at(x);
}

sf::ConvexShape &ShapeDraw::convex(size_t x)
{
    if (x == -1)
        return *(sf::ConvexShape *)back();
    else
        return *(sf::ConvexShape *)at(x);
}

sf::RectangleShape &ShapeDraw::rectangle(size_t x)
{
    if (x == -1)
        return *(sf::RectangleShape *)back();
    else
        return *(sf::RectangleShape *)at(x);
}

System::System()
{
    ShapeDraw::window = Event::window = Window::window;
    Window::setup(sf::VideoMode(1280, 720), "NULL");
}

System::~System()
{
}

void System::update()
{
    while (Window::window->isOpen())
    {
        Event::update();
        ShapeDraw::draw();
        Window::update();
    }
}
