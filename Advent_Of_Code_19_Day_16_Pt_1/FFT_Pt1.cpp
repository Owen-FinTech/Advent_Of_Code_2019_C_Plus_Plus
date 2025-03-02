#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MULTI_LINE_STRING(...) #__VA_ARGS__

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;

int main() {
    string inputString = MULTI_LINE_STRING(""); // Insert the puzzle input here
    vector<int> signal;

    for (unsigned int i = 0; i < inputString.size(); ++i) {
        string charAsString = inputString.substr(i, 1);
        signal.push_back(stoi(charAsString));
    }

    vector<int> base;
    base.push_back(0);
    base.push_back(1);
    base.push_back(0);
    base.push_back(-1);
    int baseSize = 4;
    vector<int> newSignal(signal.size());

    for (int i = 0; i < 100; ++i) {
        for (unsigned int j = 0; j < signal.size(); ++j) {
            int newSignalInt = 0;
            int baseCount = 0;
            for (unsigned int k = 0; k < signal.size(); ++k) {
                if ((k + 1) % (j + 1) == 0) {
                    ++baseCount;
                }
                newSignalInt += signal.at(k) * base.at(baseCount % baseSize);
            }
            newSignal.at(j) = static_cast<int>(fabs(static_cast<double>(newSignalInt))) % 10;
        } 

        for (unsigned int j = 0; j < signal.size(); ++j) {
            signal.at(j) = newSignal.at(j);
        }
    }

    for (int i = 0; i < 8; ++i) {
        cout << signal.at(i); 
    }
    cout << endl;

    return 0;
}