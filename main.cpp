#include <iostream>
#include <map>
#include <valarray>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;
using func = function<double(vector<string>)>;

int main(int argc, char **argv) {
    map<string, func> mapa;
    mapa["sin"] = [](vector<string>x){return sin(stod(x[2]));};
    mapa["add"] = [](vector<string>x){return stod(x[2])+stod(x[3]);};
    mapa["mod"] = [](vector<string>x){return stoi(x[2])%stoi(x[3]);};

    try {
        vector<string> argumenty(argv, argv + argc);
        auto SelectedFunc = mapa.at(argumenty.at(1));
        cout << SelectedFunc(argumenty) << endl;
    } catch (std::out_of_range aor) {
        cout << "podaj argument. Dostepne to sin, add, mod: ";

    }


    return 0;
}