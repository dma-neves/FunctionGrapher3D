#ifndef FUNCTION_GRAPHER
#define FUNCTION_GRAPHER

#include <vector>
#include <SFML/Graphics.hpp>

#include "Projector.h"

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
    std::vector<LineSeg> lineSegs;
    std::vector<LineSeg> projectedLineSegs;

    sf::RenderWindow window;
    sf::Clock clock;
};

#endif