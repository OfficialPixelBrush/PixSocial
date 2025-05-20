#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

#include "structs.h"
#include "character.h"
#include "constants.h"

using namespace std::chrono_literals;

std::vector<Character> characters;
int map[MAPSIZE][MAPSIZE];
int turnNumber = 0;

int main() {
    std::ofstream outFile("social.csv");

    // Check if the file is open
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing.\n";
        return 1;
    }

    // Populate the world with people
    for (int i = 0; i < NUMBEROFPEOPLE; i++) {
        characters.push_back(Character());
        outFile << characters[i].GetName();
        if (i < NUMBEROFPEOPLE-1) {
            outFile << ",";
        } else {
            outFile << "\n";
        }
    }

    while(true) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "It is turn #" << turnNumber << "." << std::endl;
        for (auto& c : characters) {
            c.Move();
            for (auto& cb : characters) {
                if (WithinReach(c.GetPosition(),cb.GetPosition())) {
                    c.Interact(cb.GetName(), cb.GetPersonality());
                }
            }
        }

        /*
        for (int y = 0; y < MAPSIZE; y++) {
            for (int x = 0; x < MAPSIZE; x++) {
                bool characterFound = false;
                for (auto& c : characters) {
                    if (IsMatching(c.GetPosition(),Int2{x,y})) {
                        std::cout << c.GetName()[0] << c.GetName()[1];
                        characterFound = true;
                        break;
                    }
                }
                if (!characterFound) {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
        */
        for (int i = 0; i < NUMBEROFPEOPLE; i++) {
            characters[i].CheckState();
            outFile << characters[i].GetMood().x;
            if (i < NUMBEROFPEOPLE-1) {
                outFile << ",";
            } else {
                outFile << "\n";
            }
        }
        turnNumber++;
        //std::this_thread::sleep_for(0.5s);
        //std::cin.get();    // Waits for Enter key
    }
    return 0;
}