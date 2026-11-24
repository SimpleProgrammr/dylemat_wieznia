#pragma once

class NewDataTypes {
    public:
    
    struct Weights{

    private:
        Array2D<double> *weights;
    public:
        int width;
        int height;
        Weights(int w, int h);

        [[nodiscard]] double get_weight(int w, int h) const;
        void set_weight(int w, int h, double val);
        void set_weights(int w, int h, Array2D<double> *vals);
        void set_random_weights(double min, double max) const;

    };

        T& operator[](int i) {
            return data.get()[i];
        }

        const T& operator[](int i) const {
            return data.get()[i];
        }

        [[nodiscard]] T get(const int w, const int h) {
            return data.get()[h * width + w];
        }

        void set(const int w, const int h, const T val) {
            data.get()[h * width + w] = val;
        }

    struct Msg2Judge;
};

