/*#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <map>
#include <random>
using namespace std;
using func = function<double(vector<string>)>;

auto brute_force = [](auto f, auto domain) {
    auto current_p = domain();
    auto best_point = current_p;
    try {
        while (true) {
            if (f(current_p) < f(best_point)) {
                best_point = current_p;
            }
            current_p = domain();
        }
    } catch (std::exception &e) {
    }
    return best_point;
};
using domain_t = vector<double>;
random_device rd;
mt19937 mt_generator(rd());

int main(int argc, char **argv) {
    map<string, func> mapa;
    mapa["sphere"] = [](vector<string>x){return pow(stod(x[2]),2);};
    mapa["booth"] = [](vector<string>x){return pow(stod(x[2])+2*stod(x[3])-7, 2)+pow(2*stod(x[2])+stod(x[3])-5, 2);};
    mapa["matyas"] = [](vector<string>x){return 0.26*pow(stod(x[2]),2)+pow(stod(x[3]),2)+0.48*stod(x[2])*stod(x[3]);};

    try {
        vector<string> argumenty(argv, argv + argc);
        auto SelectedFunc = mapa.at(argumenty.at(1));
        cout << SelectedFunc(argumenty) << endl;
    } catch (std::out_of_range aor) {
        cout << "Podaj nazwe funkcji. Dostepne to sphere, booth and matyas.";

    }

    return 0;
}*/
