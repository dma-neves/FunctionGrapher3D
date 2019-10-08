#include "FunctionGrapher.h"

#include <iostream>

#define PT_A 0,-5,0
#define PT_B 5,5,0
#define PT_C -5,5,0
#define PT_D 0,0,5

FunctionGrapher::FunctionGrapher(int windowWidth, int windowHeight, std::string windowTitle) :
window(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close),
camera(60, Vector2D(20, 20), Vector2D(windowWidth, windowHeight))
{
    //Create 3D Object
    obj3d.addLineSeg(LineSeg<Vector3D>(Vector3D(0,0,0), Vector3D(10,0,0), sf::Color::Red));
    obj3d.addLineSeg(LineSeg<Vector3D>(Vector3D(0,0,0), Vector3D(0,10,0), sf::Color::Red));
    obj3d.addLineSeg(LineSeg<Vector3D>(Vector3D(0,0,0), Vector3D(0,0,10), sf::Color::Red));


    obj3d.addLineSeg(LineSeg<Vector3D>(Vector3D(PT_A), Vector3D(PT_B)));
    obj3d.addLineSeg(LineSeg<Vector3D>(Vector3D(PT_B), Vector3D(PT_C)));
    obj3d.addLineSeg(LineSeg<Vector3D>(Vector3D(PT_C), Vector3D(PT_A)));
    obj3d.addLineSeg(LineSeg<Vector3D>(Vector3D(PT_A), Vector3D(PT_D)));
    obj3d.addLineSeg(LineSeg<Vector3D>(Vector3D(PT_B), Vector3D(PT_D)));
    obj3d.addLineSeg(LineSeg<Vector3D>(Vector3D(PT_C), Vector3D(PT_D)));
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

    for(LineSeg<Vector2D>& lineSeg : obj2d.lineSegments)
    {
        sf::VertexArray line(sf::LinesStrip, 2);
        line[0].position = lineSeg.pt_a.sfVector();
        line[0].color  = lineSeg.color;
        line[1].position = lineSeg.pt_b.sfVector();
        line[1].color = lineSeg.color;

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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) camera.moveStraight(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) camera.moveStraight(-dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) camera.moveHorizontal(3*dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) camera.moveHorizontal(-3*dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) camera.moveVertical(3*dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) camera.moveVertical(-3*dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) camera.rotateVertically(-M_PI/24*dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) camera.rotateVertically(M_PI/24*dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) camera.rotateHorizontally(M_PI/24*dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) camera.rotateHorizontally(-M_PI/24*dt);
}