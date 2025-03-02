#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MULTI_LINE_STRING(a) #a

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;

int main() {
   string inputString = MULTI_LINE_STRING(""); // Insert your puzzle input here

   vector<int> moduleMassValues;
   string currentIntString = "";
   int currentInt;

   for (unsigned int i = 0; i < inputString.size(); ++i) {
      if (isspace(inputString.at(i))) {
         currentInt = stoi(currentIntString);
         moduleMassValues.push_back(currentInt);
         currentIntString = "";
      }
      else if (i == inputString.size() - 1) {
         currentIntString += inputString.at(i);
         currentInt = stoi(currentIntString);
         moduleMassValues.push_back(currentInt);
      }
      else {
         currentIntString += inputString.at(i);
      }
   }

   int fuelSum = 0;
   int fuel;

   for (unsigned int i = 0; i < moduleMassValues.size(); ++i) {
      fuel = (moduleMassValues.at(i) / 3) - 2;

      while (fuel > 0) {
         fuelSum += fuel;
         fuel = (fuel / 3) - 2;
      }
   }

   cout << fuelSum << endl;

   return 0;
}



