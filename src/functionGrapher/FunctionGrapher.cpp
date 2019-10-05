#include "FunctionGrapher.h"

#include <iostream>

#define PT_A 0,-5,0
#define PT_B 5,5,0
#define PT_C -5,20,0
#define PT_D 0,0,20

FunctionGrapher::FunctionGrapher(int windowWidth, int windowHeight, std::string windowTitle) :
window(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close),
camera(Vector3D(20, 0, 5), 60, Vector2D(20, 20), Vector2D(windowWidth, windowHeight))
{
    //Create 3D Object
    obj3d.addLineSeg(std::pair<Vector3D, Vector3D>(Vector3D(PT_A), Vector3D(PT_B)));
    obj3d.addLineSeg(std::pair<Vector3D, Vector3D>(Vector3D(PT_B), Vector3D(PT_C)));
    obj3d.addLineSeg(std::pair<Vector3D, Vector3D>(Vector3D(PT_C), Vector3D(PT_A)));
    obj3d.addLineSeg(std::pair<Vector3D, Vector3D>(Vector3D(PT_A), Vector3D(PT_D)));
    obj3d.addLineSeg(std::pair<Vector3D, Vector3D>(Vector3D(PT_B), Vector3D(PT_D)));
    obj3d.addLineSeg(std::pair<Vector3D, Vector3D>(Vector3D(PT_C), Vector3D(PT_D)));
}

void FunctionGrapher::run()
{
    while (isRunning)
    {
        float dt = clock.restart().asSeconds() * DT_MULTIPLIER;;

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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) camera.pos += camera.direction*dt;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) camera.pos -= camera.direction*dt;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Vector3D aux = camera.virtual_x_axis;
        aux.setMagnitude(3);
        camera.pos += aux*dt;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Vector3D aux = camera.virtual_x_axis;
        aux.setMagnitude(3);
        camera.pos += aux*-dt;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Vector3D aux = camera.virtual_y_axis;
        aux.setMagnitude(3);
        camera.pos += aux*-dt;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Vector3D aux = camera.virtual_y_axis;
        aux.setMagnitude(3);
        camera.pos += aux*dt;
    }
}