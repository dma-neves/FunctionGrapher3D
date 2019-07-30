#include "FunctionGrapher.h"

#include <iostream>

FunctionGrapher::FunctionGrapher(int windowWidth, int windowHeight, std::string windowTitle) :
window(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close), camera(Vector2D(), Vector2D())
{
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
    projectedLineSegs = Projector::getProjectedLineSegs(&camera, &lineSegs);
}

void FunctionGrapher::render()
{
    window.clear();

    for(LineSeg& lineSeg : projectedLineSegs)
    {
        sf::VertexArray line(sf::LinesStrip, 2);
        line[0].position = lineSeg.point[0].sfVector();
        line[0].color  = sf::Color::White;
        line[1].position = lineSeg.point[1].sfVector();
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