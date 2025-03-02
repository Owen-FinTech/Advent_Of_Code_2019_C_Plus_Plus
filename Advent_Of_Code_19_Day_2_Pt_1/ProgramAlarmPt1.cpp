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
   
   int currPos = 0;
   intcode.at(1) = 12;
   intcode.at(2) = 2; 

   while (intcode.at(currPos) != 99) {
      if (intcode.at(currPos) == 1) {
         intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) + intcode.at(intcode.at(currPos + 2));
         currPos += 4;
      }
      else if (intcode.at(currPos) == 2) {
         intcode.at(intcode.at(currPos + 3)) = intcode.at(intcode.at(currPos + 1)) * intcode.at(intcode.at(currPos + 2));
         currPos += 4;
      }
      else {
         currPos += 4;
      }
   }

   cout << intcode.at(0) << endl;

   return 0;
} 
