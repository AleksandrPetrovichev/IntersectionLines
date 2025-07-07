#include "pch.h"
#include"../IntersectionLines/main.cpp"

TEST(Vector2Test, DefaultConstructor) {
    Vector2 v;
    EXPECT_FLOAT_EQ(v.x, 0);
    EXPECT_FLOAT_EQ(v.y, 0);
}

TEST(Vector2Test, ParameterizedConstructor) {
    Vector2 v(1.5, 2.5);
    EXPECT_FLOAT_EQ(v.x, 1.5);
    EXPECT_FLOAT_EQ(v.y, 2.5);
}

TEST(Vector2Test, LengthCalculation) {
    Vector2 v(3, 4);
    EXPECT_FLOAT_EQ(v.length(), 5.); 
}

TEST(Vector2Test, Normalization) {
    Vector2 v(10, 0);
    v.normalize();
    EXPECT_FLOAT_EQ(v.x, 1);
    EXPECT_FLOAT_EQ(v.y, 0);
}

TEST(LineTest, LineFromSlopeIntercept) {
    Line line(2, 1); 
    Vector3 dir = line.getDirection();
    Vector3 pt = line.getPoint();

    EXPECT_FLOAT_EQ(dir.x, 1);
    EXPECT_FLOAT_EQ(dir.y, 2); 
    EXPECT_FLOAT_EQ(pt.x, 0);
    EXPECT_FLOAT_EQ(pt.y, 1);  
}

TEST(LineTest, IntersectionBasic) {
    Line line1(1, 0);  
    Line line2(-1, 2); 
    auto result = line1.intersect(line2);

    EXPECT_FLOAT_EQ(result.x, 1); 
    EXPECT_FLOAT_EQ(result.y, 1);
}

TEST(LineTest, ParallelLines) {
    Line line1(2, 0); 
    Line line2(2, 1); 
    auto result = line1.intersect(line2);

    EXPECT_FALSE(line1.isIntersected(line2));
}
TEST(Vector3Test, DefaultConstructor) {
    Vector3 v;
    EXPECT_FLOAT_EQ(v.x, 0);
    EXPECT_FLOAT_EQ(v.y, 0);
    EXPECT_FLOAT_EQ(v.z, 0);
}

TEST(Vector3Test, LengthCalculation) {
    Vector3 v(1, 2, 2);
    EXPECT_FLOAT_EQ(v.length(), 3); 
}

TEST(Vector3Test, CrossProduct) {
    Vector3 a(1, 0, 0);
    Vector3 b(0, 1, 0);
    Vector3 cross = a.cross(b);

    EXPECT_FLOAT_EQ(cross.x, 0);
    EXPECT_FLOAT_EQ(cross.y, 0);
    EXPECT_FLOAT_EQ(cross.z, 1); 
}

TEST(Vector3Test, Normalization) {
    Vector3 v(2, 0, 0);
    v.normalize();
    EXPECT_FLOAT_EQ(v.x, 1);
    EXPECT_FLOAT_EQ(v.y, 0);
    EXPECT_FLOAT_EQ(v.z, 0);
}


