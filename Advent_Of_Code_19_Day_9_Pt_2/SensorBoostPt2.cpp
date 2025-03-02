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
1102,34463338,34463338,63,1007,63,34463338,63,1005,63,53,1101,0,3,1000,109,988,209,12,9,1000,209,6,209,3,203,0,1008,1000,1,63,1005,63,65,1008,1000,2,63,1005,63,904,1008,1000,0,63,1005,63,58,4,25,104,0,99,4,0,104,0,99,4,17,104,0,99,0,0,1102,1,29,1011,1102,1,27,1009,1101,23,0,1008,1101,0,25,1017,1102,1,36,1016,1101,0,31,1018,1102,35,1,1012,1101,28,0,1004,1101,779,0,1024,1102,403,1,1026,1101,0,33,1010,1102,37,1,1015,1101,32,0,1014,1101,0,752,1023,1101,0,30,1013,1102,21,1,1001,1102,1,1,1021,1102,1,34,1002,1102,400,1,1027,1101,0,22,1007,1102,1,567,1028,1101,558,0,1029,1102,26,1,1006,1102,39,1,1005,1102,1,0,1020,1101,0,38,1000,1101,0,755,1022,1102,1,770,1025,1102,1,24,1003,1102,20,1,1019,109,28,21107,40,41,-9,1005,1019,199,4,187,1106,0,203,1001,64,1,64,1002,64,2,64,109,-30,2107,38,7,63,1005,63,221,4,209,1105,1,225,1001,64,1,64,1002,64,2,64,109,-5,2102,1,8,63,1008,63,21,63,1005,63,251,4,231,1001,64,1,64,1106,0,251,1002,64,2,64,109,21,1207,-7,21,63,1005,63,267,1105,1,273,4,257,1001,64,1,64,1002,64,2,64,109,-1,1201,-7,0,63,1008,63,29,63,1005,63,293,1106,0,299,4,279,1001,64,1,64,1002,64,2,64,109,-4,1202,-3,1,63,1008,63,28,63,1005,63,319,1106,0,325,4,305,1001,64,1,64,1002,64,2,64,109,14,1206,-3,343,4,331,1001,64,1,64,1106,0,343,1002,64,2,64,109,-14,2108,21,-8,63,1005,63,361,4,349,1105,1,365,1001,64,1,64,1002,64,2,64,109,-9,1201,9,0,63,1008,63,27,63,1005,63,391,4,371,1001,64,1,64,1106,0,391,1002,64,2,64,109,27,2106,0,0,1106,0,409,4,397,1001,64,1,64,1002,64,2,64,109,-20,2101,0,0,63,1008,63,22,63,1005,63,431,4,415,1105,1,435,1001,64,1,64,1002,64,2,64,109,-7,1202,7,1,63,1008,63,22,63,1005,63,457,4,441,1105,1,461,1001,64,1,64,1002,64,2,64,109,8,1208,0,23,63,1005,63,479,4,467,1106,0,483,1001,64,1,64,1002,64,2,64,109,20,1205,-8,495,1105,1,501,4,489,1001,64,1,64,1002,64,2,64,109,-26,1208,4,28,63,1005,63,521,1001,64,1,64,1105,1,523,4,507,1002,64,2,64,109,15,21102,41,1,-2,1008,1015,41,63,1005,63,545,4,529,1106,0,549,1001,64,1,64,1002,64,2,64,109,18,2106,0,-7,4,555,1001,64,1,64,1106,0,567,1002,64,2,64,109,-30,1207,-3,35,63,1005,63,585,4,573,1105,1,589,1001,64,1,64,1002,64,2,64,109,14,1206,2,605,1001,64,1,64,1106,0,607,4,595,1002,64,2,64,109,-3,1205,5,621,4,613,1106,0,625,1001,64,1,64,1002,64,2,64,109,-5,21107,42,41,2,1005,1013,645,1001,64,1,64,1106,0,647,4,631,1002,64,2,64,109,-11,2108,42,5,63,1005,63,663,1106,0,669,4,653,1001,64,1,64,1002,64,2,64,109,4,21102,43,1,9,1008,1013,40,63,1005,63,693,1001,64,1,64,1106,0,695,4,675,1002,64,2,64,109,-1,2107,22,-2,63,1005,63,715,1001,64,1,64,1106,0,717,4,701,1002,64,2,64,109,7,21101,44,0,0,1008,1010,45,63,1005,63,741,1001,64,1,64,1106,0,743,4,723,1002,64,2,64,109,9,2105,1,4,1106,0,761,4,749,1001,64,1,64,1002,64,2,64,109,10,2105,1,-5,4,767,1001,64,1,64,1105,1,779,1002,64,2,64,109,-22,21108,45,43,10,1005,1017,799,1001,64,1,64,1105,1,801,4,785,1002,64,2,64,109,16,21101,46,0,-8,1008,1015,46,63,1005,63,827,4,807,1001,64,1,64,1105,1,827,1002,64,2,64,109,-7,2101,0,-7,63,1008,63,29,63,1005,63,851,1001,64,1,64,1106,0,853,4,833,1002,64,2,64,109,-5,2102,1,-3,63,1008,63,22,63,1005,63,877,1001,64,1,64,1106,0,879,4,859,1002,64,2,64,109,9,21108,47,47,-5,1005,1015,897,4,885,1105,1,901,1001,64,1,64,4,64,99,21102,27,1,1,21101,0,915,0,1105,1,922,21201,1,61784,1,204,1,99,109,3,1207,-2,3,63,1005,63,964,21201,-2,-1,1,21101,942,0,0,1105,1,922,22102,1,1,-1,21201,-2,-3,1,21102,1,957,0,1106,0,922,22201,1,-1,-2,1105,1,968,22101,0,-2,-2,109,-3,2105,1,0
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
            currPos += 2;
         }
         else if (firstParamMode == 2) {
            cout << intcode.at(intcode.at(currPos + 1) + relativeBase) << endl;
            currPos += 2;
         }
         else {
            cout << intcode.at(intcode.at(currPos + 1)) << endl;
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

   return 0;
} 