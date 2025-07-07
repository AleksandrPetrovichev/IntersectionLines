#include <cmath>
#include "Vectors.hpp"

class Line
{
public:
    Line() : direction(Vector3(0, 0, 0)), point(Vector3(0, 0, 0)) {}
    Line(const Vector3& v, const Vector3& p) : direction(v), point(p) {}    
    Line(const Vector2& v, const Vector2& p);                               
    Line(float k, float b);                                     
    ~Line() = default; 
    Line(const Line&) = default; 
    Line& operator=(const Line&) = default;

    void set(const Vector3& v, const Vector3& p);              
    void set(const Vector2& v, const Vector2& p);              
    void set(float k, float b);                    
    void setPoint(Vector3& p) { point = p; }
    void setDirection(const Vector3& v) { direction = v; }
    const Vector3& getPoint() const { return point; }
    const Vector3& getDirection() const { return direction; }
    void printSelf();

    Vector3 intersect(const Line& line);
    bool isIntersected(const Line& line);

private:
    Vector3 direction;
    Vector3 point;
};
