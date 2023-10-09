// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include <cassert>
#include <vector>
#include <cmath>
#include "p1_library.h"


using namespace std;


vector<pair<double, int> > summarize(vector<double> v) {
  sort(v);                               // sorted vector
  vector<pair<double,int>> vp;
  
  int count = 0;
  double element = v[0];
  
  for (int i = 0; i < v.size(); ++i) {  // if the element in the vector equals the stored value, increase count by 1
    if (v[i] == element) {
        ++count;
    }
    else {                              // if not, store the new value, set count to 1 as the current value has been counted once, and start counting again
        vp.push_back({element,count});  // also before storing the new value, add the existing value and its occurances to the pair vector 
        element = v[i];
        count = 1;
    }
  }
  vp.push_back({element,count});        // resolves the last occurance
  return vp;
}


int count(vector<double> v) {
  int count = v.size();

  return count;
}


double sum(vector<double> v) {
  double sum = 0;
  for (int i = 0; i < v.size(); ++i) {
    sum += v[i];
  }

  return sum;
}


double mean(vector<double> v) {
  double mean = sum(v) / v.size();

  return mean;
}


double median(vector<double> v) {
  sort(v);                                            // sorted vector
  double median;
  int size = v.size();

  if ((size % 2) != 0) {                              // if the input data vector has odd number of elements
    median = v[size / 2];
  }
  else if ((size % 2) == 0) {
    median = (v[(size - 1) / 2] + v[size / 2]) / 2;   // if the input data vector has even number of elements
  }

  return median;
}


double mode(vector<double> v) {
  sort(v);                                   // sorted vector
  double number = v[0];
  double mode = number;
  int count = 0;
  int Modecount = 0;

  for (int i = 0; i < v.size(); ++i) {      // if the counted element equal the stored value, add 1 to its occurance
    if (v[i] == number) {
        ++count;
    }
    else {                                  // if the counted element is a new element, store this new element if it occured more times than the previously stored one; if it is not new, keep counting the stored one
        if (count > Modecount) {
            Modecount = count;
            mode = number;
        }

        count = 1;
        number = v[i];
    }
  }

  if (count > Modecount) {                  // resolves edge case
    mode = number;
  }

  return mode;
}


double min(vector<double> v) {
   double min_element = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < min_element) {
            min_element = v[i];
        }
    }
    return min_element;
}


double max(vector<double> v) {
    double max_element = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > max_element) {
            max_element = v[i];
        }
    }
    return max_element;
}


double stdev(vector<double> v) {
  double stdev1 = 0;
  for (int i = 0; i < v.size(); ++i) {
    stdev1 += pow(v[i]-mean(v), 2);
  }

  double stdev_final = sqrt(stdev1/(v.size() - 1));

  return stdev_final;
}


double percentile(vector<double> v, double p) {
  sort(v);                                        // sorted vector
  int N = v.size();
  double n = (p / 100) * (N - 1) + 1;

  double fractional_part = 0;
  double integral_part = 0;
  fractional_part = modf(n, &integral_part);

  if (p == 0) {
    return v[0];
  }
  else if (p == 100) {
    return v[N -1];
  }
  else{
    return (v[integral_part - 1] + fractional_part * (v[integral_part] - v[integral_part - 1]));
  }

}
