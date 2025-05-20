#include "character.h"
#include "names.h"
#include "constants.h"
#include "structs.h"
#include <string>

Character::Character() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> PosDist(0.0, MAPSIZE);
    this->position = Int2{(int)PosDist(mt),(int)PosDist(mt)};

    std::uniform_real_distribution<double> SpectrumDist(-1.0, 1.0);
    this->personality = Vec3{
        SpectrumDist(mt),
        SpectrumDist(mt),
        SpectrumDist(mt)
    };

    this->mood = Vec2{
        SpectrumDist(mt),
        SpectrumDist(mt)
    };

    for (int i = 0; i < NUMBEROFPEOPLE; i++) {
        this->opinionsOfOthers.push_back(0.0);
    }

    this->name = GenerateNames();
    std::cout << this->name << " was born at (" << this->position.x << ", " << this->position.y << ")" << std::endl;
}

void Character::Move() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> PosDist(NONE, MAX_DIRECTIONS);
    std::uniform_real_distribution<double> PosChangeChance(-1.0, 1.0);
    // If the mood is good enough, change the movement state
    if (this->personality.x + 1.0 > 1.0) {
        movementDirection = (int)PosDist(mt);
    }
    switch(movementDirection) {
        case NORTH:
            this->position.y++;
            break;
        case SOUTH:
            this->position.y--;
            break;
        case EAST:
            this->position.x++;
            break;
        case WEST:
            this->position.x--;
            break;
        default:
            break;
    }
    // Bounds check
    LimitBounds(this->position);
    // Tell us that we moved
    if (movementDirection != NONE) {
        //std::cout << this->name << " moved to " << this->position.x << ", " << this->position.y << "." << std::endl;
    }
}

void Character::Interact(std::string othersName, Vec3 othersPersonality) {
    //std::cout << this->name << " and " << othersName << " talked a bit; ";
    //std::cout << GetDistance(this->personality, othersPersonality) << "/" << this->personality.y << "; ";
    if (GetDistance(this->personality, othersPersonality) > this->personality.y * this->mood.x + 1.0) {
        //std::cout << "It went poorly.";
        mood.x -= (float)turnsSinceInteraction/10.0 * this->personality.z;
    } else {
        //std::cout << "It went well.";
        mood.x += (float)turnsSinceInteraction/10.0 * this->personality.z;
    }
    //std::cout << std::endl;
    turnsSinceInteraction = 0;
}

void Character::CheckState() {
    if (mood.x >= 0.5) {
        std::cout << this->name << " is happy.";
    } else if (mood.x >= 0.0) {
        std::cout << this->name << " is fine.";
    } else if (mood.x >= -0.5) {
        std::cout << this->name << " is doing badly.";
    } else {
        std::cout << this->name << " is depressed.";
    }
    LimitBounds(this->personality);
    LimitBounds(this->mood);
    std::cout << " (" << mood.x << ", " << mood.y << ")" << std::endl;
    turnsSinceInteraction++;
}

std::string Character::GetName() { return this->name; }
Int2 Character::GetPosition() { return this->position; }
Vec3 Character::GetPersonality() { return this->personality; }
Vec2 Character::GetMood() { return this->mood; }