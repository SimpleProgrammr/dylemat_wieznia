//
// Created by Elmo on 23/11/2026.
//

#include "../NewDataTypes.h"

#include "Generators.h"

NewDataTypes::Weights::Weights(int w , int h) : width(w), height(h) {
    this->weights = new Array2D<double>(width, height);
}

double NewDataTypes::Weights::get_weight(const int w, const int h) const {
    return this->weights->get(w, h);
}

void NewDataTypes::Weights::set_weight(const int w, const int h, const double val) const {
    this->weights->set(w, h, val);
}

void NewDataTypes::Weights::set_weights(const int w, const int h, Array2D<double> *vals) {
    this->weights = vals;
}

void NewDataTypes::Weights::set_random_weights(const double min, const double max) const {
    auto gen = Generators();
    gen.fill_array(this->width, this->height, min, max, this->weights);
}

NewDataTypes::NeuralNetwork::NeuralNetwork(const int input_nodes_count, const int hidden_nodes_count) :
    in2hidden_weights(nullptr),
    hidden2out_weights(nullptr), output(false) {
    this->input_nodes_count = input_nodes_count;
    this->input_nodes = std::vector<int>(this->input_nodes_count);


    this->hidden_nodes_count = hidden_nodes_count;
    this->hidden_nodes = std::vector<int>(this->hidden_nodes_count);

}

NewDataTypes::NeuralNetwork::~NeuralNetwork() {
    delete this->in2hidden_weights;
    delete this->hidden2out_weights;
}

void NewDataTypes::NeuralNetwork::set_input_weights(Weights *weights) {
    delete this->in2hidden_weights;

    in2hidden_weights = weights;
}

void NewDataTypes::NeuralNetwork::set_output_weights(Weights *weights) {
    delete this->hidden2out_weights;

    hidden2out_weights = weights;
}




