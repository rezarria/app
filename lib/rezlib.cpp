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

    default:
        break;
    }
}

System::System()
{
    ObjectDraw::window = Event::window = Window::window;
    Window::setup(sf::VideoMode(1280, 720), "NULL");
}

System::~System()
{}

void System::update()
{
    while (Window::window->isOpen())
    {
        Window::update();
        Event::update();
    }
}

Circle::Circle()
{
    std::cout << "[Circle] is created!" << std::endl;
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

void test()
{
    std::cout << "FFF" << std::endl;
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
    ObjectDraw::resize(1);
    Circle* circle = &ObjectDraw::vector::back();
    //circle.setPosition(630, 360);
    //circle.setFillColor(sf::Color::Green);
    //circle.setRadius(10.0f);
}

void ObjectDraw::draw()
{
    for (sf::Drawable* obj ::* this)
        window->draw(*obj);
}