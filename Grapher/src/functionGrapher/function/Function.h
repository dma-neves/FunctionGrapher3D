#ifndef FUNCTION
#define FUNCTION

#define PARAMETES_FILE_PATH "../../Expression/parameters.txt"

#include <fstream>

#include "Object.h"
#include "Expression.h"

class Function
{
public:
    Function();
    Function(float spacing, int range) { update(spacing, range); }

    void update(float spacing, int range);

    Object3D obj = Object3D();
};

#endif