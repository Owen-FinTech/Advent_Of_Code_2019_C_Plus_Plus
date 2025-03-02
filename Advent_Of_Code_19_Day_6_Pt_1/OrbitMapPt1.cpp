#include "Planet.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;

int getOrbitCount(Planet* planetPtr) {
    int count = 0;
    if (planetPtr->GetDirectOrbit() == nullptr) {
        return count;
    }
    count++;
    count += getOrbitCount(planetPtr->GetDirectOrbit());
   
    return count;
}

int main() {
    // Insert the puzzle input into the empty text file

    vector<string> orbitPairs;
    fstream textFile;
   
    textFile.open("input.txt");

    if (textFile.is_open()) { 
        string line;
        while(getline(textFile, line)) {
            orbitPairs.push_back(line);
        }
        textFile.close();
    }
    
    vector<Planet*> allPlanetPtrs;
    
    for (unsigned int i = 0; i < orbitPairs.size(); ++i) {
        string firstString = orbitPairs.at(i).substr(0, 3);
        string secondString = orbitPairs.at(i).substr(4, 3);
        
        int firstPlanetIndex = -1;
        int secondPlanetIndex = -1;

        if (allPlanetPtrs.size() > 0) {
            for (unsigned int j = 0; j < allPlanetPtrs.size(); ++j) {
                if (allPlanetPtrs.at(j)->GetName() == firstString) {
                    firstPlanetIndex = j;
                    break;
                }
            }
        }

        if (allPlanetPtrs.size() > 0) {
            for (unsigned int j = 0; j < allPlanetPtrs.size(); ++j) {
                if (allPlanetPtrs.at(j)->GetName() == secondString) {
                    secondPlanetIndex = j;
                    break;
                }
            }
        }

        if ((firstPlanetIndex >= 0) && (secondPlanetIndex >= 0) && (allPlanetPtrs.at(secondPlanetIndex)->GetDirectOrbit() == nullptr)) {
            allPlanetPtrs.at(secondPlanetIndex)->SetDirectOrbit(allPlanetPtrs.at(firstPlanetIndex));
        }
        else if (firstPlanetIndex >= 0) {
            Planet* secondPlanetPtr = new Planet(secondString);
            allPlanetPtrs.push_back(secondPlanetPtr);
            secondPlanetPtr->SetDirectOrbit(allPlanetPtrs.at(firstPlanetIndex));
            
        }
        else if ((secondPlanetIndex >= 0) && (allPlanetPtrs.at(secondPlanetIndex)->GetDirectOrbit() == nullptr)) {
            Planet* firstPlanetPtr = new Planet(firstString);
            allPlanetPtrs.push_back(firstPlanetPtr);
            allPlanetPtrs.at(secondPlanetIndex)->SetDirectOrbit(firstPlanetPtr);
        }
        else {
            Planet* firstPlanetPtr = new Planet(firstString);
            Planet* secondPlanetPtr = new Planet(secondString);
            allPlanetPtrs.push_back(firstPlanetPtr);
            allPlanetPtrs.push_back(secondPlanetPtr);
            secondPlanetPtr->SetDirectOrbit(firstPlanetPtr);
        }             
    }

    int orbitCount = 0; 

    for (unsigned int i = 0; i < allPlanetPtrs.size(); ++i) { 
        orbitCount += getOrbitCount(allPlanetPtrs.at(i));
    }

    cout << orbitCount << endl;

    return 0;
}
