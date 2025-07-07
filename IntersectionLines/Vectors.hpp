#include <cmath>
#include <iostream>
using namespace std;
struct Vector2
{
    float x;
    float y;

    Vector2() : x(0), y(0) {};
    Vector2(float x, float y) : x(x), y(y) {};

    Vector2& set(float x, float y);
    float       length() const;                         
    float       distance(const Vector2& vec) const;     
    Vector2& normalize();                            
    float       dot(const Vector2& vec) const;          
    bool        equal(const Vector2& vec, float e) const;

    Vector2     operator-() const;                   
    Vector2     operator+(const Vector2& rhs) const; 
    Vector2     operator-(const Vector2& rhs) const; 
    Vector2& operator+=(const Vector2& rhs);         
    Vector2& operator-=(const Vector2& rhs);         
    Vector2     operator*(const float scale) const;  
    Vector2     operator*(const Vector2& rhs) const; 
    Vector2& operator*=(const float scale);          
    Vector2& operator*=(const Vector2& rhs);         
    Vector2     operator/(const float scale) const;  
    Vector2& operator/=(const float scale);          
    bool        operator==(const Vector2& rhs) const;
    bool        operator!=(const Vector2& rhs) const;
    bool        operator<(const Vector2& rhs) const; 
    float       operator[](int index) const;         
    float& operator[](int index);                  

    friend Vector2 operator*(const float a, const Vector2 vec);
    friend ostream& operator<<(ostream& os, const Vector2& vec);
};

struct Vector3
{
    float x;
    float y;
    float z;

    Vector3() : x(0), y(0), z(0) {};
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {};

    Vector3& set(float x, float y, float z);
    float       length() const;                         
    float       distance(const Vector3& vec) const;     
    float       angle(const Vector3& vec) const;        
    Vector3& normalize();                            
    float       dot(const Vector3& vec) const;          
    Vector3     cross(const Vector3& vec) const;        
    bool        equal(const Vector3& vec, float e) const; 

    Vector3     operator-() const;                   
    Vector3     operator+(const Vector3& rhs) const; 
    Vector3     operator-(const Vector3& rhs) const; 
    Vector3& operator+=(const Vector3& rhs);         
    Vector3& operator-=(const Vector3& rhs);         
    Vector3     operator*(const float scale) const;  
    Vector3     operator*(const Vector3& rhs) const; 
    Vector3& operator*=(const float scale);          
    Vector3& operator*=(const Vector3& rhs);         
    Vector3     operator/(const float scale) const;  
    Vector3& operator/=(const float scale);          
    bool        operator==(const Vector3& rhs) const;
    bool        operator!=(const Vector3& rhs) const;
    bool        operator<(const Vector3& rhs) const; 
    float       operator[](int index) const;         
    float& operator[](int index);                  

    friend Vector3 operator*(const float a, const Vector3 vec);
    friend ostream& operator<<(ostream& os, const Vector3& vec);
};



inline Vector2 Vector2::operator-() const {
    return Vector2(-x, -y);
}

inline Vector2 Vector2::operator+(const Vector2& rhs) const {
    return Vector2(x + rhs.x, y + rhs.y);
}

inline Vector2 Vector2::operator-(const Vector2& rhs) const {
    return Vector2(x - rhs.x, y - rhs.y);
}

inline Vector2& Vector2::operator+=(const Vector2& rhs) {
    x += rhs.x; y += rhs.y; return *this;
}

inline Vector2& Vector2::operator-=(const Vector2& rhs) {
    x -= rhs.x; y -= rhs.y; return *this;
}

inline Vector2 Vector2::operator*(const float a) const {
    return Vector2(x * a, y * a);
}

inline Vector2 Vector2::operator*(const Vector2& rhs) const {
    return Vector2(x * rhs.x, y * rhs.y);
}

inline Vector2& Vector2::operator*=(const float a) {
    x *= a; y *= a; return *this;
}

inline Vector2& Vector2::operator*=(const Vector2& rhs) {
    x *= rhs.x; y *= rhs.y; return *this;
}

inline Vector2 Vector2::operator/(const float a) const {
    return Vector2(x / a, y / a);
}

inline Vector2& Vector2::operator/=(const float a) {
    x /= a; y /= a; return *this;
}

inline bool Vector2::operator==(const Vector2& rhs) const {
    return (x == rhs.x) && (y == rhs.y);
}

inline bool Vector2::operator!=(const Vector2& rhs) const {
    return (x != rhs.x) || (y != rhs.y);
}

inline bool Vector2::operator<(const Vector2& rhs) const {
    if (x < rhs.x) return true;
    if (x > rhs.x) return false;
    if (y < rhs.y) return true;
    if (y > rhs.y) return false;
    return false;
}

