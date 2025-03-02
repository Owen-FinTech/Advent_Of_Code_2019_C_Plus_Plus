#include "Station.h"

Station::Station(vector<string> rows, int numRows, int numCols) {
    this->numRows = numRows;
    this->numCols = numCols;
    asteroids = new char*[numRows];
    for (unsigned int i = 0; i < numRows; ++i) {
        asteroids[i] = new char[numCols];
        for (unsigned int j = 0; j < numCols; ++j) {
            asteroids[i][j] = rows.at(i).at(j);
        }
    }
    detected = new double*[numRows];
    for (int i = 0; i < numRows; ++i) {
        detected[i] = new double[numCols];
        for (int j = 0; j < numCols; ++j) {
            detected[i][j] = 0.0;
        }
    }
    detectedCounts = new int[numRows * numCols];
    for (int i = 0; i < numRows * numCols; ++i) {
        detectedCounts[i] = 0;
    }
    maxDetected = 0; 
    rowFactor = 1;
    colFactor = 1;
    maxDetectedCoord = 0;
    vaporizedCount = 0;
    finalVaporizedCoord = 0;
    rotations = 0;   
}

Station::~Station() {
    for (int i = 0; i < numRows; ++i) {
        delete[] asteroids[i];
        delete[] detected[i];
    }
    delete[] asteroids;
    delete[] detected;
    delete[] detectedCounts;
}
 
void Station::resetDetected() {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            detected[i][j] = 0.0;
        }
    }
}

void Station::resetFactors() {
    rowFactor = 1;
    colFactor = 1;
}

bool Station::noCommonFactors() {
    bool noCommon = true;
    int minFactor = 0;
    if (this->rowFactor < colFactor) {
        minFactor = this->rowFactor;
    }
    else {
        minFactor = this->colFactor;
    }

    for (int i = 2; i <= minFactor; ++i) {
        if ((this->rowFactor % i == 0) && (this->colFactor % i == 0)) {
            noCommon = false;
            break;
        }
    }
    return noCommon;
}

bool Station::detectAsteroid(int k, int l) {
    bool isDetected = false;
    if (asteroids[k][l] == '#') {
        detected[k][l] = 1.0;
        isDetected = true;
    }
    return isDetected;
}

double Station::getAngle(int i, int j, int k, int l) {
    double up = atan2(0, 1);
    double counterClockwise = atan2(j - l, i - k);
    double angle = up - counterClockwise;
    if (angle > PI) {
        angle -= 2 * PI;
    }
    else if (angle < -PI) {
        angle += 2 * PI;
    }

    angle = (angle * 180.0) / PI; 
    if (angle < 0.0) {
        angle += 360.0;
    }

    angle += rotations * 360.0;
    if (angle == 0.0) {
        angle = -360.0;
    }
    return angle;
}

bool Station::vaporizeAsteroid(int i, int j, int k, int l) {
    bool isVaporized = false;
    if (asteroids[k][l] == '#') {
        asteroids[k][l] == '.';
        detected[k][l] = getAngle(i, j, k, l);
        isVaporized = true;
        ++vaporizedCount;
    }
    return isVaporized;
}

void Station::detectDirectSouthEast(int i, int j, bool vaporize) {
    bool blocked = false;
    int k = i;
    for (int l = j + 1; l < numCols; ++l) {
        if (vaporize) {
            blocked = this->vaporizeAsteroid(i, j, k, l);
        }
        else {
            blocked = this->detectAsteroid(k, l);
        }
        if (blocked) {break;}
    }
}

void Station::detectDirectSouthWest(int i, int j, bool vaporize) {
    bool blocked = false;
    int k = i;
    for (int l = j - 1; l >= 0; --l) {
        if (vaporize) {
            blocked = this->vaporizeAsteroid(i, j, k, l);
        }
        else {
            blocked = this->detectAsteroid(k, l);
        }
        if (blocked) {break;}
    }
}

void Station::detectDirectNorthEast(int i, int j, bool vaporize) {
    bool blocked = false;
    int l = j;
    for (int k = i - 1; k >= 0; --k) {
        if (vaporize) {
            blocked = this->vaporizeAsteroid(i, j, k, l);
        }
        else {
            blocked = this->detectAsteroid(k, l);
        }
        if (blocked) {break;}
    }
}

void Station::detectDirectNorthWest(int i, int j, bool vaporize) {
    bool blocked = false;
    int l = j;
    for (int k = i + 1; k < numRows; ++k) {
        if (vaporize) {
            blocked = this->vaporizeAsteroid(i, j, k, l);
        }
        else {
            blocked = this->detectAsteroid(k, l);
        }
        if (blocked) {break;}
    }
}

