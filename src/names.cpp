#include "names.h"

std::vector<std::string> start = {
    "To","Jo","Ry","Ol","Ra","Chri","Te","Mi","Ku","Si","Tre","Do","Ma"
};

std::vector<std::string> middle = {
    "r","b","a","k","m","b","z","g","e","l","p"
};

std::vector<std::string> end = {
    "en","by","an","en","un","tin","nt","th"
};

std::string GenerateNames() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distStart(0.0, start.size());
    std::uniform_real_distribution<double> distMiddle(0.0, middle.size());
    std::uniform_real_distribution<double> distEnd(0.0, end.size());
    return start[(int)distStart(mt)] + middle[(int)distMiddle(mt)] + end[(int)distEnd(mt)];
}