#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <string>
#include <vector>


using std::string;
using std::vector;

class Station {
    public:
        Station(vector<string> rows, int numRows, int numCols);
        ~Station();
        void resetDetected();
        void resetFactors();
        bool detectAsteroid(int k, int l);
        bool noCommonFactors();
        void detectDirectLines(int i, int j);
        void detectSouthEast(int i, int j);
        void detectSouthWest(int i, int j);
        void detectNorthEast(int i, int j);
        void detectNorthWest(int i, int j);
        void addDetectedCount(int i, int j);
        int getMaxDetected();
        int numRows;
        int numCols;
        char** asteroids = nullptr;
        int** detected = nullptr;
        int rowFactor;
        int colFactor;
        int* detectedCounts = nullptr;
        int maxDetected;
};

#endif //STATION_H