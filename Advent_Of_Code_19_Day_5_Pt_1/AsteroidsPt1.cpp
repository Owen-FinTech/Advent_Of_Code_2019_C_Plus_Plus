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
      
   vector<int> intcode;
   string currIntString = "";
   int currInt;

   for (unsigned int i = 0; i < inputString.size(); ++i) {
      if (inputString.at(i) == ',') {
         currInt = stoi(currIntString);
         intcode.push_back(currInt);
         currIntString = "";
      }
      else if (i == inputString.size() - 1) {
         currIntString += inputString.at(i);
         currInt = stoi(currIntString);
         intcode.push_back(currInt);
      }
      else if (isspace(inputString.at(i))) {
         continue;
      }
      else { 
         currIntString +=inputString.at(i);
      }
   }
   
   int currPos = 0;

   int input = 1; 

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
         if (firstParamMode == 1) {
            intcode.at(intcode.at(currPos + 1)) = input;
            currPos += 2;
         }
         else {
            intcode.at(intcode.at(intcode.at(currPos + 1))) = input;
            currPos += 2;
         }  
      }
      else if ((intcode.at(currPos) == 4) || (twoDigitOpcode == 4)) {
         if (firstParamMode == 1) {
            cout << intcode.at(currPos + 1) << endl;
            currPos += 2;
         }
         else {
            cout << intcode.at(intcode.at(currPos + 1)) << endl;
            currPos += 2;
         }
      }
      else {
         currPos += 4;
      }
   }

   return 0;
} 
