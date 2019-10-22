#ifndef FUNCTION_GRAPHER
#define FUNCTION_GRAPHER

#include <vector>
#include <SFML/Graphics.hpp>

#define DT_MULTIPLIER 3

#include "Projector.h"
#include "Function.h"

class FunctionGrapher
{
public:
    FunctionGrapher(int windowWidth, int windowHeight, std::string windowTitle);

    void run();
    void handleEvents(float dt);

private:
    void update();
    void render();
    void renderLineSeg(LineSeg<Vector2D>& lineSeg);

    bool isRunning = true;
    Camera camera;
    Object3D axis;
    Object2D axis_obj2d;
    Function func;
    Object2D func_obj2d;

    sf::RenderWindow window;
    sf::Clock clock;
};

#endif