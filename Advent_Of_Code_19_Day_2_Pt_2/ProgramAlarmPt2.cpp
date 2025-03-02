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
1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,6,19,2,19,6,23,1,23,5,27,1,9,27,31,1,31,10,35,2,35,9,39,1,5,39,43,2,43,9,47,1,5,47,51,2,51,13,55,1,55,10,59,1,59,10,63,2,9,63,67,1,67,5,71,2,13,71,75,1,75,10,79,1,79,6,83,2,13,83,87,1,87,6,91,1,6,91,95,1,10,95,99,2,99,6,103,1,103,5,107,2,6,107,111,1,10,111,115,1,115,5,119,2,6,119,123,1,123,5,127,2,127,6,131,1,131,5,135,1,2,135,139,1,139,13,0,99,2,0,14,0
   ); // Insert your puzzle input here

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
   
   vector<int> intcodeCopy;

   for (int i = 0; i <= 99; ++i) {
      for (int j = 0; j <= 99; ++j) {

         intcodeCopy.clear();
         for (unsigned int k = 0; k < intcode.size(); ++k) {
            intcodeCopy.push_back(intcode.at(k));
         }	 

         int currPos = 0;
         intcodeCopy.at(1) = i;
         intcodeCopy.at(2) = j; 

         while (intcodeCopy.at(currPos) != 99) {
            if (intcodeCopy.at(currPos) == 1) {
               intcodeCopy.at(intcodeCopy.at(currPos + 3)) = intcodeCopy.at(intcodeCopy.at(currPos + 1)) 
	          + intcodeCopy.at(intcodeCopy.at(currPos + 2));
               currPos += 4;
            }
            else if (intcodeCopy.at(currPos) == 2) {
               intcodeCopy.at(intcodeCopy.at(currPos + 3)) = intcodeCopy.at(intcodeCopy.at(currPos + 1)) 
	          * intcodeCopy.at(intcodeCopy.at(currPos + 2));
               currPos += 4;
            }
            else {
               currPos += 4;
            }
         }

         if (intcodeCopy.at(0) == 19690720) {
	    break;
	 }
      }

      if (intcodeCopy.at(0) == 19690720) {
         break;
      }
   }

   cout << (100 * intcodeCopy.at(1)) + intcodeCopy.at(2) << endl;

   return 0;
} 
