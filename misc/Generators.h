//
// Created by Elmo on 23/11/2026.
//

#pragma once
#include <random>

#include "./Array2D.h"


class Generators {

    std::mt19937 GEN;

    template<typename T>
    T get_rand_real(T min, T max) {
        static std::uniform_real_distribution<T> rand(min, max);

        return rand(GEN);
    }

    template<typename T>
    T get_rand_int(T min, T max) {
        static std::uniform_int_distribution<T> rand(min, max);

        return rand(GEN);
    }


    public:
    Generators() {
        GEN = std::mt19937(std::random_device{}());
    }

    template<typename T = double>
    void fill_array(const int width, const int height, T min, T max, Array2D<T>* arr) {
        for (int i=0; i<width; i++) {
            for (int j=0; j<height; j++) {
                arr->set(i,j, get_rand_real<T>(min, max) );
            }
        }
     }

    template<typename T = int>
    void fill_array_int(const int width, const int height, T min, T max, Array2D<T>* arr) {
        for (int i=0; i<width; i++) {
            for (int j=0; j<height; j++) {
                arr->set(i,j, get_rand_int<T>(min, max) );
            }
        }
     }

};
