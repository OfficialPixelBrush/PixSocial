#include "structs.h"
#include "constants.h"

double GetDistance(Vec3 a, Vec3 b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

bool IsMatching(Int2 a, Int2 b) {
    return (a.x == b.x && a.y == b.y);
}

bool IsAdjacent(int a, int b) {
    int diff = abs(a - b);
    return diff == 1 || diff == MAPSIZE - 1; // wraparound
}

bool WithinReach(Int2 a, Int2 b) {
    return IsAdjacent(a.x, b.x) && a.y == b.y ||
           IsAdjacent(a.y, b.y) && a.x == b.x;
}

void LimitBounds(Vec2& pos) {
    if (pos.x < -1.0) {
        pos.x = -1.0;
    } else if (pos.x > 1.0) {
        pos.x = 1.0;
    }
    if (pos.y < -1.0) {
        pos.y = -1.0;
    } else if (pos.y > 1.0) {
        pos.y = 1.0;
    }
}

void LimitBounds(Vec3& pos) {
    if (pos.x < -1.0) {
        pos.x = -1.0;
    } else if (pos.x > 1.0) {
        pos.x = 1.0;
    }
    if (pos.y < -1.0) {
        pos.y = -1.0;
    } else if (pos.y > 1.0) {
        pos.y = 1.0;
    }
    if (pos.z < -1.0) {
        pos.z = -1.0;
    } else if (pos.z > 1.0) {
        pos.z = 1.0;
    }
}

void LimitBounds(Int2& pos) {
    if (pos.x < 0) {
        pos.x = MAPSIZE - 1;
    }
    if (pos.x >= MAPSIZE) {
        pos.x = 0;
    }
    if (pos.y < 0) {
        pos.y = MAPSIZE - 1;
    }
    if (pos.y >= MAPSIZE) {
        pos.y = 0;
    }
}