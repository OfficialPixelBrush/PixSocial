#pragma once
#include <cmath>
#include "constants.h"

struct Vec2 {
    double x,y;
};

typedef struct Vec2 Vec2;

struct Vec3 {
    double x,y,z;
};

typedef struct Vec3 Vec3;

struct Int2 {
    int x,y;
};

typedef struct Int2 Int2;

double GetDistance(Vec3 a, Vec3 b);
bool IsMatching(Int2 a, Int2 b);
bool IsAdjacent(int a, int b);
bool WithinReach(Int2 a, Int2 b);
void LimitBounds(Vec2& pos);
void LimitBounds(Vec3& pos);
void LimitBounds(Int2& pos);