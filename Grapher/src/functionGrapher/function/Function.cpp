#include "Function.h"

Function::Function()
{
    std::ifstream parameters(PARAMETES_FILE_PATH);
    if(parameters.is_open())
    {
        float spacing;
        int range;
        parameters >> spacing;
        parameters >> range;
        update(spacing, range);
        parameters.close();
    }
    else std::cout << "Error: Unable to open parameters file" << std::endl;
}

void Function::update(float spacing, int range)
{
    obj = Object3D();
    float size = spacing * (float)range;

    for(float y_0 = -size/2.0f; y_0 <= size/2.0f; y_0 += spacing)
    {
        for(float x_0 = -size/2.0f; x_0 < size/2.0f; x_0 += spacing)
        {
            float y = y_0;
            float x = x_0;
            float z = EXPRESSION;
            Vector3D vec_0(x,y,z);
            x += spacing;
            z = EXPRESSION;
            Vector3D vec_1(x,y,z);
            obj.addLineSeg(LineSeg<Vector3D>(vec_0, vec_1));

        }
    }

    for(float x_0 = -size/2.0f; x_0 <= size/2.0f; x_0 += spacing)
    {
        for(float y_0 = -size/2.0f; y_0 < size/2.0f; y_0 += spacing)
        {
            float x = x_0;
            float y = y_0;
            float z = EXPRESSION;
            Vector3D vec_0(x,y,z);
            y += spacing;
            z = EXPRESSION;
            Vector3D vec_1(x,y,z);
            obj.addLineSeg(LineSeg<Vector3D>(vec_0, vec_1));
        }
    }
}