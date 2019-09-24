#include "Projector.h"

Object2D Projector::projectObject(Camera* camera, Object3D* renderable)
{
    Object2D obj2d;
    obj2d.addLineSeg( std::pair<Vector2D, Vector2D>( Vector2D(50, 50), Vector2D(300, 20)) );
    obj2d.addLineSeg( std::pair<Vector2D, Vector2D>( Vector2D(500, 50), Vector2D(300, 600)) );
    obj2d.addLineSeg( std::pair<Vector2D, Vector2D>( Vector2D(600, 600), Vector2D(650, 600)) );
    return obj2d;
}