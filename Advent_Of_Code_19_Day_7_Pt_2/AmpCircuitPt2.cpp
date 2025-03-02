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
3,8,1001,8,10,8,105,1,0,0,21,42,55,64,85,98,179,260,341,422,99999,3,9,101,2,9,9,102,5,9,9,1001,9,2,9,1002,9,5,9,4,9,99,3,9,1001,9,5,9,1002,9,4,9,4,9,99,3,9,101,3,9,9,4,9,99,3,9,1002,9,4,9,101,3,9,9,102,5,9,9,101,4,9,9,4,9,99,3,9,1002,9,3,9,1001,9,3,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,99,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,99,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,99
); // Insert the puzzle input here
        
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

    for (int i = 5; i < 10; ++i) {
        for (int j = 5; j < 10; ++j) {
            for (int k = 5; k < 10; ++k) {
                for (int l = 5; l < 10; ++l) {
                    for (int m = 5; m < 10; ++m) {
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

    vector<int> currPos;
        
    for (unsigned int i = 0; i < thrusterSignals.size(); ++i) {    
        int output = 0;
        int ampCount = 0;

        currPos.clear();
        currPos.push_back(0);
        currPos.push_back(0);
        currPos.push_back(0);
        currPos.push_back(0);
        currPos.push_back(0);

        while (true) {
            int inputCount = 0;

            intcode.clear();

            for (unsigned int k = 0; k < originalIntcode.size(); ++k) {
                intcode.push_back(originalIntcode.at(k));
            }

            int input = thrusterSignals.at(i).at(ampCount % 5);
            int input2 = output;

            while (intcode.at(currPos.at(ampCount % 5)) != 99) {
                int twoDigitOpcode = 0;
                int firstParamMode = 0;
                int secondParamMode = 0;

                int currPosAsDigits = intcode.at(currPos.at(ampCount % 5));

                twoDigitOpcode = currPosAsDigits % 100;
                currPosAsDigits = currPosAsDigits / 100;
                firstParamMode = currPosAsDigits % 10;
                currPosAsDigits = currPosAsDigits / 10;
                secondParamMode = currPosAsDigits % 10;
                
                if ((intcode.at(currPos.at(ampCount % 5)) == 1) || (twoDigitOpcode == 1)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 
                        intcode.at(currPos.at(ampCount % 5) + 1) + intcode.at(currPos.at(ampCount % 5) + 2);
                        currPos.at(ampCount % 5) += 4;
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 
                        intcode.at(currPos.at(ampCount % 5) + 1) + intcode.at(intcode.at(currPos.at(ampCount % 5) + 2));
                        currPos.at(ampCount % 5) += 4;
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) + intcode.at(currPos.at(ampCount % 5) + 2);
                        currPos.at(ampCount % 5) += 4;
                    }
                    else {
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) + intcode.at(intcode.at(currPos.at(ampCount % 5) + 2));
                        currPos.at(ampCount % 5) += 4;
                    }
                }
                else if ((intcode.at(currPos.at(ampCount % 5)) == 2) || (twoDigitOpcode == 2)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 
                        intcode.at(currPos.at(ampCount % 5) + 1) * intcode.at(currPos.at(ampCount % 5) + 2);
                        currPos.at(ampCount % 5) += 4;
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 
                        intcode.at(currPos.at(ampCount % 5) + 1) * intcode.at(intcode.at(currPos.at(ampCount % 5) + 2));
                        currPos.at(ampCount % 5) += 4;
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) * intcode.at(currPos.at(ampCount % 5) + 2);
                        currPos.at(ampCount % 5) += 4;
                    }
                    else {
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 
                        intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) * intcode.at(intcode.at(currPos.at(ampCount % 5) + 2));
                        currPos.at(ampCount % 5) += 4;
                    }
                }
                else if ((intcode.at(currPos.at(ampCount % 5)) == 3) || (twoDigitOpcode == 3)) {
                    if ((ampCount > 4) || (inputCount > 0)) {
                        if (firstParamMode == 1) {
                            intcode.at(currPos.at(ampCount % 5) + 1) = input2;
                            currPos.at(ampCount % 5) += 2;
                            inputCount += 1;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) = input2;
                            currPos.at(ampCount % 5) += 2;
                            inputCount += 1;
                        } 
                    }
                    else {
                        if (firstParamMode == 1) {
                            intcode.at(currPos.at(ampCount % 5) + 1) = input;
                            currPos.at(ampCount % 5) += 2;
                            inputCount += 1;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) = input;
                            currPos.at(ampCount % 5) += 2;
                            inputCount += 1;
                        }
                    }  
                }
                else if ((intcode.at(currPos.at(ampCount % 5)) == 4) || (twoDigitOpcode == 4)) {
                    if (firstParamMode == 1) {
                        cout << intcode.at(currPos.at(ampCount % 5) + 1) << endl;
                        currPos.at(ampCount % 5) += 2;
                    }
                    else {
                        output = intcode.at(intcode.at(currPos.at(ampCount % 5) + 1));
                        currPos.at(ampCount % 5) += 2;
                        ampCount += 1;
                        break; 
                    }
                }
                else if ((intcode.at(currPos.at(ampCount % 5)) == 5) || (twoDigitOpcode == 5)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        if (intcode.at(currPos.at(ampCount % 5) + 1) > 0) {
                            currPos.at(ampCount % 5) = intcode.at(currPos.at(ampCount % 5) + 2);
                        }
                        else {
                            currPos.at(ampCount % 5) += 2;
                        }
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        if (intcode.at(currPos.at(ampCount % 5) + 1) > 0) {
                            currPos.at(ampCount % 5) = intcode.at(intcode.at(currPos.at(ampCount % 5) + 2));
                        }
                        else {
                            currPos.at(ampCount % 5) += 2;
                        }
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        if (intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) > 0) {
                            currPos.at(ampCount % 5) = intcode.at(currPos.at(ampCount % 5) + 2);
                        }
                        else {
                            currPos.at(ampCount % 5) += 2;
                        }
                    }
                    else {
                        if (intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) > 0) {
                            currPos.at(ampCount % 5) = intcode.at(intcode.at(currPos.at(ampCount % 5) + 2));
                        }
                        else {
                            currPos.at(ampCount % 5) += 2;
                        }
                    }
                }
                else if ((intcode.at(currPos.at(ampCount % 5)) == 6) || (twoDigitOpcode == 6)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        if (intcode.at(currPos.at(ampCount % 5) + 1) == 0) {
                            currPos.at(ampCount % 5) = intcode.at(currPos.at(ampCount % 5) + 2);
                        }
                        else {
                            currPos.at(ampCount % 5) += 2;
                        }
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        if (intcode.at(currPos.at(ampCount % 5) + 1) == 0) {
                            currPos.at(ampCount % 5) = intcode.at(intcode.at(currPos.at(ampCount % 5) + 2));
                        }
                        else {
                            currPos.at(ampCount % 5) += 2;
                        }
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        if (intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) == 0) {
                            currPos.at(ampCount % 5) = intcode.at(currPos.at(ampCount % 5) + 2);
                        }
                        else {
                            currPos.at(ampCount % 5) += 2;
                        }
                    }
                    else {
                        if (intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) == 0) {
                            currPos.at(ampCount % 5) = intcode.at(intcode.at(currPos.at(ampCount % 5) + 2));
                        }
                        else {
                            currPos.at(ampCount % 5) += 2;
                        }
                    }
                }
                else if ((intcode.at(currPos.at(ampCount % 5)) == 7) || (twoDigitOpcode == 7)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        if (intcode.at(currPos.at(ampCount % 5) + 1) < intcode.at(currPos.at(ampCount % 5) + 2)) {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 1;
                            currPos.at(ampCount % 5) += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 0;
                            currPos.at(ampCount % 5) += 4;
                        }
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        if (intcode.at(currPos.at(ampCount % 5) + 1) < intcode.at(intcode.at(currPos.at(ampCount % 5) + 2))) {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 1;
                            currPos.at(ampCount % 5) += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 0;
                            currPos.at(ampCount % 5) += 4;
                        }
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        if (intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) < intcode.at(currPos.at(ampCount % 5) + 2)) {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 1;
                            currPos.at(ampCount % 5) += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 0;
                            currPos.at(ampCount % 5) += 4;
                        }
                    }
                    else {
                        if (intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) < intcode.at(intcode.at(currPos.at(ampCount % 5) + 2))) {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 1;
                            currPos.at(ampCount % 5) += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 0;
                            currPos.at(ampCount % 5) += 4;
                        }
                    }
                }
                else if ((intcode.at(currPos.at(ampCount % 5)) == 8) || (twoDigitOpcode == 8)) {
                    if ((firstParamMode == 1) && (secondParamMode == 1)) {
                        if (intcode.at(currPos.at(ampCount % 5) + 1) == intcode.at(currPos.at(ampCount % 5) + 2)) {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 1;
                            currPos.at(ampCount % 5) += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 0;
                            currPos.at(ampCount % 5) += 4;
                        }
                    }
                    else if ((firstParamMode == 1) && (secondParamMode == 0)) {
                        if (intcode.at(currPos.at(ampCount % 5) + 1) == intcode.at(intcode.at(currPos.at(ampCount % 5) + 2))) {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 1;
                            currPos.at(ampCount % 5) += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 0;
                            currPos.at(ampCount % 5) += 4;
                        }
                    }
                    else if ((firstParamMode == 0) && (secondParamMode == 1)) {
                        if (intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) == intcode.at(currPos.at(ampCount % 5) + 2)) {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 1;
                            currPos.at(ampCount % 5) += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 0;
                            currPos.at(ampCount % 5) += 4;
                        }
                    }
                    else {
                        if (intcode.at(intcode.at(currPos.at(ampCount % 5) + 1)) == intcode.at(intcode.at(currPos.at(ampCount % 5) + 2))) {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 1;
                            currPos.at(ampCount % 5) += 4;
                        }
                        else {
                            intcode.at(intcode.at(currPos.at(ampCount % 5) + 3)) = 0;
                            currPos.at(ampCount % 5) += 4;
                        }
                    }
                }
                else {
                    currPos.at(ampCount % 5) += 1;
                }
            }

            if (output > maxOutput) {
                maxOutput = output;
            }
            
            if (intcode.at(currPos.at(4)) == 99) {
                break;
            } 
        } 
    }

    cout << maxOutput << endl; 
    return 0;
} 