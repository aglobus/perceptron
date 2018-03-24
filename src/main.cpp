#include "Perceptron.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

std::vector<std::string> split(const std::string &s, char delim);

namespace {
  std::vector<TrainingSet_t> train_set;
  std::vector<TrainingSet_t> test_set;

  void write_to(const char *filepath, std::vector<TrainingSet_t> &from, Perceptron &n) {
    std::ofstream write(filepath);
    std::ifstream read(filepath, std::ios::in);

    int i = 0;
    for (std::string line; std::getline(read, line);i++) {
      write << line << "," << n.ask(from[i].inputs) << "\n";
    }

  }

  void read_in(const char *filepath, std::vector<TrainingSet_t> &output_set, const bool *a) {
    std::ifstream data(filepath, std::ios::in);

    for (std::string line; std::getline(data, line);) {
      //SL, SW, PL, PW, Type
      std::vector<std::string> r = split(line, ',');
      //grab the PL and PW
      std::vector<double> x;
      for (int i = 0; i < COLS; i++)
        x.push_back(std::atof(r[i].c_str()));
      // setosa vs all
      /*
      if (r[4] == "Iris-setosa")
        output_set.push_back(TrainingSet_t(false, x));
      else
        output_set.push_back(TrainingSet_t(true, x));
      */
      // versicolor vs virginica
      if (r[4] == "Iris-versicolor")
        output_set.push_back(TrainingSet_t(false, x));
      else if (r[4] == "Iris-virginica")
        output_set.push_back(TrainingSet_t(true, x));
    }
  }

  void read_train_csv(const bool *r) {
    read_in("../train.csv", train_set, r);
  }

  void read_test_csv(const bool *r) {
    read_in("../test.csv", test_set, r);
  }
}

int main(void) {
  // bool x[COLS] = {true, true, true, true};

  // read_train_csv(x);
  // Perceptron p(4);
  // p.train(train_set, 100);

  // read_train_csv(x);
  // Adaline a(4);
  // a.train(train_set, 100);

  // read_test_csv(x);
  // for (TrainingSet_t &t : test_set) {
  //   printf("%f\n", a.ask(t.inputs));
  // }

  return 0;
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> tokens;
  // Extract characters from ss and append them to item until delim or end while ss is valid
  while (std::getline(ss, item, delim)) {
    tokens.push_back(item);
  }
  return tokens;
}
