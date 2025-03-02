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

int countTransfers(vector<Planet*> allPlanetPtrs) {
    int transfers = 0;
    vector<Planet*> visitedPtrs;
    vector<Planet*> currPtrs;
    Planet* startPtr = nullptr;
    Planet* endPtr = nullptr;

    for (unsigned int i = 0; i < allPlanetPtrs.size(); ++i) {
        if (allPlanetPtrs.at(i)->GetName() == "YOU") {
            startPtr = allPlanetPtrs.at(i)->GetDirectOrbit();
        }
        else if (allPlanetPtrs.at(i)->GetName() == "SAN") {
            endPtr = allPlanetPtrs.at(i)->GetDirectOrbit();
        }
    }

    currPtrs.push_back(startPtr);
    bool foundEnd = false;
    vector<Planet*> tempCurrPtrs;

    while (!foundEnd) {
        for (unsigned int i = 0; i < currPtrs.size(); ++i) {
            if (currPtrs.at(i) == endPtr) {
                foundEnd = true;
                break;
            }
        }

        if (foundEnd) {
            break;
        }

        transfers += 1;

        for (unsigned int i = 0; i < currPtrs.size(); ++i) {
            visitedPtrs.push_back(currPtrs.at(i));
        }

        for (unsigned int i = 0; i < currPtrs.size(); ++i) {
            bool directVisited = false;
            for (unsigned int j = 0; j < visitedPtrs.size(); ++j) {
                if (currPtrs.at(i)->GetDirectOrbit() != nullptr)
                    if (currPtrs.at(i)->GetDirectOrbit() == visitedPtrs.at(j)) {
                        directVisited = true; 
                        break;
                    }
            }

            if (!directVisited && (currPtrs.at(i)->GetDirectOrbit() != nullptr)) {
                tempCurrPtrs.push_back(currPtrs.at(i)->GetDirectOrbit());
            }

            for (unsigned int j = 0; j < allPlanetPtrs.size(); ++j) {
                bool parentVisited = false;

                if (allPlanetPtrs.at(j)->GetDirectOrbit() != nullptr) {
                    if (allPlanetPtrs.at(j)->GetDirectOrbit() == currPtrs.at(i)) {
                        for (unsigned int k = 0; k < visitedPtrs.size(); ++k) {
                            if (allPlanetPtrs.at(j) == visitedPtrs.at(k)) {
                                parentVisited = true;
                                break;
                            }
                        }

                        if (!parentVisited) {
                            tempCurrPtrs.push_back(allPlanetPtrs.at(j));
                        }
                    }
                }
            }
        }

        currPtrs.clear();

        for (unsigned int i = 0; i < tempCurrPtrs.size(); ++i) {
            currPtrs.push_back(tempCurrPtrs.at(i));
        } 

        tempCurrPtrs.clear();
    }
    
    return transfers;
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

    cout << countTransfers(allPlanetPtrs) << endl;

    return 0;
}
