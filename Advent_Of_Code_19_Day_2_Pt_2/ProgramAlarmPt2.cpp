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
   string inputString = MULTI_LINE_STRING(""); // Insert your puzzle input here

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