void Station::detectSouthEast(int i, int j, bool vaporize) {
    this->resetFactors();
    bool blocked = false;
    int k = i + rowFactor;
    int l = j + colFactor;
    while (rowFactor < numRows) {
        while (k < numRows && l < numCols) {
            bool noCommon = this->noCommonFactors();
            if (noCommon) {
                while (k < numRows && l < numCols) {
                    if (vaporize) {
                        blocked = this->vaporizeAsteroid(i, j, k, l);
                    }
                    else {
                        blocked = this->detectAsteroid(k, l);
                    }
                    if (blocked) {break;}
                    k += rowFactor;
                    l += colFactor;
                }
            }
            ++colFactor;
            k = i + rowFactor;
            l = j + colFactor;
        }
        ++rowFactor;
        colFactor = 1;
        k = i + rowFactor;
        l = j + colFactor;
    }
}

void Station::detectSouthWest(int i, int j, bool vaporize) {
    this->resetFactors();
    bool blocked = false;
    int k = i + rowFactor;
    int l = j - colFactor;
    while (rowFactor < numRows) {
        while (k < numRows && l >= 0) {
            bool noCommon = this->noCommonFactors();
            if (noCommon) {
                while (k < numRows && l >= 0) {
                    if (vaporize) {
                        blocked = this->vaporizeAsteroid(i, j, k, l);
                    }
                    else {
                        blocked = this->detectAsteroid(k, l);
                    }
                    if (blocked) {break;}
                    k += rowFactor;
                    l -= colFactor;
                }
            }
            ++colFactor;
            k = i + rowFactor;
            l = j - colFactor;
        }
        ++rowFactor;
        colFactor = 1;
        k = i + rowFactor;
        l = j - colFactor;
    }
}

void Station::detectNorthEast(int i, int j, bool vaporize) {
    this->resetFactors();
    bool blocked = false;
    int k = i - rowFactor;
    int l = j + colFactor;
    while (colFactor < numCols) {
        while (k >= 0 && l < numCols) {
            bool noCommon = this->noCommonFactors();
            if (noCommon) {
                while (k >= 0 && l < numCols) {
                    if (vaporize) {
                        blocked = this->vaporizeAsteroid(i, j, k, l);
                    }
                    else {
                        blocked = this->detectAsteroid(k, l);
                    }
                    if (blocked) {break;}
                    k -= rowFactor;
                    l += colFactor;
                }
            }
            ++rowFactor;
            k = i - rowFactor;
            l = j + colFactor;
        }
        ++colFactor;
        rowFactor = 1;
        k = i - rowFactor;
        l = j + colFactor;
    }
}

void Station::detectNorthWest(int i, int j, bool vaporize) {
    this->resetFactors();
    bool blocked = false;
    int k = i - rowFactor;
    int l = j - colFactor;
    while (colFactor < numCols) {
        while (k >= 0 && l >= 0) {
            bool noCommon = this->noCommonFactors();
            if (noCommon) {
                while (k >= 0 && l >= 0) {
                    if (vaporize) {
                        blocked = this->vaporizeAsteroid(i, j, k, l);
                    }
                    else {
                        blocked = this->detectAsteroid(k, l);
                    }
                    if (blocked) {break;}
                    k -= rowFactor;
                    l -= colFactor;
                }
            }
            ++rowFactor;
            k = i - rowFactor;
            l = j - colFactor;
        }
        ++colFactor;
        rowFactor = 1;
        k = i - rowFactor;
        l = j - colFactor;
    }     
}

void Station::addDetectedCount(int i, int j) {
    int detectedCount = 0;
    for (int k = 0; k < numRows; ++k) {
        for (int l = 0; l < numCols; ++l) {
            if (detected[k][l] > 0.0) {
                ++detectedCount;
            }
        }
    }
    detectedCounts[(i * numCols) + j] = detectedCount;
}

int Station::getMaxDetectedCoord() {
    maxDetected = 0;
    maxDetectedCoord = 0;
    for (int i = 0; i < (numRows * numCols); ++i) {
        if (detectedCounts[i] > maxDetected) {
            maxDetected = detectedCounts[i];
            maxDetectedCoord = i;
        }
    }
    return maxDetectedCoord;
}

void Station::sortForTwoHundreth() {
    vector<double> allAngles;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (detected[i][j] != 0.0) {
                allAngles.push_back(detected[i][j]);
            }
        }
    }

    for (int i = 0; i < allAngles.size() - 1; i++) { 
        for (int j = 0; j < allAngles.size() - i - 1; j++) { 
            if (allAngles.at(j) > allAngles.at(j + 1)) {
                double temp = allAngles.at(j);
                allAngles.at(j) = allAngles.at(j + 1);
                allAngles.at(j + 1) = temp;
            }
        }
    }
     
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (detected[i][j] == allAngles.at(199)) {
                cout << (j * 100) + i << endl;
            }
        }
    }
    
}