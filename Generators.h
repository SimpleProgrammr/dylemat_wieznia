//
// Created by Elmo on 23/11/2026.
//

#pragma once

class Generators {

    static int get_rand_int(int min, int max);
    static double get_rand_double(double min, double max);

    public:
        static void weight_generator();
        static void offsets_generator();
        static double apply_offset();

};
