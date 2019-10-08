#include "Projector.h"

Object2D Projector::projectObject(Camera* camera, Object3D* obj3d)
{
    Object2D obj2d;

    for(LineSeg<Vector3D>& ls : obj3d->lineSegments)
    {
        obj2d.addLineSeg(LineSeg<Vector2D>( projectPointToWindow(camera, ls.pt_a), projectPointToWindow(camera, ls.pt_b), ls.color ));
    }
    return obj2d;
}

Vector3D Projector::projectPointSpatially(Camera* camera, Vector3D& pt)
{
    Vector3D& planeNormal = camera->direction;
    Vector3D rayVector = pt - camera->pos;
	Vector3D diff = pt - camera->getPlanePoint();

	double prod1 = diff.dot(planeNormal);
	double prod2 = rayVector.dot(planeNormal);
	double prod3 = prod1 / prod2;
	return pt - rayVector * prod3;
}

Vector2D Projector::projectPointToWindow(Camera* camera, Vector3D& pt)
{
    Vector3D virtual_pt = projectPointSpatially(camera, pt);
    Vector3D relative_pt = virtual_pt - camera->get_vw_origin();
    Vector2D projectedPt;

    projectedPt.x = relative_pt.dot(camera->virtual_x_axis.unitVector()) * camera->scaler.x;
    projectedPt.y = relative_pt.dot(camera->virtual_y_axis.unitVector()) * camera->scaler.y;
    return projectedPt;
}