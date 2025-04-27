# Collisions
Implement a function isColliding that returns true if two triangles in 2D space collide with each other.
Then, write a visualizer for this collision.
The triangles should be visible on the screen, and at least one of them should be controllable by the user.
The collision should be somehow signaled to the user.

```cpp
struct vec2
{
    float x, y;
};

struct triangle
{
    std::array<vec2, 3> points;
};

bool isColliding(const& triangle1, const& triangle2);
```

## How to build on Linux:
```bash
conan install . --profile linux.conf --output-folder build --build missing
cmake -S . -B build
cmake --build build
```

## How to build on Windows:
```bash
conan install . --profile windows.conf --output-folder build --build missing
cmake -S . -B build
cmake --build build
```

## How to run visualizer:
```bash
./build/game
```

## Controls:
- W: go up
- D: go right
- S: go down
- A: go left
- Q: rotate left
- E: rotate right

## How to run tests:
```bash
./build/tests
```