//
// Created by Elmo on 23/11/2026.
//

#include "Generators.h"

#include <random>

int Generators::get_rand_int(int min, int max) {

    static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_int_distribution<int> rand(min,max);

    return rand(rng);

}

double Generators::get_rand_double(double min, double max) {
    static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_real_distribution<> rand(min,max);



    return rand(rng);



}
