#include "Station.h"
#include <fstream>

using std::fstream;
using std::cout;
using std::endl;

vector<string> getInput() {
    // Insert the puzzle input into the empty text file
    vector<string> initialRows;
    fstream textFile;
    textFile.open("input.txt");

    if (textFile.is_open()) { 
        string line;
        while(getline(textFile, line)) {
            initialRows.push_back(line);
        }
        textFile.close();
    }
    return initialRows;
}

int main() {
    vector<string> rows = getInput();
    Station myStation(rows, rows.size(), rows.at(0).size());

    for (int i = 0; i < myStation.numRows; ++i) {
        for (int j = 0; j < myStation.numCols; ++j) {
            myStation.resetDetected();
            if (myStation.asteroids[i][j] == '#') {
                myStation.detectDirectNorthEast(i, j, false);
                myStation.detectNorthEast(i, j, false);
                myStation.detectDirectSouthEast(i, j, false);
                myStation.detectSouthEast(i, j, false);
                myStation.detectDirectSouthWest(i, j, false);
                myStation.detectSouthWest(i, j, false);
                myStation.detectDirectNorthWest(i, j, false);
                myStation.detectNorthWest(i, j, false);
                myStation.addDetectedCount(i, j);
            }
        }
    }
    int stationCoord = myStation.getMaxDetectedCoord();
    int stationRow = stationCoord / myStation.numCols;
    int stationCol = stationCoord % myStation.numCols;
    myStation.resetDetected();

    while (myStation.vaporizedCount < 300) {
        myStation.detectDirectNorthEast(stationRow, stationCol, true);
        myStation.detectNorthEast(stationRow, stationCol, true);
        myStation.detectDirectSouthEast(stationRow, stationCol, true);
        myStation.detectSouthEast(stationRow, stationCol, true);
        myStation.detectDirectNorthWest(stationRow, stationCol, true);
        myStation.detectNorthWest(stationRow, stationCol, true);
        myStation.detectDirectSouthWest(stationRow, stationCol, true);
        myStation.detectSouthWest(stationRow, stationCol, true);
        ++myStation.rotations;
    }
    myStation.sortForTwoHundreth(); 

    return 0;
}