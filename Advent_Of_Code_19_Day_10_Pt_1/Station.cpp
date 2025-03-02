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
    detected = new int*[numRows];
    for (int i = 0; i < numRows; ++i) {
        detected[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            detected[i][j] = 0;
        }
    }
    detectedCounts = new int[numRows * numCols];
    for (int i = 0; i < numRows * numCols; ++i) {
        detectedCounts[i] = 0;
    }
    maxDetected = 0; 
    rowFactor = 1;
    colFactor = 1;   
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
            detected[i][j] = 0;
        }
    }
}

void Station::resetFactors() {
    rowFactor = 1;
    colFactor = 1;
}

bool Station::detectAsteroid(int k, int l) {
    bool isDetected = false;
    if (asteroids[k][l] == '#') {
        detected[k][l] = 1;
        isDetected = true;
    }
    return isDetected;
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

void Station::detectDirectLines(int i, int j) {
    int k = i;
    for (int l = j + 1; l < numCols; ++l) {
        bool blocked = this->detectAsteroid(k, l);
        if (blocked) {break;}
    }
    k = i;
    for (int l = j - 1; l >= 0; --l) {
        bool blocked = this->detectAsteroid(k, l);
        if (blocked) {break;}
    }
    int l = j;
    for (int k = i - 1; k >= 0; --k) {
        bool blocked = this->detectAsteroid(k, l);
        if (blocked) {break;}
    }
    l = j;
    for (int k = i + 1; k < numRows; ++k) {
        bool blocked = this->detectAsteroid(k, l);
        if (blocked) {break;}
    }
}

void Station::detectSouthEast(int i, int j) {
    this->resetFactors();
    int k = i + rowFactor;
    int l = j + colFactor;
    while (rowFactor < numRows) {
        while (k < numRows && l < numCols) {
            bool noCommon = this->noCommonFactors();
            if (noCommon) {
                while (k < numRows && l < numCols) {
                    bool blocked = this->detectAsteroid(k, l);
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

void Station::detectSouthWest(int i, int j) {
    this->resetFactors();
    int k = i + rowFactor;
    int l = j - colFactor;
    while (rowFactor < numRows) {
        while (k < numRows && l >= 0) {
            bool noCommon = this->noCommonFactors();
            if (noCommon) {
                while (k < numRows && l >= 0) {
                    bool blocked = this->detectAsteroid(k, l);
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

void Station::detectNorthEast(int i, int j) {
    this->resetFactors();
    int k = i - rowFactor;
    int l = j + colFactor;
    while (colFactor < numCols) {
        while (k >= 0 && l < numCols) {
            bool noCommon = this->noCommonFactors();
            if (noCommon) {
                while (k >= 0 && l < numCols) {
                    bool blocked = this->detectAsteroid(k, l);
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

void Station::detectNorthWest(int i, int j) {
    this->resetFactors();
    int k = i - rowFactor;
    int l = j - colFactor;
    while (colFactor < numCols) {
        while (k >= 0 && l >= 0) {
            bool noCommon = this->noCommonFactors();
            if (noCommon) {
                while (k >= 0 && l >= 0) {
                    bool blocked = this->detectAsteroid(k, l);
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
            if (detected[k][l] == 1) {
                ++detectedCount;
            }
        }
    }
    detectedCounts[(i * numCols) + j] = detectedCount;
}

int Station::getMaxDetected() {
    maxDetected = 0;
    for (int i = 0; i < (numRows * numCols); ++i) {
        if (detectedCounts[i] > maxDetected) {
            maxDetected = detectedCounts[i];
        }
    }
    return maxDetected;
}

