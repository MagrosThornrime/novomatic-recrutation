#include <gtest/gtest.h>
#include <Triangle.h>
#include <Collisions.h>

TEST(Tests, SimpleCollision){
    triangle triangle1 = {
        vec2(-200, 200),
        vec2(200, 200),
        vec2(0, -200)
    };
    triangle1.setCircle();

    triangle triangle2 = {
        vec2(-300, -100),
        vec2(100, -100),
        vec2(-100, 100)
    };

    triangle2.setCircle();
    ASSERT_TRUE(isColliding(triangle1, triangle2));
}

TEST(Tests, NoCollision){
    triangle triangle1 = {
        vec2(-200, 200),
        vec2(200, 200),
        vec2(0, -200)
    };
    triangle1.setCircle();

    triangle triangle2 = {
        vec2(-300, -100),
        vec2(-100, -100),
        vec2(-300, 100)
    };
    triangle2.setCircle();

    ASSERT_FALSE(isColliding(triangle1, triangle2));
}

TEST(Tests, TriangleInside){
    triangle triangle1 = {
        vec2(-200, 200),
        vec2(200, 200),
        vec2(0, -200)
    };
    triangle1.setCircle();

    triangle triangle2 = {
        vec2(0, -100),
        vec2(100, 100),
        vec2(-100, 100)
    };
    triangle2.setCircle();

    ASSERT_TRUE(isColliding(triangle1, triangle2));
}