inline float Vector2::operator[](int index) const {
    return (&x)[index];
}

inline float& Vector2::operator[](int index) {
    return (&x)[index];
}

inline Vector2& Vector2::set(float x, float y) {
    this->x = x; this->y = y; return *this;
}

inline float Vector2::length() const {
    return sqrtf(x * x + y * y);
}

inline float Vector2::distance(const Vector2& vec) const {
    return sqrtf((vec.x - x) * (vec.x - x) + (vec.y - y) * (vec.y - y));
}

inline Vector2& Vector2::normalize() {
    float xxyy = x * x + y * y;
    float invLength = 1 / sqrtf(xxyy);
    x *= invLength;
    y *= invLength;
    return *this;
}

inline float Vector2::dot(const Vector2& rhs) const {
    return (x * rhs.x + y * rhs.y);
}

inline bool Vector2::equal(const Vector2& rhs, float epsilon) const {
    return fabs(x - rhs.x) < epsilon && fabs(y - rhs.y) < epsilon;
}

inline Vector2 operator*(const float a, const Vector2 vec) {
    return Vector2(a * vec.x, a * vec.y);
}

inline ostream& operator<<(ostream& os, const Vector2& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}
///////////////////////////////////////////////////////////////

inline Vector3 Vector3::operator-() const {
    return Vector3(-x, -y, -z);
}

inline Vector3 Vector3::operator+(const Vector3& rhs) const {
    return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

inline Vector3 Vector3::operator-(const Vector3& rhs) const {
    return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

inline Vector3& Vector3::operator+=(const Vector3& rhs) {
    x += rhs.x; y += rhs.y; z += rhs.z; return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& rhs) {
    x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this;
}

inline Vector3 Vector3::operator*(const float a) const {
    return Vector3(x * a, y * a, z * a);
}

inline Vector3 Vector3::operator*(const Vector3& rhs) const {
    return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
}

inline Vector3& Vector3::operator*=(const float a) {
    x *= a; y *= a; z *= a; return *this;
}

inline Vector3& Vector3::operator*=(const Vector3& rhs) {
    x *= rhs.x; y *= rhs.y; z *= rhs.z; return *this;
}

inline Vector3 Vector3::operator/(const float a) const {
    return Vector3(x / a, y / a, z / a);
}

inline Vector3& Vector3::operator/=(const float a) {
    x /= a; y /= a; z /= a; return *this;
}

inline bool Vector3::operator==(const Vector3& rhs) const {
    return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
}

inline bool Vector3::operator!=(const Vector3& rhs) const {
    return (x != rhs.x) || (y != rhs.y) || (z != rhs.z);
}

inline bool Vector3::operator<(const Vector3& rhs) const {
    if (x < rhs.x) return true;
    if (x > rhs.x) return false;
    if (y < rhs.y) return true;
    if (y > rhs.y) return false;
    if (z < rhs.z) return true;
    if (z > rhs.z) return false;
    return false;
}

inline float Vector3::operator[](int index) const {
    return (&x)[index];
}

inline float& Vector3::operator[](int index) {
    return (&x)[index];
}

inline Vector3& Vector3::set(float x, float y, float z) {
    this->x = x; this->y = y; this->z = z; return *this;
}

inline float Vector3::length() const {
    return sqrtf(x * x + y * y + z * z);
}

inline float Vector3::distance(const Vector3& vec) const {
    return sqrtf((vec.x - x) * (vec.x - x) + (vec.y - y) * (vec.y - y) + (vec.z - z) * (vec.z - z));
}

inline float Vector3::angle(const Vector3& vec) const {
    float l1 = this->length();
    float l2 = vec.length();
    float d = this->dot(vec);
    float angle = acosf(d / (l1 * l2)) / 3.141592f * 180;
    return angle;
}

inline Vector3& Vector3::normalize() {
    float xxyyzz = x * x + y * y + z * z;
    float invLength = 1 / sqrtf(xxyyzz);
    x *= invLength;
    y *= invLength;
    z *= invLength;
    return *this;
}

inline float Vector3::dot(const Vector3& rhs) const {
    return (x * rhs.x + y * rhs.y + z * rhs.z);
}

inline Vector3 Vector3::cross(const Vector3& rhs) const {
    return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

inline bool Vector3::equal(const Vector3& rhs, float epsilon) const {
    return fabs(x - rhs.x) < epsilon && fabs(y - rhs.y) < epsilon && fabs(z - rhs.z) < epsilon;
}

inline Vector3 operator*(const float a, const Vector3 vec) {
    return Vector3(a * vec.x, a * vec.y, a * vec.z);
}

inline ostream& operator<<(ostream& os, const Vector3& vec) {
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}
