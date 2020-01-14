// Carter Mooring, Jared Alano-Gray, & Jackson Lindsay
// Dr. Bowers
// CPSC 223
// project.cpp
// This code sorts an array using cocktail, shell, separation and pigeon sort
// To Test, run CMakeList.txt, compile using make,
//  run using ./project (c | p | s | n) tester.txt
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <cassert>
#include "sort.cpp"

using namespace std;
using namespace std::chrono;

typedef pair<string,double> pair_t;

const int COCK_SORT = 0;
const int PIGE_SORT = 1;
const int SHLL_SORT = 2;
const int SEP_SORT = 3;

void do_sort(const vector<int>& inputs, int type)
{
  // create collection
  int size = inputs.size()-1;
  int c[size];
  for (int i = 0; i < size; i++) {
    c[i] = inputs[i];
  }
  // time sort
  if (type == COCK_SORT) {
    auto start = high_resolution_clock::now();
    cocktail_sort(c, size);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(end - start);
    cout << "Cocktail Sort: " << time.count() << " microseconds" << endl;
  }
  else if (type == PIGE_SORT) {
    auto start = high_resolution_clock::now();
    pigeonhole_sort(c, size);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(end - start);
    cout << "Pigeonhole Sort: " << time.count() << " microseconds" << endl;
  }
  else if (type == SHLL_SORT) {
    auto start = high_resolution_clock::now();
    shell_sort(c, size);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(end - start);
    cout << "Shell Sort.: " << time.count() << " microseconds" << endl;
  }
  else if (type == SEP_SORT) {
    auto start = high_resolution_clock::now();
    separation_sort(c, size);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(end - start);
    cout << "Separation Sort: " << time.count() << " microseconds" << endl;
  }
}

int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "usage: " << argv[0] << " (c | p | s | n) filename " << endl;
    return 1;
  }
  // load the data
  vector<int> inputs;
  fstream in_file;
  in_file.open(argv[2]);
  int value;
  while (in_file) {
    in_file >> value;
    inputs.push_back(value);
  }

  // run the sort algos
  if (string(argv[1]) == "c")
    do_sort(inputs, COCK_SORT);
  else if (string(argv[1]) == "p")
    do_sort(inputs, PIGE_SORT);
  else if (string(argv[1]) == "s")
    do_sort(inputs, SHLL_SORT);
  else if (string(argv[1]) == "n")
    do_sort(inputs, SEP_SORT);
}
