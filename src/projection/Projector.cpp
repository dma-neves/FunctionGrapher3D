#include "Projector.h"

std::vector<LineSeg> Projector::getProjectedLineSegs(Camera* camera, std::vector<LineSeg>* lineSegs)
{
    std::vector<LineSeg> projectedLineSegs;
    projectedLineSegs.push_back(LineSeg(Vector2D(10, 10), Vector2D(500, 20)));
    projectedLineSegs.push_back(LineSeg(Vector2D(200, 200), Vector2D(10, 300)));

    return projectedLineSegs;
}