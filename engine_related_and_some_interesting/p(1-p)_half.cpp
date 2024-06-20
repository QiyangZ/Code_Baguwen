/*
    Problem Description:
    you have a function pProb(), which can generate 1 in probobility p
    and generate 0 in probobility (1 - p); design a function by using
    pProb(), that can generate 1 in probobility 0.5 and generate 0 in
    probobility 0.5;
 */
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