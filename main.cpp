#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

double findMedian(const vector<int>& data) {
    size_t n = data.size();
    if (n == 0) {
        throw runtime_error("Data set is empty");
    }
    if (n % 2 == 1) {
        return static_cast<double>(data[n / 2]);
    } else {
        return (data[n / 2 - 1] + data[n / 2]) / 2.0;
    }
}

vector<int> readDataFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file: " + filename);
    }

    vector<int> data;
    string line;
    getline(file, line); 

    stringstream ss(line);
    string number;
    while (getline(ss, number, ',')) {
        data.push_back(stoi(number));
    }

    file.close();
    return data;
}

int main() {
    string filename;
    cout << "Enter the filename, including the extension (Example: Enter data.csv for the given file) ";
    cin >> filename;

    try {
        vector<int> data = readDataFromFile(filename);
        double median = findMedian(data);
        cout << "The median of the dataset is " << median << "." << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
