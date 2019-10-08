#ifndef FUNCTION_GRAPHER
#define FUNCTION_GRAPHER

#include <vector>
#include <SFML/Graphics.hpp>

#define DT_MULTIPLIER 3

#include "Projector.h"
#include "Object.h"

class FunctionGrapher
{
public:
    FunctionGrapher(int windowWidth, int windowHeight, std::string windowTitle);

    void run();
    void handleEvents(float dt);

private:
    void update();
    void render();

    bool isRunning = true;
    Camera camera;
    Object3D obj3d;
    Object2D obj2d;

    sf::RenderWindow window;
    sf::Clock clock;
};

#endif