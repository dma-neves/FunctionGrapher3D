#ifndef PROJECTOR
#define PROJECTOR

#include <vector>

#include "Camera.h"
#include "LineSeg.h"

class Projector
{
public:
    static std::vector<LineSeg> getProjectedLineSegs(Camera* camera, std::vector<LineSeg>* lineSegs);
};

#endif