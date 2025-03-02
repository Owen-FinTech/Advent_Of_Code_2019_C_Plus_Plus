#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MULTI_LINE_STRING_1(...) #__VA_ARGS__
#define MULTI_LINE_STRING_2(...) #__VA_ARGS__

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;

int main() {
   string inputString1 = MULTI_LINE_STRING_1(""); // Insert the first half of the puzzle input here
   
   string inputString2 = MULTI_LINE_STRING_2(""); // Insert the second half of the puzzle input here

   vector<string> wirePath1;
   string currString = "";

   for (unsigned int i = 0; i < inputString1.size(); ++i) {
      if (inputString1.at(i) == ',') {
         wirePath1.push_back(currString);
         currString = "";
      }
      else if (i == inputString1.size() - 1) {
         currString += inputString1.at(i);
         wirePath1.push_back(currString);
      }
      else if (isspace(inputString1.at(i))) {
         continue;
      }
      else { 
         currString += inputString1.at(i);
      }
   }
   
   vector<string> wirePath2;
   currString = "";

   for (unsigned int i = 0; i < inputString2.size(); ++i) {
      if (inputString2.at(i) == ',') {
         wirePath2.push_back(currString);
         currString = "";
      }
      else if (i == inputString2.size() - 1) {
         currString += inputString2.at(i);
         wirePath2.push_back(currString);
      }
      else if (isspace(inputString2.at(i))) {
         continue;
      }
      else { 
         currString += inputString2.at(i);
      }
   }
   
   vector<vector<int>> coordinates1;
   int xPos = 0;
   int yPos = 0;
   vector<int> centralPort;
   centralPort.push_back(xPos);
   centralPort.push_back(yPos);
   coordinates1.push_back(centralPort);

   for (unsigned int i = 0; i < wirePath1.size(); ++i) {
      vector<int> currPos;   
      if (wirePath1.at(i).at(0) == 'R') {
         int rightDist = stoi(wirePath1.at(i).substr(1, wirePath1.at(i).size() - 1));
	 
	 for (int j = 0; j < rightDist; ++j) {
            currPos.clear();
	    xPos += 1;
	    currPos.push_back(xPos);
	    currPos.push_back(yPos);
	    coordinates1.push_back(currPos);
	 }
      }
      
      if (wirePath1.at(i).at(0) == 'L') {
         int leftDist = stoi(wirePath1.at(i).substr(1, wirePath1.at(i).size() - 1));
	 
	 for (int j = 0; j < leftDist; ++j) {
            currPos.clear();
	    xPos -= 1;
	    currPos.push_back(xPos);
	    currPos.push_back(yPos);
	    coordinates1.push_back(currPos);
	 }
      }
      
      if (wirePath1.at(i).at(0) == 'U') {
         int upDist = stoi(wirePath1.at(i).substr(1, wirePath1.at(i).size() - 1));
	 
	 for (int j = 0; j < upDist; ++j) {
            currPos.clear();
	    yPos += 1;
	    currPos.push_back(xPos);
	    currPos.push_back(yPos);
	    coordinates1.push_back(currPos);
	 }
      }
      
      if (wirePath1.at(i).at(0) == 'D') {
         int downDist = stoi(wirePath1.at(i).substr(1, wirePath1.at(i).size() - 1));
	 
	 for (int j = 0; j < downDist; ++j) {
            currPos.clear();
	    yPos -= 1;
	    currPos.push_back(xPos);
	    currPos.push_back(yPos);
	    coordinates1.push_back(currPos);
	 }
      }
   }      
   
   vector<vector<int>> coordinates2;
   xPos = 0;
   yPos = 0;
   centralPort.clear();
   centralPort.push_back(xPos);
   centralPort.push_back(yPos);
   coordinates2.push_back(centralPort);

   for (unsigned int i = 0; i < wirePath2.size(); ++i) {   
      vector<int> currPos;
      if (wirePath2.at(i).at(0) == 'R') {
         int rightDist = stoi(wirePath2.at(i).substr(1, wirePath2.at(i).size() - 1));
	 
	 for (int j = 0; j < rightDist; ++j) {
            currPos.clear();
	    xPos += 1;
	    currPos.push_back(xPos);
	    currPos.push_back(yPos);
	    coordinates2.push_back(currPos);
	 }
      }
      
      if (wirePath2.at(i).at(0) == 'L') {
         int leftDist = stoi(wirePath2.at(i).substr(1, wirePath2.at(i).size() - 1));
	 
	 for (int j = 0; j < leftDist; ++j) {
            currPos.clear();
	    xPos -= 1;
	    currPos.push_back(xPos);
	    currPos.push_back(yPos);
	    coordinates2.push_back(currPos);
	 }
      }
      
      if (wirePath2.at(i).at(0) == 'U') {
         int upDist = stoi(wirePath2.at(i).substr(1, wirePath2.at(i).size() - 1));
	 
	 for (int j = 0; j < upDist; ++j) {
            currPos.clear();
	    yPos += 1;
	    currPos.push_back(xPos);
	    currPos.push_back(yPos);
	    coordinates2.push_back(currPos);
	 }
      }
      
      if (wirePath2.at(i).at(0) == 'D') {
         int downDist = stoi(wirePath2.at(i).substr(1, wirePath2.at(i).size() - 1));
	 
	 for (int j = 0; j < downDist; ++j) {
            currPos.clear();
	    yPos -= 1;
	    currPos.push_back(xPos);
	    currPos.push_back(yPos);
	    coordinates2.push_back(currPos);
	 }
      }
   }      

   vector<int> manhattanDist;

   for (unsigned int i = 0; i < coordinates1.size(); ++i) {
      for (unsigned int j = 0; j < coordinates2.size(); ++j) {
         if ((coordinates1.at(i).at(0) == coordinates2.at(j).at(0)) && 
	    (coordinates1.at(i).at(1) == coordinates2.at(j).at(1))) {
            manhattanDist.push_back(static_cast<int>(fabs(coordinates1.at(i).at(0))) 
	       + static_cast<int>(fabs(coordinates1.at(i).at(1))));
	 }
      }
   }

   int minManhattanDist = manhattanDist.at(manhattanDist.size() - 1);

   for (unsigned int i = 0; i < manhattanDist.size(); ++i) {
      if ((manhattanDist.at(i) < minManhattanDist) && (manhattanDist.at(i) != 0)) {
         minManhattanDist = manhattanDist.at(i);
      }
   }

   cout << minManhattanDist << endl;   

   return 0;
} 
