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
                myStation.detectDirectLines(i, j);
                myStation.detectSouthEast(i, j);
                myStation.detectSouthWest(i, j);
                myStation.detectNorthEast(i, j);
                myStation.detectNorthWest(i, j);
                myStation.addDetectedCount(i, j);
            }
        }
    }
    cout << myStation.getMaxDetected() << endl;
    return 0;
}