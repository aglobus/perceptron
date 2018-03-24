#include "Perceptron.h"

double dot_product(const std::vector<double> &a, const std::vector<double> &b) {
  return std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
}

void Perceptron::train(const std::vector<TrainingSet_t> &train_from, int max_iter) {
  for (int i = 0; i < max_iter; i++) {
    for (const TrainingSet_t &item : train_from) {
      // run each item in the set through the learning process
      learn(item.output, item.inputs);
    }
  }
}
double Perceptron::ask(const std::vector<double> &query) {
  return (dot_product(query, weights) + bias > 0 ? 1.0 : 0.0);
}

void Perceptron::learn(double expected, const std::vector<double> &inputs) {
  bool x = (expected != 0.0);
  bool result = ask(inputs) != 0.0;
  if (result != x) {
    double error = (int)x - (int)result;
    correct_error(error, inputs);
  }
}

void Perceptron::correct_error(double error, const std::vector<double> &inputs) {
  //adjust the weights
  for (int i = 0; i < weights.size(); i++) {
    weights[i] += learning_rate * error * inputs[i];
  }
  //adjust the bias
  bias += learning_rate * error;
}

double Adaline::ask(const std::vector<double> &query) {
  return dot_product(query, weights) + bias;
}

void Adaline::learn(double expected, const std::vector<double> &inputs) {
  // summation
  double net = ask(inputs);
  // feed that result into 1/1+exp(-{summation result})
  double output  = 1 / (1 + exp(-net));
  // error = expected - {activation function result}
  double error = expected - output;
  correct_error(error, inputs);
}
