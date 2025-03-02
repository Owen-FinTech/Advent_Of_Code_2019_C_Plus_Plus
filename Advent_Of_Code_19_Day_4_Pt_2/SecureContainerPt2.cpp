#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#define MULTI_LINE_STRING(...) #__VA_ARGS__

using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::vector;

int main() {
   string inputString = MULTI_LINE_STRING(""); // Insert the puzzle input here
      
   string currIntString = "";
   int lowRange;
   int highRange;

   for (unsigned int i = 0; i < inputString.size(); ++i) {
      if (inputString.at(i) == '-') {
         lowRange = stoi(currIntString);
         currIntString = "";
      }
      else if (i == inputString.size() - 1) {
         currIntString += inputString.at(i);
         highRange = stoi(currIntString);
      }
      else {
         currIntString += inputString.at(i);
      }
   }

   int count = 0;

   for (int i = lowRange; i <= highRange; ++i) {
      if ((i % 10 >= ((i / 10) % 10)) &&
         (((i / 10) % 10) >= ((i / 100) % 10)) &&
         (((i / 100) % 10) >= ((i / 1000) % 10)) &&
         (((i / 1000) % 10) >= ((i / 10000) % 10)) &&
         (((i / 10000) % 10) >= ((i / 100000) % 10)) &&
         ((i % 10 == ((i / 10) % 10)) ||
         (((i / 10) % 10) == ((i / 100) % 10)) ||
         (((i / 100) % 10) == ((i / 1000) % 10)) ||
         (((i / 1000) % 10) == ((i / 10000) % 10)) ||
         (((i / 10000) % 10) == ((i / 100000) % 10)))) {
         vector<int> digitCounts = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

         digitCounts.at(i % 10) += 1;
         digitCounts.at((i / 10) % 10) += 1;
         digitCounts.at((i / 100) % 10) += 1;
         digitCounts.at((i / 1000) % 10) += 1;
         digitCounts.at((i / 10000) % 10) += 1;
         digitCounts.at((i / 100000) % 10) += 1;

         for (int j = 0; j <= 9; ++j) {
            if (digitCounts.at(j) == 2) {
               count += 1;
               break;
            }
         }
      }
   }

   cout << count << endl;

   return 0;
} 
