#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MULTI_LINE_STRING(...) #__VA_ARGS__

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoll;

int main() {
    string inputString = MULTI_LINE_STRING(
3,1033,1008,1033,1,1032,1005,1032,31,1008,1033,2,1032,1005,1032,58,1008,1033,3,1032,1005,1032,81,1008,1033,4,1032,1005,1032,104,99,101,0,1034,1039,1001,1036,0,1041,1001,1035,-1,1040,1008,1038,0,1043,102,-1,1043,1032,1,1037,1032,1042,1105,1,124,101,0,1034,1039,101,0,1036,1041,1001,1035,1,1040,1008,1038,0,1043,1,1037,1038,1042,1106,0,124,1001,1034,-1,1039,1008,1036,0,1041,1001,1035,0,1040,1001,1038,0,1043,1002,1037,1,1042,1105,1,124,1001,1034,1,1039,1008,1036,0,1041,102,1,1035,1040,101,0,1038,1043,1002,1037,1,1042,1006,1039,217,1006,1040,217,1008,1039,40,1032,1005,1032,217,1008,1040,40,1032,1005,1032,217,1008,1039,1,1032,1006,1032,165,1008,1040,33,1032,1006,1032,165,1101,0,2,1044,1106,0,224,2,1041,1043,1032,1006,1032,179,1101,1,0,1044,1106,0,224,1,1041,1043,1032,1006,1032,217,1,1042,1043,1032,1001,1032,-1,1032,1002,1032,39,1032,1,1032,1039,1032,101,-1,1032,1032,101,252,1032,211,1007,0,43,1044,1105,1,224,1101,0,0,1044,1106,0,224,1006,1044,247,1002,1039,1,1034,1002,1040,1,1035,102,1,1041,1036,1001,1043,0,1038,101,0,1042,1037,4,1044,1105,1,0,13,30,60,64,5,28,36,24,67,12,1,67,32,39,14,78,29,17,38,88,79,9,62,25,15,18,88,25,7,81,38,41,10,69,86,32,11,33,1,10,22,84,14,92,48,79,10,3,62,33,61,13,93,78,20,63,68,17,80,34,12,8,23,61,90,51,17,84,37,46,64,25,3,73,19,45,99,41,62,21,77,8,17,89,9,13,84,75,85,14,53,60,6,29,76,63,14,23,63,61,93,72,17,41,28,94,5,3,19,47,57,55,14,34,38,79,85,40,13,22,99,67,72,15,62,15,6,63,3,90,2,87,20,84,15,50,70,27,18,78,21,70,48,52,2,99,92,55,3,46,41,93,99,88,13,39,4,45,71,3,96,1,91,59,31,53,23,25,82,32,50,16,60,38,78,34,59,30,15,51,92,3,22,26,62,60,37,42,74,28,21,76,7,24,70,18,40,11,81,41,9,73,62,12,66,81,9,3,74,62,11,6,56,16,34,20,78,79,1,97,17,39,87,15,12,77,94,28,22,66,45,59,39,2,6,52,6,72,49,17,92,15,86,18,92,79,67,20,22,72,10,72,3,52,26,77,78,41,97,36,59,88,24,57,12,38,90,53,14,38,67,2,36,44,93,99,10,41,49,3,16,7,63,32,11,15,81,12,91,39,62,19,83,6,91,28,19,80,38,23,63,31,71,14,58,8,21,71,21,21,81,38,26,32,29,82,52,28,72,54,97,41,65,96,75,1,48,28,80,66,25,47,49,29,87,51,12,50,70,36,60,81,29,77,76,55,25,40,45,83,91,26,72,99,12,47,11,20,27,52,9,98,17,99,27,37,62,25,3,15,73,66,22,5,85,5,20,98,20,38,62,78,21,16,59,28,98,38,31,2,40,46,87,14,48,33,80,48,36,27,56,21,1,50,83,3,61,92,20,52,16,50,10,86,9,98,39,56,25,50,42,39,91,81,56,25,70,44,24,15,99,4,20,55,12,98,27,65,20,77,97,76,36,42,87,6,11,79,65,16,65,44,13,90,13,48,79,13,95,60,19,55,24,66,4,53,11,23,68,14,97,53,45,14,16,93,18,29,83,5,6,77,19,70,97,34,20,70,52,11,74,14,72,10,36,44,33,45,19,38,36,77,5,37,51,1,55,17,2,48,23,18,2,34,90,97,24,30,51,66,33,70,51,37,31,51,37,65,55,18,8,66,4,65,62,26,93,29,88,3,75,73,24,23,67,1,13,68,7,36,87,62,48,1,31,45,28,62,86,24,98,1,59,49,37,26,62,36,44,66,18,17,97,92,40,36,65,80,84,5,84,6,79,87,36,31,96,15,71,96,2,72,11,81,95,94,41,54,31,58,25,74,24,51,81,38,32,73,22,96,40,62,22,59,74,39,25,86,2,55,20,61,40,37,88,69,1,60,42,18,31,54,13,27,19,93,34,41,99,33,89,20,16,52,84,32,94,31,6,61,25,1,61,1,38,78,87,39,31,39,26,68,42,36,2,94,66,2,67,30,80,2,95,65,40,54,50,33,11,23,97,89,1,31,56,9,35,49,92,55,23,84,48,91,20,7,72,25,55,3,85,3,16,40,90,22,99,44,38,86,98,11,76,26,76,13,82,80,24,93,4,15,64,95,58,15,85,25,57,29,66,3,66,19,98,57,24,44,59,35,76,48,31,92,33,94,68,56,41,45,15,46,5,68,15,65,34,73,49,68,17,78,28,80,24,59,26,74,21,52,1,94,5,61,41,88,37,56,1,49,0,0,21,21,1,10,1,0,0,0,0,0,0
); // Insert the puzzle input here
   
    vector<long long int> intcode(1000000000);
    string currLongString = "";
    long long int currLong;
    int count = 0;

    for (unsigned int i = 0; i < inputString.size(); ++i) {
        if (inputString.at(i) == ',') {
            currLong = stoll(currLongString);
            intcode.at(count) = currLong;
            ++count;
            currLongString = "";
        }
        else if (i == inputString.size() - 1) {
            currLongString += inputString.at(i);
            currLong = stol(currLongString);
            intcode.at(count) = currLong;
            ++count;
        }
        else if (isspace(inputString.at(i))) {
            continue;
        }
        else { 
            currLongString += inputString.at(i);
        }
    }

    long long int currPos = 0;
    long long int relativeBase = 0;
    vector<long long int> commands(4);
    
    commands.at(0) = 1;
    commands.at(1) = 4;
    commands.at(2) = 2;
    commands.at(3) = 3;

    long long int commandIndex = 0;
    long long int input = commands.at(commandIndex);
    long long int currRow = 500;
    long long int currCol = 500;
    bool found = false;
    long long int foundRow = 0;
    long long int foundCol = 0;

    char** mapped = new char*[1000];
    for (int i = 0; i < 1000; ++i) {
        mapped[i] = new char[1000];
        for (int j = 0; j < 1000; ++j) {
            mapped[i][j] = '_';
        }
    }
    mapped[currRow][currCol] = '.';

    while (intcode.at(currPos) != static_cast<long long int>(99) && !found) {
        long long int twoDigitOpcode = 0;
        long long int firstParamMode = 0;
        long long int secondParamMode = 0;
        long long int thirdParamMode = 0;

        long long int currPosAsDigits = intcode.at(currPos);

        twoDigitOpcode = currPosAsDigits % static_cast<long long int>(100);
        currPosAsDigits = currPosAsDigits / static_cast<long long int>(100);
        firstParamMode = currPosAsDigits % static_cast<long long int>(10);
        currPosAsDigits = currPosAsDigits / static_cast<long long int>(10);
        secondParamMode = currPosAsDigits % static_cast<long long int>(10);
        currPosAsDigits = currPosAsDigits / static_cast<long long int>(10);
        thirdParamMode = currPosAsDigits % static_cast<long long int>(10);
        
        if ((intcode.at(currPos) == 1) || (twoDigitOpcode == 1)) {
            if ((firstParamMode == 1) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) + intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(currPos + 1) + intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) + intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(currPos + 1) + intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) + intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1)) + intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) + intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1)) + intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) + intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(currPos + 1) + intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1) + relativeBase) + intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1) + relativeBase) + intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1) + relativeBase) + intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1) + relativeBase) + intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1) + relativeBase) + intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1) + relativeBase) + intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) + intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1)) + intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
        }
        else if ((intcode.at(currPos) == 2) || (twoDigitOpcode == 2)) {
            if ((firstParamMode == 1) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) * intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(currPos + 1) * intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) * intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(currPos + 1) * intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) * intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1)) * intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) * intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1)) * intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(currPos + 1) * intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(currPos + 1) * intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1) + relativeBase) * intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1) + relativeBase) * intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1) + relativeBase) * intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1) + relativeBase) * intcode.at(currPos + 2);
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1) + relativeBase) * intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1) + relativeBase) * intcode.at(intcode.at(currPos + 2) + relativeBase);
            currPos += 4;
            }
            else if ((firstParamMode == 0) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) * intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
            else {
            intcode.at(intcode.at(currPos + 3) + relativeBase) = intcode.at(intcode.at(currPos + 1)) * intcode.at(intcode.at(currPos + 2));
            currPos += 4;
            }
        }
        else if ((intcode.at(currPos) == 3) || (twoDigitOpcode == 3)) {
            if (firstParamMode == 2) {
            intcode.at(intcode.at(currPos + 1) + relativeBase) = input;
            currPos += 2;
            }
            else {
            intcode.at(intcode.at(currPos + 1)) = input;
            currPos += 2;
            }   
        }
        else if ((intcode.at(currPos) == 4) || (twoDigitOpcode == 4)) {
            if (firstParamMode == 1) {
                if (intcode.at(currPos + 1) == 0) {
                    if (input == 1) {
                        mapped[currRow + 1][currCol] = '#';
                    }
                    else if (input == 2) {
                        mapped[currRow - 1][currCol] = '#';
                    }
                    else if (input == 3) {
                        mapped[currRow][currCol - 1] = '#';                   
                    }
                    else {
                        mapped[currRow][currCol + 1] = '#';
                    }
                    commandIndex = (commandIndex + 1) % static_cast<long long int>(4);
                    input = commands.at(commandIndex);
                }
                else if (intcode.at(currPos + 1) == 1) {
                    if (input == 1) {
                        currRow += 1;
                    }
                    else if (input == 2) {
                        currRow -= 1;
                    }
                    else if (input == 3) {
                        currCol -= 1;                   
                    }
                    else {
                        currCol += 1;
                    }
                    mapped[currRow][currCol] = '.';
                    if (commandIndex == 0) {
                        commandIndex = static_cast<long long int>(3);
                    }
                    else {
                        commandIndex = (commandIndex - 1) % static_cast<long long int>(4);
                    }
                    input = commands.at(commandIndex);
                }
                else if (intcode.at(currPos + 1) == 2) {
                    if (input == 1) {
                        currRow += 1;
                    }
                    else if (input == 2) {
                        currRow -= 1;
                    }
                    else if (input == 3) {
                        currCol -= 1;                   
                    }
                    else {
                        currCol += 1;
                    }
                    foundRow = currRow;
                    foundCol = currCol;
                    mapped[currRow][currCol] = 'o';
                    found = true;
                }
                currPos += 2;
            }
            else if (firstParamMode == 2) {
                if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 0) {
                    if (input == 1) {
                        mapped[currRow + 1][currCol] = '#';
                    }
                    else if (input == 2) {
                        mapped[currRow - 1][currCol] = '#';
                    }
                    else if (input == 3) {
                        mapped[currRow][currCol - 1] = '#';                   
                    }
                    else {
                        mapped[currRow][currCol + 1] = '#';
                    }
                    commandIndex = (commandIndex + 1) % static_cast<long long int>(4);
                    input = commands.at(commandIndex);
                }
                else if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 1) {
                    if (input == 1) {
                        currRow += 1;
                    }
                    else if (input == 2) {
                        currRow -= 1;
                    }
                    else if (input == 3) {
                        currCol -= 1;                   
                    }
                    else {
                        currCol += 1;
                    }
                    mapped[currRow][currCol] = '.';
                    if (commandIndex == 0) {
                        commandIndex = static_cast<long long int>(3);
                    }
                    else {
                        commandIndex = (commandIndex - 1) % static_cast<long long int>(4);
                    }
                    input = commands.at(commandIndex);
                }
                else if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 2) {
                    if (input == 1) {
                        currRow += 1;
                    }
                    else if (input == 2) {
                        currRow -= 1;
                    }
                    else if (input == 3) {
                        currCol -= 1;                   
                    }
                    else {
                        currCol += 1;
                    }
                    foundRow = currRow;
                    foundCol = currCol;
                    mapped[currRow][currCol] = 'o';
                    found = true;
                }
                currPos += 2;
            }
            else {
                if (intcode.at(intcode.at(currPos + 1)) == 0) {
                    if (input == 1) {
                        mapped[currRow + 1][currCol] = '#';
                    }
                    else if (input == 2) {
                        mapped[currRow - 1][currCol] = '#';
                    }
                    else if (input == 3) {
                        mapped[currRow][currCol - 1] = '#';                   
                    }
                    else {
                        mapped[currRow][currCol + 1] = '#';
                    }
                    commandIndex = (commandIndex + 1) % static_cast<long long int>(4);
                    input = commands.at(commandIndex);
                }
                else if (intcode.at(intcode.at(currPos + 1)) == 1) {
                    if (input == 1) {
                        currRow += 1;
                    }
                    else if (input == 2) {
                        currRow -= 1;
                    }
                    else if (input == 3) {
                        currCol -= 1;                   
                    }
                    else {
                        currCol += 1;
                    }
                    mapped[currRow][currCol] = '.';
                    if (commandIndex == 0) {
                        commandIndex = static_cast<long long int>(3);
                    }
                    else {
                        commandIndex = (commandIndex - 1) % static_cast<long long int>(4);
                    }
                    input = commands.at(commandIndex);
                }
                else if (intcode.at(intcode.at(currPos + 1)) == 2) {
                    if (input == 1) {
                        currRow += 1;
                    }
                    else if (input == 2) {
                        currRow -= 1;
                    }
                    else if (input == 3) {
                        currCol -= 1;                   
                    }
                    else {
                        currCol += 1;
                    }
                    foundRow = currRow;
                    foundCol = currCol;
                    mapped[currRow][currCol] = 'o';
                    found = true;
                }
                currPos += 2;
            }
        }
        else if ((intcode.at(currPos) == 5) || (twoDigitOpcode == 5)) {
            if ((firstParamMode == 1) && (secondParamMode == 1)) {
            if (intcode.at(currPos + 1) > 0) {
                currPos = intcode.at(currPos + 2);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0)) {
            if (intcode.at(currPos + 1) > 0) {
                currPos = intcode.at(intcode.at(currPos + 2));
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1)) > 0) {
                currPos = intcode.at(currPos + 2);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1)) > 0) {
                currPos = intcode.at(intcode.at(currPos + 2) + relativeBase);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2)) {
            if (intcode.at(currPos + 1) > 0) {
                currPos = intcode.at(intcode.at(currPos + 2) + relativeBase);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) > 0) {
                currPos = intcode.at(intcode.at(currPos + 2));
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) > 0) {
                currPos = intcode.at(currPos + 2);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) > 0) {
                currPos = intcode.at(intcode.at(currPos + 2) + relativeBase);
            }
            else {
                currPos += 3;
            }
            }
            else {
            if (intcode.at(intcode.at(currPos + 1)) > 0) {
                currPos = intcode.at(intcode.at(currPos + 2));
            }
            else {
                currPos += 3;
            }
            }
        }
        else if ((intcode.at(currPos) == 6) || (twoDigitOpcode == 6)) {
            if ((firstParamMode == 1) && (secondParamMode == 1)) {
            if (intcode.at(currPos + 1) == 0) {
                currPos = intcode.at(currPos + 2);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0)) {
            if (intcode.at(currPos + 1) == 0) {
                currPos = intcode.at(intcode.at(currPos + 2));
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1)) == 0) {
                currPos = intcode.at(currPos + 2);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1)) == 0) {
                currPos = intcode.at(intcode.at(currPos + 2) + relativeBase);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2)) {
            if (intcode.at(currPos + 1) == 0) {
                currPos = intcode.at(intcode.at(currPos + 2) + relativeBase);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 0) {
                currPos = intcode.at(intcode.at(currPos + 2));
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 0) {
                currPos = intcode.at(currPos + 2);
            }
            else {
                currPos += 3;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 0) {
                currPos = intcode.at(intcode.at(currPos + 2) + relativeBase);
            }
            else {
                currPos += 3;
            }
            }
            else {
            if (intcode.at(intcode.at(currPos + 1)) == 0) {
                currPos = intcode.at(intcode.at(currPos + 2));
            }
            else {
                currPos += 3;
            }
            }
        }
        else if ((intcode.at(currPos) == 7) || (twoDigitOpcode == 7)) {
            if ((firstParamMode == 1) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(currPos + 1) < intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            if (intcode.at(currPos + 1) < intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(currPos + 1) < intcode.at(intcode.at(currPos + 2))) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0) && (thirdParamMode == 2)) {
            if (intcode.at(currPos + 1) < intcode.at(intcode.at(currPos + 2))) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1)) < intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1)) < intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1)) < intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1)) < intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(currPos + 1) < intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            if (intcode.at(currPos + 1) < intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) < intcode.at(intcode.at(currPos + 2))) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) < intcode.at(intcode.at(currPos + 2))) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) < intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) < intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) < intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) < intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)){
            if (intcode.at(intcode.at(currPos + 1)) < intcode.at(intcode.at(currPos + 2))) {
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
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
        }
        else if ((intcode.at(currPos) == 8) || (twoDigitOpcode == 8)) {
            if ((firstParamMode == 1) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(currPos + 1) == intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            if (intcode.at(currPos + 1) == intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(currPos + 1) == intcode.at(intcode.at(currPos + 2))) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 0) && (thirdParamMode == 2)) {
            if (intcode.at(currPos + 1) == intcode.at(intcode.at(currPos + 2))) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1)) == intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1)) == intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1)) == intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1)) == intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(currPos + 1) == intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 1) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            if (intcode.at(currPos + 1) == intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) == intcode.at(intcode.at(currPos + 2))) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 0) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) == intcode.at(intcode.at(currPos + 2))) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) == intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 1) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) == intcode.at(currPos + 2)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) == intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3)) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3)) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 2) && (secondParamMode == 2) && (thirdParamMode == 2)) {
            if (intcode.at(intcode.at(currPos + 1) + relativeBase) == intcode.at(intcode.at(currPos + 2) + relativeBase)) {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
            else if ((firstParamMode == 0) && (secondParamMode == 0) && (thirdParamMode == 0 || thirdParamMode == 1)) {
            if (intcode.at(intcode.at(currPos + 1)) == intcode.at(intcode.at(currPos + 2))) {
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
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 1;
                currPos += 4;
            }
            else {
                intcode.at(intcode.at(currPos + 3) + relativeBase) = 0;
                currPos += 4;
            }
            }
        }
        else if ((intcode.at(currPos) == 9) || (twoDigitOpcode == 9)) {
            if (firstParamMode == 2) {
            relativeBase += intcode.at(intcode.at(currPos + 1) + relativeBase);
            currPos += 2;
            }
            else if (firstParamMode == 1) {
            relativeBase += intcode.at(currPos + 1);
            currPos += 2;
            }
            else {
            relativeBase += intcode.at(intcode.at(currPos + 1));
            currPos += 2;
            }
        }
        else {
            currPos += 1;
        }
    }

    vector<int> visitedRow(1000 * 1000);
    vector<int> visitedCol(1000 * 1000);
    int visitedCount = 0;
    currRow = 500;
    currCol = 500;
    visitedRow.at(visitedCount) = currRow;
    visitedCol.at(visitedCount) = currCol;
    ++visitedCount;
    found = false;
    int pathLength = 0;

    while (!found) {
        int tempAdded = 0;
        for (int i = 0; i < visitedCount; ++i) {
            if (mapped[visitedRow.at(i) + 1][visitedCol.at(i)] == '.') {
                bool upInVisited = false;
                for (int j = 0; j < visitedCount; ++j) {
                    if ((visitedRow.at(i) + 1 == visitedRow.at(j)) &&
                        (visitedCol.at(i) == visitedCol.at(j))) {
                        upInVisited = true;
                    }
                }
                if (!upInVisited) {
                    visitedRow.at(visitedCount + tempAdded) = visitedRow.at(i) + 1;
                    visitedCol.at(visitedCount + tempAdded) = visitedCol.at(i);
                    ++tempAdded;
                }
            }
            else if (mapped[visitedRow.at(i) + 1][visitedCol.at(i)] == 'o') {
                found = true;
            }

            if (mapped[visitedRow.at(i) - 1][visitedCol.at(i)] == '.') {
                bool downInVisited = false;
                for (int j = 0; j < visitedCount; ++j) {
                    if ((visitedRow.at(i) - 1 == visitedRow.at(j)) &&
                        (visitedCol.at(i) == visitedCol.at(j))) {
                        downInVisited = true;
                    }
                }
                if (!downInVisited) {
                    visitedRow.at(visitedCount + tempAdded) = visitedRow.at(i) - 1;
                    visitedCol.at(visitedCount + tempAdded) = visitedCol.at(i);
                    ++tempAdded;
                }
            }
            else if (mapped[visitedRow.at(i) - 1][visitedCol.at(i)] == 'o') {
                found = true;
            }

            if (mapped[visitedRow.at(i)][visitedCol.at(i) + 1] == '.') {
                bool rightInVisited = false;
                for (int j = 0; j < visitedCount; ++j) {
                    if ((visitedRow.at(i) == visitedRow.at(j)) &&
                        (visitedCol.at(i) + 1 == visitedCol.at(j))) {
                        rightInVisited = true;
                    }
                }
                if (!rightInVisited) {
                    visitedRow.at(visitedCount + tempAdded) = visitedRow.at(i);
                    visitedCol.at(visitedCount + tempAdded) = visitedCol.at(i) + 1;
                    ++tempAdded;
                }
            }
            else if (mapped[visitedRow.at(i)][visitedCol.at(i) + 1] == 'o') {
                found = true;
            }

            if (mapped[visitedRow.at(i)][visitedCol.at(i) - 1] == '.') {
                bool leftInVisited = false;
                for (int j = 0; j < visitedCount; ++j) {
                    if ((visitedRow.at(i) == visitedRow.at(j)) &&
                        (visitedCol.at(i) - 1 == visitedCol.at(j))) {
                        leftInVisited = true;
                    }
                }
                if (!leftInVisited) {
                    visitedRow.at(visitedCount + tempAdded) = visitedRow.at(i);
                    visitedCol.at(visitedCount + tempAdded) = visitedCol.at(i) - 1;
                    ++tempAdded;
                }
            }
            else if (mapped[visitedRow.at(i)][visitedCol.at(i) - 1] == 'o') {
                found = true;
            }
        }
        ++pathLength;
        visitedCount += tempAdded;
    }

    cout << "pathLength: " << pathLength << endl;

    return 0;
} 