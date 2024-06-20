#include <iostream>
#include <random>
#include <ctime>
static std::uniform_real_distribution<double> u(0, 1);
static std::default_random_engine e(time(NULL));
int pProb() {
    double p = 0.8;
    return u(e) > p ? 0 : 1;
}

int halfProb() {
    int first, second;
    do{
        first = pProb();
        second = pProb();
    } while(first == second);

    return first;
}

int main() {
    for (int i = 0; i < 21; i++) {
        std::cout<< halfProb() << ' ';
    }

    return 0;
}