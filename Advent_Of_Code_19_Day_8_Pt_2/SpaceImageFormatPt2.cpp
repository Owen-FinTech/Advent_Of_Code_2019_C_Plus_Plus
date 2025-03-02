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

    vector<int> visible;

    for (int i = 0; i < sizeOfLayer; ++i) {
        for (int j = 0; j < numLayers; ++j) {
            if (allDigits.at((j * sizeOfLayer) + i) < 2) {
                visible.push_back(allDigits.at((j * sizeOfLayer) + i));
                break;
            }
        }
    }

    for (unsigned int i = 0; i < visible.size(); ++i) {
        if ((i + 1) % 25 == 0) {
            if (visible.at(i) == 1) {
                cout << 'X' << endl;
            }
            else {
                cout << ' ' << endl;
            }
        }
        else {
            if (visible.at(i) == 1) {
                cout << 'X';
            }
            else {
                cout << ' ';
            }
        }
    }

    return 0;
}