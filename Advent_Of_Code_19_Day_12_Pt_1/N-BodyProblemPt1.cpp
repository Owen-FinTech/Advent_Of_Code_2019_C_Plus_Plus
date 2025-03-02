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
   string inputString = MULTI_LINE_STRING(
<x=-14, y=-4, z=-11>
<x=-9, y=6, z=-7>
<x=4, y=1, z=4>
<x=2, y=-14, z=-9>
    ); // Insert the puzzle input here

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

    int step = 0;

    while (step < 1000) {
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (posAndVel[i][k] > posAndVel[j][k]) {
                        --posAndVel[i][k + 3];
                        ++posAndVel[j][k + 3];
                    }
                    else if (posAndVel[i][k] < posAndVel[j][k]) {
                        ++posAndVel[i][k + 3];
                        --posAndVel[j][k + 3];
                    }
                }
            }
        }

        for (int i = 0; i < 4; ++i) {
            for (int k = 0; k < 3; ++k) {
                posAndVel[i][k] += posAndVel[i][k + 3];
            } 
        }
        ++step;        
    }

    int potential = 0;
    int kinetic = 0;
    int total = 0;

    for (int i = 0; i < 4; ++i) {
        potential = 0;
        kinetic = 0;
        for (int k = 0; k < 3; ++k) {
            potential += fabs(posAndVel[i][k]);
            kinetic += fabs(posAndVel[i][k + 3]);
        }
        total += (potential * kinetic);
    }
   
    cout << "Total: " << total << endl;

    return 0;
}