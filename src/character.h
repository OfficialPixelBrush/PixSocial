#pragma once
#include "structs.h"

#include <vector>
#include <string>
#include <iostream>

class Character {
    private:
        std::string name;
        Int2 position;
        // X = free-spiritness (movement predictability)
        // Y = openness (margin of being able to make friends, despite different spectrum)
        // Z = sociality (-1.0 = attention whores, 0.0 = normal, 1.0 = prefer small groups)
        Vec3 personality = Vec3{0.0,0.0,0.0};
        // X = happiness
        // Y = focus
        Vec2 mood = Vec2{0.0,0.0};
        int movementDirection = NONE;
        int turnsSinceInteraction = 0;
        std::vector<float> opinionsOfOthers;
    public:
        Character();
        void Move();
        void Interact(std::string othersName, Vec3 othersPersonality);
        std::string GetName();
        Int2 GetPosition();
        Vec3 GetPersonality();
        Vec2 GetMood();
        void CheckState();
};