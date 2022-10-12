#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <random>
using namespace std;
using func = function<double(vector<string>)>;

auto brute_force = [](auto func, auto domain) {
    auto current_px = domain();
    auto currentPY = domain();
    auto best_pointX = current_px;
    auto bestPointY = currentPY;
    try {
        while (true) {
            if (func(current_px, currentPY) < func(best_pointX, bestPointY)) {
                best_pointX = current_px;
                bestPointY = currentPY;
            }
            current_px = domain();
            currentPY = domain();
        }
    } catch (exception &e) {
    }
    double arr[2] = {best_pointX, bestPointY};
    return *arr;
};
/*using domain_t = vector<double>;
random_device rd;
mt19937 mt_generator(rd());*/

int main() {
    auto boothFunc = [](double x, double y) {return pow(x+2*y-7, 2)+pow(2*x+y-5, 2);};
    double chosenX = -21;
    double chosenY = -37;
    auto boothGeneratorForX = [&]() {
        chosenX+= 1.0/12;
        if (chosenX >= 21) throw invalid_argument("finished");
        return chosenX;
    };

    auto boothGeneratorForY = [&]() {
        chosenY+= 1.0/12;
        if (chosenX >= 37) throw invalid_argument("finished");
        return chosenY;
    };

    double bestPoints[2] = {brute_force(boothFunc, boothGeneratorForX)};
    double bestPointX[1] = {bestPoints[0]};
    double bestPointY[1] = {bestPoints[1]};
    cout << "best x = " << bestPointX[0] << " best y = " << bestPointY[0] << endl;
    return 0;
}
