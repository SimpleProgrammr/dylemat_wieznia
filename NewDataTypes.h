#pragma once

class NewDataTypes {
    public:

    template <typename T>
    struct Array2D{
    private:
        std::unique_ptr<T> data;
    public:
        int width, height;
        Array2D(int w , int h): width(w), height(h) {
            data = std::unique_ptr<T>(new T[width * height]);
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

