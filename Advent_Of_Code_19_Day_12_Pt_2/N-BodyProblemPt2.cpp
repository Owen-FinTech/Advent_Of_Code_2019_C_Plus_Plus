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

    int moon = 0;
    int xyz = 0;
    bool inNum = false;
    string currNum = "";

    int** posAndVel = new int*[4];
    for (int i = 0; i < 4; ++i) {
        posAndVel[i] = new int [6];
        for (int j = 0; j < 6; ++j) {
            posAndVel[i][j] = 0;
        }
    }
    
    for (int i = 0; i < inputString.size(); ++i) {
        if (inNum && inputString.at(i) == ',') {
            posAndVel[moon][xyz] = stoi(currNum);
            ++xyz;
            currNum = "";
            inNum = false;
        }
        else if (inNum && inputString.at(i) == '>') {
            posAndVel[moon][xyz] = stoi(currNum);
            xyz = 0;
            ++moon;
            currNum = "";
            inNum = false;
        }
        else if (inNum) {
            currNum += inputString.at(i);
        }
        
        if (inputString.at(i) == '=') {
            inNum = true;
        }
    }

    int** posAndVelCopy = new int*[4];
    for (int i = 0; i < 4; ++i) {
        posAndVelCopy[i] = new int [6];
        for (int j = 0; j < 6; ++j) {
            posAndVelCopy[i][j] = posAndVel[i][j];
        }
    }

    long long int step = 0;
    bool repeat = false;
    int k = 0;
    vector<long long int> axisRepeats(3);

    while (k < 3) {
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                if (posAndVelCopy[i][k] > posAndVelCopy[j][k]) {
                    --posAndVelCopy[i][k + 3];
                    ++posAndVelCopy[j][k + 3];
                }
                else if (posAndVelCopy[i][k] < posAndVelCopy[j][k]) {
                    ++posAndVelCopy[i][k + 3];
                    --posAndVelCopy[j][k + 3];
                }
            }
        }

        for (int i = 0; i < 4; ++i) {
            posAndVelCopy[i][k] += posAndVelCopy[i][k + 3];
        }
        ++step;
        int repeatCount = 0;

        for (int i = 0; i < 4; ++i) {
            if (posAndVel[i][k] == posAndVelCopy[i][k] && 
                posAndVel[i][k + 3] == posAndVelCopy[i][k + 3]) {
                ++repeatCount;
            }
        }

        if (repeatCount == 4) {
            axisRepeats.at(k) = step;
            ++k;
            step = 0;
        }
    }

    long long int gcdA = 0;
    long long int minRepeatA;
    long long int lcmA = 0;

    if (axisRepeats.at(0) < axisRepeats.at(1)) {
        minRepeatA = axisRepeats.at(0);
    }
    else {
        minRepeatA = axisRepeats.at(1);
    }

    for (long long int i = 1; i <= minRepeatA; ++i) {
        if ((axisRepeats.at(0) % i == 0) && (axisRepeats.at(1) % i == 0)) {
            gcdA = i;
        }
    }

    lcmA = (axisRepeats.at(0) * axisRepeats.at(1)) / gcdA;

    long long int gcdB = 0;
    long long int minRepeatB;
    long long int lcmB = 0;

    if (axisRepeats.at(2) < lcmA) {
        minRepeatB = axisRepeats.at(2);
    }
    else {
        minRepeatB = lcmA;
    }

    for (long long int i = 1; i <= minRepeatB; ++i) {
        if ((axisRepeats.at(2) % i == 0) && (lcmA % i == 0)) {
            gcdB = i;
        }
    }

    lcmB = (axisRepeats.at(2) * lcmA) / gcdB;

    cout << lcmB << endl;

    return 0;
}