/*#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <map>
using namespace std;
using func = function<double(vector<string>)>;

int main(int argc, char **argv) {
    map<string, func> mapa;
    mapa["rastrigin"] = [](vector<string>x){return 10+(pow(stod(x[2]),2)-10*cos(3.14*stod(x[2])));};
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