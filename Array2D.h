#pragma once
#include <memory>
#include <vector>

using namespace std;

template <typename T>
class Array2D {
public:

    int width, height;
    
    Array2D(const int w , int h):
    width(w),
    height(h),
    data(h, vector<T>(w)) {};

    [[nodiscard]] T get(const int w, const int h) {
        return data[h][w];
    }

    void set(const int w, const int h, const T val) {
        data[h][w] = val;
    }

    void operator +=(Array2D<T> &other) {
        data += other.data;
    }
    void operator -=(Array2D<T> &other) {
        data -= other.data;
    }


private:
    vector< vector<T> > data;

};

