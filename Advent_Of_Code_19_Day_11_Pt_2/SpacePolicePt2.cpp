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
   string inputString = MULTI_LINE_STRING(""); // Insert the puzzle input here
   
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

   char** panels = new char*[1000];
   for (int i = 0; i < 1000; ++i) {
      panels[i] = new char[1000]; 
      for (int j = 0; j < 1000; ++j) {
         panels[i][j] = '.';
      }
   }

   int** painted = new int*[1000];
   for (int i = 0; i < 1000; ++i) {
      painted[i] = new int[1000]; 
      for (int j = 0; j < 1000; ++j) {
         painted[i][j] = 0;
      }
   }

   int currPanelsRow = 500;
   int currPanelsCol = 500;
   int outputCount = 0; 
   int direction = 'N';
   
   long long int currPos = 0;
   long long int relativeBase = 0;
   long long int input = 1; 

   while (intcode.at(currPos) != static_cast<long long int>(99)) {
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
            cout << intcode.at(currPos + 1) << endl;
            if (outputCount % 2 == 0) {
               if (intcode.at(currPos + 1) == 1) {
                  panels[currPanelsRow][currPanelsCol] = '#';
                  painted[currPanelsRow][currPanelsCol] = 1;
                  input = 1;
               }
               else {
                  panels[currPanelsRow][currPanelsCol] = '.';
                  painted[currPanelsRow][currPanelsCol] = 1;
                  input = 0;
               }
            }
            else {
               if (direction == 'N') {
                  if (intcode.at(currPos + 1) == 1) {
                     direction = 'E';
                     currPanelsCol += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'W';
                     currPanelsCol -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
               else if (direction == 'S') {
                  if (intcode.at(currPos + 1) == 1) {
                     direction = 'W';
                     currPanelsCol -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'E';
                     currPanelsCol += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
               else if (direction == 'E') {
                  if (intcode.at(currPos + 1) == 1) {
                     direction = 'S';
                     currPanelsRow += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'N';
                     currPanelsRow -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
               else {
                  if (intcode.at(currPos + 1) == 1) {
                     direction = 'N';
                     currPanelsRow -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'S';
                     currPanelsRow += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
            }
            ++outputCount;
            currPos += 2;
         }
         else if (firstParamMode == 2) {
            cout << intcode.at(intcode.at(currPos + 1) + relativeBase) << endl;
            if (outputCount % 2 == 0) {
               if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 1) {
                  panels[currPanelsRow][currPanelsCol] = '#';
                  painted[currPanelsRow][currPanelsCol] = 1;
                  input = 1;
               }
               else {
                  panels[currPanelsRow][currPanelsCol] = '.';
                  painted[currPanelsRow][currPanelsCol] = 1;
                  input = 0;
               }
            }
            else {
               if (direction == 'N') {
                  if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 1) {
                     direction = 'E';
                     currPanelsCol += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'W';
                     currPanelsCol -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
               else if (direction == 'S') {
                  if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 1) {
                     direction = 'W';
                     currPanelsCol -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'E';
                     currPanelsCol += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
               else if (direction == 'E') {
                  if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 1) {
                     direction = 'S';
                     currPanelsRow += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'N';
                     currPanelsRow -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
               else {
                  if (intcode.at(intcode.at(currPos + 1) + relativeBase) == 1) {
                     direction = 'N';
                     currPanelsRow -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'S';
                     currPanelsRow += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
            }
            ++outputCount;
            currPos += 2;
         }
         else {
            cout << intcode.at(intcode.at(currPos + 1)) << endl;
            if (outputCount % 2 == 0) {
               if (intcode.at(intcode.at(currPos + 1)) == 1) {
                  panels[currPanelsRow][currPanelsCol] = '#';
                  painted[currPanelsRow][currPanelsCol] = 1;
                  input = 1;
               }
               else {
                  panels[currPanelsRow][currPanelsCol] = '.';
                  painted[currPanelsRow][currPanelsCol] = 1;
                  input = 0;
               }
            }
            else {
               if (direction == 'N') {
                  if (intcode.at(intcode.at(currPos + 1)) == 1) {
                     direction = 'E';
                     currPanelsCol += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'W';
                     currPanelsCol -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
               else if (direction == 'S') {
                  if (intcode.at(intcode.at(currPos + 1)) == 1) {
                     direction = 'W';
                     currPanelsCol -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'E';
                     currPanelsCol += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
               else if (direction == 'E') {
                  if (intcode.at(intcode.at(currPos + 1)) == 1) {
                     direction = 'S';
                     currPanelsRow += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'N';
                     currPanelsRow -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
               else {
                  if (intcode.at(intcode.at(currPos + 1)) == 1) {
                     direction = 'N';
                     currPanelsRow -= 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
                  else {
                     direction = 'S';
                     currPanelsRow += 1;
                     if (panels[currPanelsRow][currPanelsCol] == '#') {
                        input = 1;
                     }
                     else {
                        input = 0;
                     }
                  }
               }
            }
            ++outputCount;
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

   int panelsRowMin = 999;
   int panelsRowMax = 0;
   int panelsColMin = 999;
   int panelsColMax = 0;

   for (int i = 0; i < 1000; ++i) {
      for (int j = 0; j < 1000; ++j) {
         if (panels [i][j] == '#') {
            if (i > panelsRowMax) {
               panelsRowMax = i;
            }

            if (j > panelsColMax) {
               panelsColMax = j;
            }            
         }
      }
   }

   for (int i = 999; i >= 0; --i) {
      for (int j = 999; j >= 0; --j) {
         if (panels [i][j] == '#') {
            if (i < panelsRowMin) {
               panelsRowMin = i;
            }
            
            if (j < panelsColMin) {
               panelsColMin = j;
            } 
         }
      }
   }

   for (int i = panelsRowMin; i <= panelsRowMax; ++i) {
      for (int j = panelsColMin; j <= panelsColMax; ++j) {
         cout << panels[i][j];
      }
      cout << endl;
   }

   return 0;
} 