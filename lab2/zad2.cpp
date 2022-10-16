#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <functional>
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
    } catch (exception &e) {
    }
    return best_point;
};

using domain_t = vector<double>;
random_device rd;
mt19937 mt_generator(rd());

domain_t hill_climbing(const function<double(domain_t)> &f, domain_t minimal_d, domain_t maximal_d, int max_iterations) {
    domain_t current_p(minimal_d.size());
    for (int i = 0; i < minimal_d.size(); i++) {
        uniform_real_distribution<double> dist(minimal_d[i], maximal_d[i]);
        current_p[i] = dist(mt_generator);
    }
    for (int iteration = 0; iteration < max_iterations; iteration++) {
        domain_t new_p(minimal_d.size());
        for (int i = 0; i < minimal_d.size(); i++) {
            uniform_real_distribution<double> dist(-1.0/128.0, 1.0/128.0);
            new_p[i] = current_p[i] + dist(mt_generator);
        }
        if (f(current_p) > f(new_p)) {
            current_p = new_p;
        }
    }
    return current_p;
}

int main() {
    srand((unsigned)time(0));
    auto rastriginFunc = [](double x) {return 10+(pow(x,2)-10*cos(3.14*x));};
    double rastriginCurrentX = -(rand()%10000)+1;;
    double numberToCompare = rastriginCurrentX;
    auto generateRastrigin = [&]() {
        rastriginCurrentX+= 1.0;
        if (rastriginCurrentX >= (-numberToCompare)) throw invalid_argument("finished");
        return rastriginCurrentX;
    };
    auto best_point = brute_force(rastriginFunc, generateRastrigin);
    cout << "best x = " << best_point << endl;
    auto rastriginFuncVector = [](domain_t x) {return 10+(pow(x[0],2)-10*cos(3.14*x[0]));};
    auto best2 = hill_climbing(rastriginFuncVector, {rastriginCurrentX},{-rastriginCurrentX},100000);
    cout << "best x = " << best2[0] << endl;
    return 0;
}