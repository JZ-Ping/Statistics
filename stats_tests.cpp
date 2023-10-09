/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_percentile_small_data_set();
void test_stdev_small_data_set();
void test_max_small_data_set();
void test_min_small_data_set();
void test_mode_small_data_set_edge();
void test_median_small_data_set();
void test_mean_small_data_set();
void test_count_small_data_set();

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  // Call your test functions here

  test_percentile_small_data_set();
  test_stdev_small_data_set();
  test_max_small_data_set();
  test_min_small_data_set();
  test_mode_small_data_set_edge();
  test_median_small_data_set();
  test_mean_small_data_set();
  test_count_small_data_set();

  // testing summarize separately
  vector<double> data;
  data.push_back(1);
  data.push_back(4);
  data.push_back(3);
  data.push_back(2);
  data.push_back(4);

  vector<pair<double, int> > summary = summarize(data);
  for (int i = 0; i < summary.size(); ++i) {
    cout << "summary[" << i << "] = {" << summary[i].first << ", " << summary[i].second << "}\n";
  }

  return 0;
}

// sum

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(4);

  assert(sum(data) == 14);

  cout << "sum_pass" << endl;
}

// Add the test function implementations here.

//count

void test_count_small_data_set() {
  cout << "test_count_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(4);

  assert(count(data) == 5);

  cout << "count_pass" << endl;
}

// mean

void test_mean_small_data_set() {
  cout << "test_mean_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(4);

  assert(mean(data) == 2.8);

  cout << "mean_pass" << endl;
}

// median

void test_median_small_data_set() {
  cout << "test_median_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(4);
  data.push_back(3);
  data.push_back(2);
  data.push_back(4);

  assert(median(data) == 3);

  cout << "median_pass" << endl;
}

// mode occurs at the end of vector or edge case

void test_mode_small_data_set_edge() {
  cout << "test_mode_small_data_set_edge_case" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(4);
  data.push_back(3);
  data.push_back(2);
  data.push_back(4);

  assert(mode(data) == 4);

  cout << "mode_edge_case_pass" << endl;
}

// min

void test_min_small_data_set() {
  cout << "test_min_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(4);

  assert(min(data) == 1);

  cout << "min_pass" << endl;
}

// max

void test_max_small_data_set() {
  cout << "test_max_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(4);

  assert(max(data) == 4);

  cout << "max_pass" << endl;
}

// stdev

void test_stdev_small_data_set() {
  cout << "test_stdev_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(4);

  bool result = true;
  double correct_ans = 1.3038404810405;
  double difference = abs(stdev(data) - correct_ans);
  if (difference > 0.001) {
    result = false;
  }

  assert(result);

  cout << "stdev_pass" << endl;
}

// percentile

void test_percentile_small_data_set() {
  cout << "test_percentile_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(4);
  data.push_back(3);
  data.push_back(2);
  data.push_back(4);

  vector<double> second_input = {0, 25, 50, 75, 100}; // size = 5
  vector<double> calc_percentile;

  for (int i = 0; i < second_input.size(); ++i) {
    calc_percentile.push_back(percentile(data, second_input[i]));
  }
  
  vector<double> ans = {1, 2, 3, 4, 4}; // size = 5
  
  vector<double> diff;

  for (int i = 0; i < ans.size(); ++i) {
    diff.push_back(abs(calc_percentile[i] - ans[i]));
  }
  
  vector<bool> result = {true, true, true, true, true}; // size = 5

  for (int i = 0; i < diff.size(); ++i) {
    if (diff[i] > 0.001) {
      result[i] = false;
    }
  }
  
  bool final_result = true;

  for (int i = 0; i < result.size(); ++i) {
    if (result[i] == false) {
      final_result = false;
    }
  }

  assert(final_result);

  cout << "percentile_pass" << endl;
}

// summarize will be used directly for convenience, as errors in this small data set are easily identifiable