#pragma once
#include <memory>

#include "./Array2D.h"


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
        void set_weight(int w, int h, double val) const;
        void set_weights(int w, int h, Array2D<double> *vals);
        void set_random_weights(double min, double max) const;

    };

    struct NeuralNetwork{
        int input_nodes_count;
        std::vector<int> input_nodes;

        Weights *in2hidden_weights;

        int hidden_nodes_count;
        std::vector<int> hidden_nodes;

        Weights *hidden2out_weights;

        bool output;

        NeuralNetwork(int input_nodes_count, int hidden_nodes_count);
        ~NeuralNetwork();

        void set_input_weights(Weights *weights);
        void set_output_weights(Weights *weights);
    };

    struct Msg2Judge {
        long id;
        NeuralNetwork *NN1;
        NeuralNetwork *NN2;
        int rounds_limit;

        Msg2Judge();
    };
};

