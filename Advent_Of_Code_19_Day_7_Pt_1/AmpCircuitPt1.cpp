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
        
    vector<int> originalIntcode;
    vector<int> intcode;
    string currIntString = "";
    int currInt;

    for (unsigned int i = 0; i < inputString.size(); ++i) {
        if (inputString.at(i) == ',') {
            currInt = stoi(currIntString);
            originalIntcode.push_back(currInt);
            currIntString = "";
        }
        else if (i == inputString.size() - 1) {
            currIntString += inputString.at(i);
            currInt = stoi(currIntString);
            originalIntcode.push_back(currInt);
        }
        else if (isspace(inputString.at(i))) {
            continue;
        }
        else { 
            currIntString +=inputString.at(i);
        }
    }

    vector<vector<int>> thrusterSignals;
    vector<int> thrusterSignal;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                for (int l = 0; l < 5; ++l) {
                    for (int m = 0; m < 5; ++m) {
                        if ((i != j) && (i != k) && (i != l) && (i != m) &&
                        (j != k) && (j != l) && (j != m) && (k != l) && (k != m) &&
                        (l != m)) {
                            thrusterSignal.clear();
                            thrusterSignal.push_back(i);
                            thrusterSignal.push_back(j);
                            thrusterSignal.push_back(k);
                            thrusterSignal.push_back(l);
                            thrusterSignal.push_back(m);
                            thrusterSignals.push_back(thrusterSignal);
                        }
                    }
                }
            }
        } 
    }

    int maxOutput = 0;
        
    for (unsigned int i = 0; i < thrusterSignals.size(); ++i) {    
        int output = 0;

        for (unsigned int j = 0; j < thrusterSignals.at(i).size(); ++j) {

            intcode.clear();

            for (unsigned int k = 0; k < originalIntcode.size(); ++k) {
                intcode.push_back(originalIntcode.at(k));
            }

            int currPos = 0;
            int inputCount = 0;
            int input = thrusterSignals.at(i).at(j);
            int input2 = output;

            while (intcode.at(currPos) != 99) {
                int twoDigitOpcode = 0;
                int firstParamMode = 0;
                int secondParamMode = 0;

                int currPosAsDigits = intcode.at(currPos);

                twoDigitOpcode = currPosAsDigits % 100;
                currPosAsDigits = currPosAsDigits / 100;
                firstParamMode = currPosAsDigits % 10;
                currPosAsDigits = currPosAsDigits / 10;
                secondParamMode = currPosAsDigits % 10;
                
                if ((intcode.at(currPos) == 1) || (twoDigitOpcode == 1)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) + intcode.at(currPos + 2);
                        currPos += 4;
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) + intcode.at(intcode.at(currPos + 2));
                        currPos += 4;
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) + intcode.at(currPos + 2);
                        currPos += 4;
                    }
                    else {
                        intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) + intcode.at(intcode.at(currPos + 2));
                        currPos += 4;
                    }
                }
                else if ((intcode.at(currPos) == 2) || (twoDigitOpcode == 2)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) * intcode.at(currPos + 2);
                        currPos += 4;
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) * intcode.at(intcode.at(currPos + 2));
                        currPos += 4;
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) * intcode.at(currPos + 2);
                        currPos += 4;
                    }
                    else {
                        intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) * intcode.at(intcode.at(currPos + 2));
                        currPos += 4;
                    }
                }
                else if ((intcode.at(currPos) == 3) || (twoDigitOpcode == 3)) {
                    if (inputCount == 1) {
                        if (firstParamMode == 1) {
                            intcode.at(currPos + 1) = input2;
                            currPos += 2;
                            ++inputCount;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 1)) = input2;
                            currPos += 2;
                            ++inputCount;
                        } 
                    }
                    else {
                        if (firstParamMode == 1) {
                            intcode.at(currPos + 1) = input;
                            currPos += 2;
                            ++inputCount;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 1)) = input;
                            currPos += 2;
                            ++inputCount;
                        }
                    }  
                }
                else if ((intcode.at(currPos) == 4) || (twoDigitOpcode == 4)) {
                    if (firstParamMode == 1) {
                        cout << intcode.at(currPos + 1) << endl;
                        currPos += 2;
                    }
                    else {
                        output = intcode.at(intcode.at(currPos + 1));
                        currPos += 2;
                    }
                }
                else if ((intcode.at(currPos) == 5) || (twoDigitOpcode == 5)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        if (intcode.at(currPos + 1) > 0) {
                            currPos = intcode.at(currPos + 2);
                        }
                        else {
                            currPos += 2;
                        }
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        if (intcode.at(currPos + 1) > 0) {
                            currPos = intcode.at(intcode.at(currPos + 2));
                        }
                        else {
                            currPos += 2;
                        }
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        if (intcode.at(intcode.at(currPos + 1)) > 0) {
                            currPos = intcode.at(currPos + 2);
                        }
                        else {
                            currPos += 2;
                        }
                    }
                    else {
                        if (intcode.at(intcode.at(currPos + 1)) > 0) {
                            currPos = intcode.at(intcode.at(currPos + 2));
                        }
                        else {
                            currPos += 2;
                        }
                    }
                }
                else if ((intcode.at(currPos) == 6) || (twoDigitOpcode == 6)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        if (intcode.at(currPos + 1) == 0) {
                            currPos = intcode.at(currPos + 2);
                        }
                        else {
                            currPos += 2;
                        }
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        if (intcode.at(currPos + 1) == 0) {
                            currPos = intcode.at(intcode.at(currPos + 2));
                        }
                        else {
                            currPos += 2;
                        }
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        if (intcode.at(intcode.at(currPos + 1)) == 0) {
                            currPos = intcode.at(currPos + 2);
                        }
                        else {
                            currPos += 2;
                        }
                    }
                    else {
                        if (intcode.at(intcode.at(currPos + 1)) == 0) {
                            currPos = intcode.at(intcode.at(currPos + 2));
                        }
                        else {
                            currPos += 2;
                        }
                    }
                }
                else if ((intcode.at(currPos) == 7) || (twoDigitOpcode == 7)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        if (intcode.at(currPos + 1) < intcode.at(currPos + 2)) {
                            intcode.at(intcode.at(currPos + 3)) = 1;
                            currPos += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 3)) = 0;
                            currPos += 4;
                        }
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        if (intcode.at(currPos + 1) < intcode.at(intcode.at(currPos + 2))) {
                            intcode.at(intcode.at(currPos + 3)) = 1;
                            currPos += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 3)) = 0;
                            currPos += 4;
                        }
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        if (intcode.at(intcode.at(currPos + 1)) < intcode.at(currPos + 2)) {
                            intcode.at(intcode.at(currPos + 3)) = 1;
                            currPos += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 3)) = 0;
                            currPos += 4;
                        }
                    }
                    else {
                        if (intcode.at(intcode.at(currPos + 1)) < intcode.at(intcode.at(currPos + 2))) {
                            intcode.at(intcode.at(currPos + 3)) = 1;
                            currPos += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 3)) = 0;
                            currPos += 4;
                        }
                    }
                }
                else if ((intcode.at(currPos) == 8) || (twoDigitOpcode == 8)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        if (intcode.at(currPos + 1) == intcode.at(currPos + 2)) {
                            intcode.at(intcode.at(currPos + 3)) = 1;
                            currPos += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 3)) = 0;
                            currPos += 4;
                        }
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        if (intcode.at(currPos + 1) == intcode.at(intcode.at(currPos + 2))) {
                            intcode.at(intcode.at(currPos + 3)) = 1;
                            currPos += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 3)) = 0;
                            currPos += 4;
                        }
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        if (intcode.at(intcode.at(currPos + 1)) == intcode.at(currPos + 2)) {
                            intcode.at(intcode.at(currPos + 3)) = 1;
                            currPos += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 3)) = 0;
                            currPos += 4;
                        }
                    }
                    else {
                        if (intcode.at(intcode.at(currPos + 1)) == intcode.at(intcode.at(currPos + 2))) {
                            intcode.at(intcode.at(currPos + 3)) = 1;
                            currPos += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos + 3)) = 0;
                            currPos += 4;
                        }
                    }
                }
                else {
                    currPos += 1;
                }
            }

            if ((j == 4) && (output > maxOutput)) {
                maxOutput = output;
            }
        }    
    }

    cout << maxOutput << endl; 
    return 0;
} 