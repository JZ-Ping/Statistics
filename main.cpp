// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
// #include <fstream>


using namespace std;


int main() {
    string filename;
    string column;

    cout << "enter a filename" << "\n";
    cin >> filename;

    cout << "enter a column name" << "\n";
    cin >> column;

    vector<double> data = extract_column(filename, column);

    cout << "reading column " << column << " from " << filename << "\n";
    cout << "Summary (value: frequency)" << "\n";

    // print summary

    vector<pair<double, int> > summary = summarize(data);
        for (int i = 0; i < summary.size(); ++i) {
            cout << summary[i].first << ": " << summary[i].second << "\n";
        }

    cout << "\n";

    // print other statistics

    cout << "count = " << count(data) << "\n";
    cout << "sum = " << sum(data) << "\n";
    cout << "mean = " << mean(data) << "\n";
    cout << "stdev = " << stdev(data) << "\n";
    cout << "median = " << median(data) << "\n";
    cout << "mode = " << mode(data) << "\n";
    cout << "min = " << min(data) << "\n";
    cout << "max = " << max(data) << "\n";
    cout << "  0th percentile = " << percentile(data, 0) << "\n";
    cout << " 25th percentile = " << percentile(data, 25) << "\n";
    cout << " 50th percentile = " << percentile(data, 50) << "\n";
    cout << " 75th percentile = " << percentile(data, 75) << "\n";
    cout << "100th percentile = " << percentile(data, 100) << "\n";

    return 0;

}
