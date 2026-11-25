#pragma once
#include <memory>
#include <vector>
#include <stdexcept>
#include <iostream>


template <typename T>
class Array2D {

private:
    std::vector< std::vector<T> > data;
public:

    int width, height;

    Array2D(const int w ,const int h):
    data(h, std::vector<T>(w)),
    width(w),
    height(h) {};

    [[nodiscard]] T get(const int w, const int h) {
        return data[h][w];
    }

    void set(const int w, const int h, const T val) {
        data[h][w] = val;
    }

    void print(const std::string &delimiter = ", ", const std::string &lineDelimiter = "\n") {
        for (auto line : data) {
            for ( auto cell : line) {
                std::cout << cell << delimiter;
            }
            std::cout << lineDelimiter;
        }
    }


    Array2D& operator+=(const Array2D& other) {
        if (width != other.width || height != other.height)
            throw std::invalid_argument("size mismatch");
        for (int x = 0; x < width; ++x)
            for (int y = 0; y < height; ++y)
                data[x][y] += other.data[x][y];
        return *this;
    }
    Array2D& operator-=(const Array2D& other) {
        if (width != other.width || height != other.height)
            throw std::invalid_argument("size mismatch");
        for (int x = 0; x < width; ++x)
            for (int y = 0; y < height; ++y)
                data[x][y] -= other.data[x][y];
        return *this;
    }

    Array2D& operator =(const Array2D<T> &other) {
        data = other.data;
        return *this;
    }
    Array2D& operator =( std::vector< std::vector<T> > other) {
        data = other;
        return *this;
    }
    std::vector<T>& operator[](const int x) {
        return data[x];
    }


};

