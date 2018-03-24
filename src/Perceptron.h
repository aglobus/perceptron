#include <vector>
#include <numeric>
#include <math.h>

#define DEFAULT_LEARN_RATE 1
#define DEFAULT_LR_ADALINE 0.2
#define DEFAULT_BIAS 1

#define COLS 4

typedef struct TrainingSet {
  //expected outcome
  double output; // Was bool, changed to adapt for adaline

  //training set's input
  std::vector<double> inputs;

  //constructor
  TrainingSet(double expected_output, const std::vector<double> &inputs) : output(expected_output), inputs(inputs) {}
} TrainingSet_t;

// TODO change the name/move to more generic Neuron class
// Because now it reads that an Adaline is_a Perceptron
// When really both Adalines and Pereptrons is_a Neuron
class Perceptron {
 public:
  //constructor
  Perceptron(int n_inputs, double learning_rate = DEFAULT_LEARN_RATE, double bias = DEFAULT_BIAS) : learning_rate(learning_rate), bias(bias), weights(n_inputs) {}

  //destructor
  ~Perceptron() {}

  //train the network with a vector of training data and the number of iterations
  void train(const std::vector<TrainingSet_t> &set, int max_iter);

  //Given a set of inputs, ask the network what it classifies it as
  virtual double ask(const std::vector<double> &query);
 protected:
  //Learn will take in an expected value and a set of inputs. If perceptron classifies it correctly, do nothing. If classified incorrectly, learn will call correct_error to adjust the weights and bias members
  virtual void learn(double expected, const std::vector<double> &inputs);
  virtual void correct_error(double error, const std::vector<double> &inputs);

  // A perceptron keeps track of its learning rate, bias, and a set of weights for each input
  double learning_rate;
  double bias;
  std::vector<double> weights;

};

class Adaline : public Perceptron {
 public:
 Adaline(int n_inputs, double learning_rate = DEFAULT_LR_ADALINE, double bias = DEFAULT_BIAS) : Perceptron(n_inputs, learning_rate, bias) {}

 double ask(const std::vector<double> &query);

 private:
  void learn(double expected, const std::vector<double> &inputs);
  /* void correct_error(double error, const std::vector<double> &inputs); */
};
