#include <iostream>
#include "Line.hpp"
#include <optional>
using namespace std;


Line::Line(float k, float b)
{
    set(k, b);
}



Line::Line(const Vector2& direction, const Vector2& point)
{
    set(direction, point);
}



void Line::set(const Vector3& v, const Vector3& p)
{
    this->direction = v;
    this->point = p;
}

void Line::set(const Vector2& v, const Vector2& p)
{
    // convert 2D to 3D
    this->direction = Vector3(v.x, v.y, 0);
    this->point = Vector3(p.x, p.y, 0);
}

void Line::set(float k, float b)
{
    // convert k-b form (2D) to parametric form (3D)
    this->direction = Vector3(1, k, 0);
    this->point = Vector3(0, b, 0);
}



// debug
void Line::printSelf()
{
    cout << "Line\n"
        << "====\n"
        << "Direction: " << this->direction << "\n"
        << "    Point: " << this->point << endl;
}



// Line1 = p1 + aV1 
// Line2 = p2 + bV2 
//
// Intersect:
// p1 + aV1 = p2 + bV2
//      aV1 = (p2-p1) + bV2
//   aV1xV2 = (p2-p1)xV2
//        a = (p2-p1)xV2 / (V1xV2)
//        a = ((p2-p1)xV2).(V1xV2) / (V1xV2).(V1xV2)
Vector3 Line::intersect(const Line& line)
{
    const Vector3 v2 = line.getDirection();
    const Vector3 p2 = line.getPoint();
    Vector3 result = Vector3(NAN, NAN, NAN); 

    // find v3 = (p2 - p1) x V2
    Vector3 v3 = (p2 - point).cross(v2);

    // find v4 = V1 x V2
    Vector3 v4 = direction.cross(v2);

    // find (V1xV2) . (V1xV2)
    float dot = v4.dot(v4);

    // if both V1 and V2 are same direction, return NaN point
    if (dot == 0)
        return result;

    // find a = ((p2-p1)xV2).(V1xV2) / (V1xV2).(V1xV2)
    float alpha = v3.dot(v4) / dot;

    
    
    

    result = point + (alpha * direction);
    return result;
}



bool Line::isIntersected(const Line& line)
{
    Vector3 v = this->direction.cross(line.getDirection());
    if (v.x == 0 && v.y == 0 && v.z == 0)
        return false;
    else
        return true;
}

