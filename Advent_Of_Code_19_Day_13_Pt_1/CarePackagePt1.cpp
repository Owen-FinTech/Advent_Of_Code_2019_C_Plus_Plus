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
1,380,379,385,1008,2751,576818,381,1005,381,12,99,109,2752,1101,0,0,383,1102,1,0,382,20101,0,382,1,21001,383,0,2,21102,1,37,0,1106,0,578,4,382,4,383,204,1,1001,382,1,382,1007,382,44,381,1005,381,22,1001,383,1,383,1007,383,24,381,1005,381,18,1006,385,69,99,104,-1,104,0,4,386,3,384,1007,384,0,381,1005,381,94,107,0,384,381,1005,381,108,1106,0,161,107,1,392,381,1006,381,161,1101,0,-1,384,1106,0,119,1007,392,42,381,1006,381,161,1101,1,0,384,21002,392,1,1,21102,22,1,2,21101,0,0,3,21102,1,138,0,1105,1,549,1,392,384,392,21002,392,1,1,21101,0,22,2,21101,3,0,3,21102,1,161,0,1106,0,549,1102,0,1,384,20001,388,390,1,21001,389,0,2,21102,1,180,0,1106,0,578,1206,1,213,1208,1,2,381,1006,381,205,20001,388,390,1,20102,1,389,2,21102,205,1,0,1105,1,393,1002,390,-1,390,1101,0,1,384,21002,388,1,1,20001,389,391,2,21102,228,1,0,1106,0,578,1206,1,261,1208,1,2,381,1006,381,253,20102,1,388,1,20001,389,391,2,21102,253,1,0,1106,0,393,1002,391,-1,391,1101,0,1,384,1005,384,161,20001,388,390,1,20001,389,391,2,21101,0,279,0,1105,1,578,1206,1,316,1208,1,2,381,1006,381,304,20001,388,390,1,20001,389,391,2,21101,304,0,0,1106,0,393,1002,390,-1,390,1002,391,-1,391,1101,0,1,384,1005,384,161,20102,1,388,1,21002,389,1,2,21102,1,0,3,21102,1,338,0,1106,0,549,1,388,390,388,1,389,391,389,21002,388,1,1,21001,389,0,2,21101,4,0,3,21102,365,1,0,1105,1,549,1007,389,23,381,1005,381,75,104,-1,104,0,104,0,99,0,1,0,0,0,0,0,0,304,20,19,1,1,22,109,3,22102,1,-2,1,21201,-1,0,2,21101,0,0,3,21101,414,0,0,1106,0,549,21202,-2,1,1,22101,0,-1,2,21101,429,0,0,1106,0,601,1201,1,0,435,1,386,0,386,104,-1,104,0,4,386,1001,387,-1,387,1005,387,451,99,109,-3,2106,0,0,109,8,22202,-7,-6,-3,22201,-3,-5,-3,21202,-4,64,-2,2207,-3,-2,381,1005,381,492,21202,-2,-1,-1,22201,-3,-1,-3,2207,-3,-2,381,1006,381,481,21202,-4,8,-2,2207,-3,-2,381,1005,381,518,21202,-2,-1,-1,22201,-3,-1,-3,2207,-3,-2,381,1006,381,507,2207,-3,-4,381,1005,381,540,21202,-4,-1,-1,22201,-3,-1,-3,2207,-3,-4,381,1006,381,529,22102,1,-3,-7,109,-8,2105,1,0,109,4,1202,-2,44,566,201,-3,566,566,101,639,566,566,2102,1,-1,0,204,-3,204,-2,204,-1,109,-4,2106,0,0,109,3,1202,-1,44,594,201,-2,594,594,101,639,594,594,20101,0,0,-2,109,-3,2106,0,0,109,3,22102,24,-2,1,22201,1,-1,1,21101,0,541,2,21101,0,17,3,21102,1,1056,4,21102,630,1,0,1106,0,456,21201,1,1695,-2,109,-3,2105,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,2,0,2,2,2,0,2,2,2,0,2,0,0,0,2,2,0,2,0,2,0,0,0,2,2,2,2,2,2,0,2,0,2,2,0,2,0,1,1,0,0,2,0,0,0,0,0,0,0,0,0,2,2,0,2,0,0,2,0,0,2,2,2,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,1,1,0,0,0,2,0,0,2,0,0,0,0,2,2,0,0,0,2,0,2,0,0,0,0,0,2,2,2,2,0,2,0,0,2,0,2,0,0,2,2,0,2,0,1,1,0,2,0,2,0,2,2,2,2,0,0,2,0,0,2,2,2,2,2,2,2,0,2,2,0,0,0,2,0,2,2,2,2,0,2,2,0,0,0,0,0,0,1,1,0,0,2,0,0,2,0,2,0,2,2,2,0,0,0,0,0,2,2,0,2,0,0,2,2,0,2,2,2,0,2,0,2,0,0,2,2,2,2,0,0,0,1,1,0,0,0,2,0,2,0,2,0,2,0,2,0,0,2,0,0,0,2,0,2,2,0,2,0,2,0,0,2,2,0,0,2,2,2,2,2,0,2,0,2,0,1,1,0,0,2,2,2,2,2,0,0,2,2,0,2,2,2,2,0,0,2,0,2,0,2,0,2,2,0,2,0,2,2,2,2,2,0,2,0,2,0,0,0,0,1,1,0,2,0,2,0,2,2,2,2,0,0,2,0,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,0,2,2,0,0,0,2,2,2,2,0,2,2,0,1,1,0,2,0,0,2,0,2,0,0,0,2,0,2,0,0,2,2,0,0,0,0,0,2,2,2,0,2,0,2,0,2,0,0,2,2,2,2,2,2,0,2,0,1,1,0,2,2,2,2,0,2,0,0,2,0,0,2,0,2,0,0,0,2,2,0,2,0,2,2,2,0,0,2,0,0,2,0,0,2,2,0,2,0,0,0,0,1,1,0,0,2,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,2,0,2,2,2,0,2,2,0,2,0,2,0,2,2,0,0,2,0,0,2,0,0,0,1,1,0,0,2,2,2,2,2,0,0,2,0,0,0,2,0,2,0,0,0,0,0,0,0,0,2,2,0,2,0,2,0,0,2,0,2,0,2,0,0,2,0,0,1,1,0,0,2,0,0,0,0,0,0,0,2,2,2,0,2,2,0,2,0,0,0,2,0,0,2,2,2,2,0,2,0,2,0,2,0,2,0,2,0,2,0,0,1,1,0,0,2,2,0,2,2,2,2,0,0,2,2,2,2,0,0,2,0,2,0,0,0,2,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,2,0,0,1,1,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,2,0,2,2,0,0,0,2,2,2,2,2,2,2,0,2,0,2,0,2,0,2,0,2,0,1,1,0,2,2,0,0,2,2,0,0,0,2,0,2,0,2,0,0,2,0,0,0,0,0,0,0,2,2,0,0,2,2,2,2,2,0,2,2,0,2,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,90,70,96,85,71,32,46,60,11,68,65,14,38,60,42,18,48,81,69,25,37,42,57,8,57,60,51,25,89,27,12,57,3,12,2,47,7,88,41,47,26,33,27,31,51,63,35,85,84,5,37,42,20,21,95,34,74,93,31,80,51,70,93,53,31,97,79,78,18,38,81,10,2,49,31,55,27,46,76,46,47,26,89,40,46,51,22,71,66,66,70,21,84,74,87,61,52,82,85,26,14,55,26,12,91,1,51,46,50,29,90,47,94,86,59,36,18,29,6,33,17,58,8,12,25,32,92,62,87,84,89,90,6,80,23,53,79,33,45,48,98,67,63,8,80,50,32,67,58,98,15,43,79,77,79,71,67,51,66,78,4,52,19,49,72,8,63,61,89,74,3,18,37,83,5,64,12,93,87,31,45,51,78,1,58,71,42,56,65,35,35,39,93,58,86,47,57,30,17,19,74,67,43,66,34,40,73,93,35,1,51,77,49,79,72,7,71,5,73,88,71,69,42,33,10,81,32,18,11,58,91,75,98,53,33,84,93,65,67,81,82,49,2,82,82,9,7,53,6,13,21,74,50,59,27,97,37,48,55,59,67,88,85,55,52,95,93,33,77,34,1,81,96,48,50,16,62,94,69,42,27,2,21,73,19,73,90,27,91,66,44,44,77,72,1,9,58,68,26,79,81,97,33,61,59,27,25,81,23,39,97,6,52,71,3,12,79,76,75,35,81,45,50,35,50,84,39,19,81,9,77,81,14,81,41,78,12,18,28,15,73,24,65,56,22,37,30,58,30,5,91,77,18,51,20,41,16,74,33,98,2,84,2,7,81,47,91,48,34,68,44,31,15,11,29,18,55,39,93,2,69,91,29,78,20,83,16,54,2,22,33,68,2,41,61,16,29,75,35,3,57,39,48,71,94,97,94,22,72,83,80,75,98,4,63,52,49,34,13,46,58,16,44,8,75,64,1,48,72,5,77,7,90,8,90,82,40,31,65,93,69,50,5,92,48,2,88,34,45,40,64,76,61,62,52,70,14,65,44,93,69,10,11,35,17,32,64,31,14,3,63,61,67,43,8,21,6,4,82,14,33,16,68,53,70,73,48,78,35,8,44,60,21,46,78,27,59,75,18,51,51,85,67,37,76,76,86,73,65,32,1,10,49,44,82,69,68,9,61,21,21,93,86,16,21,14,37,24,69,20,23,56,78,35,4,7,69,47,21,12,76,55,27,58,6,87,88,49,11,44,95,34,57,57,4,85,22,6,52,6,65,32,89,5,80,62,2,91,32,18,12,33,63,81,89,70,43,72,8,51,56,96,94,77,43,50,45,96,20,33,25,39,13,82,24,56,73,19,10,22,81,46,88,6,37,55,13,45,70,59,20,80,82,49,97,95,47,29,62,59,35,12,84,83,60,54,86,72,68,18,26,62,49,60,6,68,81,51,65,69,16,81,51,92,37,90,85,80,60,23,32,2,97,33,20,25,36,2,98,62,7,89,83,64,81,32,62,70,24,35,15,43,73,22,30,44,48,48,95,67,10,36,93,15,21,33,31,85,90,67,37,22,51,71,8,25,38,10,92,10,37,20,98,74,81,87,85,83,17,32,37,11,89,20,4,36,18,96,63,9,8,9,46,45,3,29,23,79,4,56,2,88,82,94,94,48,71,75,86,31,76,92,61,73,3,44,28,50,26,6,90,51,36,16,94,20,25,34,2,65,47,28,17,86,98,39,57,63,14,69,59,45,68,35,78,74,28,51,36,16,78,40,66,85,18,25,36,37,2,54,74,2,59,13,93,67,18,16,27,85,8,60,92,59,37,29,15,29,38,49,6,64,33,27,1,47,96,65,91,74,58,93,33,4,39,44,63,11,78,23,87,63,54,95,56,28,48,79,73,45,66,64,48,29,5,6,84,45,6,93,28,73,96,39,9,31,71,51,62,20,21,25,84,12,13,64,35,62,98,23,80,32,30,95,93,15,21,44,24,81,6,49,32,40,52,1,6,93,59,22,38,77,32,95,64,89,65,31,79,93,25,90,27,18,56,69,32,18,79,89,91,80,16,74,43,48,57,20,13,29,79,35,81,32,21,70,83,70,3,65,74,75,4,30,29,5,31,9,79,19,24,65,46,2,86,36,71,80,29,24,24,82,86,40,35,26,6,80,57,49,30,43,29,84,15,8,3,38,98,64,30,40,47,22,41,93,4,47,27,88,74,62,81,10,55,79,70,84,65,65,27,44,95,73,19,87,9,82,73,2,79,4,84,45,13,95,55,18,72,45,19,53,24,66,5,96,37,90,5,84,38,25,56,38,64,33,88,65,14,91,61,60,95,72,77,54,32,53,54,93,74,63,41,51,12,68,11,94,72,69,51,82,28,40,58,19,576818
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
   long long int input = 2;
   int outputCount = 0; 
   int blockTileCount = 0;

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
            if ((outputCount % 3 == 2) && (intcode.at(currPos + 1) == 2)) {
               ++blockTileCount;
            }
            ++outputCount;
            currPos += 2;
         }
         else if (firstParamMode == 2) {
            cout << intcode.at(intcode.at(currPos + 1) + relativeBase) << endl;
            if ((outputCount % 3 == 2) && (intcode.at(intcode.at(currPos + 1) + relativeBase) == 2)) {
               ++blockTileCount;
            }
            ++outputCount;
            currPos += 2;
         }
         else {
            cout << intcode.at(intcode.at(currPos + 1)) << endl;
            if ((outputCount % 3 == 2) && (intcode.at(intcode.at(currPos + 1)) == 2)) {
               ++blockTileCount;
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

   cout << "Block Tile Count: " << blockTileCount << endl;

   return 0;
} 