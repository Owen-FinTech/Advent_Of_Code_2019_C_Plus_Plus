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

    vector<int> allDigits;

    for (unsigned int i = 0; i < inputString.size(); ++i) {
        allDigits.push_back(stoi(inputString.substr(i, 1)));
    }

    int pixelsWide = 25;
    int pixelsTall = 6;
    int sizeOfLayer = pixelsWide * pixelsTall;
    int numLayers = allDigits.size() / sizeOfLayer;
    int fewestZeros = sizeOfLayer;
    int fewestZerosOnes = 0;
    int fewestZerosTwos = 0;

    for (int i = 0; i < numLayers; ++i) {
        int numZeros = 0;
        int numOnes = 0;
        int numTwos = 0;

        for (int j = 0; j < sizeOfLayer; ++j) {
            if (allDigits.at((i * sizeOfLayer) + j) == 0) {
                ++numZeros;
            }
            else if (allDigits.at((i * sizeOfLayer) + j) == 1) {
                ++numOnes;
            }
            else {
                ++numTwos;
            }
        }

        if (numZeros < fewestZeros) {
            fewestZeros = numZeros;
            fewestZerosOnes = numOnes;
            fewestZerosTwos = numTwos;
        }
    }

    cout << fewestZerosOnes * fewestZerosTwos << endl;

    return 0;
}