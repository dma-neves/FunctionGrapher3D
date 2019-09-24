#include "FunctionGrapher.h"

#include <iostream>

FunctionGrapher::FunctionGrapher(int windowWidth, int windowHeight, std::string windowTitle) :
window(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close), camera(Vector3D(), Vector3D())
{
    //Create 3D Object
}

void FunctionGrapher::run()
{
    while (isRunning)
    {
        float dt;

        update();
        render();
        handleEvents(dt);
    }
}

void FunctionGrapher::update()
{
    obj2d = Projector::projectObject(&camera, &obj3d);
}

void FunctionGrapher::render()
{
    window.clear();

    for(std::pair<Vector2D, Vector2D>& lineSeg : obj2d.lineSegments)
    {
        sf::VertexArray line(sf::LinesStrip, 2);
        line[0].position = lineSeg.first.sfVector();
        line[0].color  = sf::Color::White;
        line[1].position = lineSeg.second.sfVector();
        line[1].color = sf::Color::White;

        window.draw(line);
    }

    window.display();
}

void FunctionGrapher::handleEvents(float dt)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            isRunning = false;
            window.close();
        }
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        isRunning = false;
        window.close();
    }
}