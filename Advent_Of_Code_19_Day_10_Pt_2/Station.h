#ifndef STATION_H
#define STATION_H
#define PI 3.14159265

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Station {
    public:
        Station(vector<string> rows, int numRows, int numCols);
        ~Station();
        void resetDetected();
        void resetFactors();
        bool noCommonFactors();
        bool detectAsteroid(int k, int l);
        double getAngle(int i, int j, int k, int l);
        bool vaporizeAsteroid(int i, int j, int k, int l);
        void detectDirectSouthEast(int i, int j, bool vaporize);
        void detectDirectSouthWest(int i, int j, bool vaporize);
        void detectDirectNorthEast(int i, int j, bool vaporize);
        void detectDirectNorthWest(int i, int j, bool vaporize);
        void detectSouthEast(int i, int j, bool vaporize);
        void detectSouthWest(int i, int j, bool vaporize);
        void detectNorthEast(int i, int j, bool vaporize);
        void detectNorthWest(int i, int j, bool vaporize);
        void addDetectedCount(int i, int j);
        int getMaxDetectedCoord();
        void sortForTwoHundreth();
        int numRows;
        int numCols;
        char** asteroids = nullptr;
        double** detected = nullptr;
        int rowFactor;
        int colFactor;
        int* detectedCounts = nullptr;
        int maxDetected;
        int maxDetectedCoord;
        int vaporizedCount;
        int finalVaporizedCoord;
        int rotations;
};

#endif //STATION_H