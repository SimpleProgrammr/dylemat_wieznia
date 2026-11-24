//
// Created by Elmo on 23/11/2026.
//

#include "NewDataTypes.h"

struct NewDataTypes::Weights{
    int width;
    int height;
    double (*weight)[];
};

struct NewDataTypes::NeuralNetwork {
    int input_nodes_count;
    int *input_nodes;

    Weights *in2hidden_weights;

    int hidden_nodes_count;
    int *hidden_nodes;

    Weights *hidden2out_weights;

    bool output;
};

struct NewDataTypes::Msg2Judge {
    
};