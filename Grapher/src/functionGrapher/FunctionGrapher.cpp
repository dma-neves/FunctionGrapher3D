#include "FunctionGrapher.h"

#include <iostream>

FunctionGrapher::FunctionGrapher(int windowWidth, int windowHeight, std::string windowTitle) :
window(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close),
camera(60, Vector2D(20, 20), Vector2D(windowWidth, windowHeight))
{
    axis.addLineSeg(LineSeg<Vector3D>(Vector3D(-10,0,0), Vector3D(10,0,0), sf::Color::Red));
    axis.addLineSeg(LineSeg<Vector3D>(Vector3D(10,0,0), Vector3D(9,1,0), sf::Color::Green));
    axis.addLineSeg(LineSeg<Vector3D>(Vector3D(10,0,0), Vector3D(9,-1,0), sf::Color::Green));

    axis.addLineSeg(LineSeg<Vector3D>(Vector3D(0,-10,0), Vector3D(0,10,0), sf::Color::Red));
    axis.addLineSeg(LineSeg<Vector3D>(Vector3D(0,10,0), Vector3D(1,9,0), sf::Color::Green));
    axis.addLineSeg(LineSeg<Vector3D>(Vector3D(0,10,0), Vector3D(-1,9,0), sf::Color::Green));

    axis.addLineSeg(LineSeg<Vector3D>(Vector3D(0,0,-10), Vector3D(0,0,10), sf::Color::Red));
    axis.addLineSeg(LineSeg<Vector3D>(Vector3D(0,0,10), Vector3D(1,-1,9), sf::Color::Green));
    axis.addLineSeg(LineSeg<Vector3D>(Vector3D(0,0,10), Vector3D(-1,1,9), sf::Color::Green));
}

void FunctionGrapher::run()
{
    while (isRunning)
    {
        float dt = clock.restart().asSeconds() * DT_MULTIPLIER;

        update();
        render();
        handleEvents(dt);
    }
}

void FunctionGrapher::update()
{
    axis_obj2d = Projector::projectObject(&camera, &axis);
    func_obj2d = Projector::projectObject(&camera, &func.obj);
}

void FunctionGrapher::render()
{
    window.clear();

    for(LineSeg<Vector2D>& lineSeg : func_obj2d.lineSegments) renderLineSeg(lineSeg);
    for(LineSeg<Vector2D>& lineSeg : axis_obj2d.lineSegments) renderLineSeg(lineSeg);

    window.display();
}

void FunctionGrapher::renderLineSeg(LineSeg<Vector2D>& lineSeg)
{
        sf::VertexArray line(sf::LinesStrip, 2);
        line[0].position = lineSeg.pt_a.sfVector();
        line[0].color  = lineSeg.color;
        line[1].position = lineSeg.pt_b.sfVector();
        line[1].color = lineSeg.color;

        window.draw(line);
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) camera.moveStraight(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) camera.moveStraight(-dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) camera.rotateVertically(-M_PI/6*dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) camera.rotateVertically(M_PI/6*dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) camera.rotateAround_z(-M_PI/6*dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) camera.rotateAround_z(M_PI/6*dt);
}