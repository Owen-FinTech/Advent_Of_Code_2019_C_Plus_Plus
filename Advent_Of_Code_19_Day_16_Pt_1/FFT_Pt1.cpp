#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MULTI_LINE_STRING(...) #__VA_ARGS__

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;

int main() {
    string inputString = MULTI_LINE_STRING(
59718730609456731351293131043954182702121108074562978243742884161871544398977055503320958653307507508966449714414337735187580549358362555889812919496045724040642138706110661041990885362374435198119936583163910712480088609327792784217885605021161016819501165393890652993818130542242768441596060007838133531024988331598293657823801146846652173678159937295632636340994166521987674402071483406418370292035144241585262551324299766286455164775266890428904814988362921594953203336562273760946178800473700853809323954113201123479775212494228741821718730597221148998454224256326346654873824296052279974200167736410629219931381311353792034748731880630444730593
); // Insert the puzzle input here
    vector<int> signal;

    for (unsigned int i = 0; i < inputString.size(); ++i) {
        string charAsString = inputString.substr(i, 1);
        signal.push_back(stoi(charAsString));
    }

    vector<int> base;
    base.push_back(0);
    base.push_back(1);
    base.push_back(0);
    base.push_back(-1);
    int baseSize = 4;
    vector<int> newSignal(signal.size());

    for (int i = 0; i < 100; ++i) {
        for (unsigned int j = 0; j < signal.size(); ++j) {
            int newSignalInt = 0;
            int baseCount = 0;
            for (unsigned int k = 0; k < signal.size(); ++k) {
                if ((k + 1) % (j + 1) == 0) {
                    ++baseCount;
                }
                newSignalInt += signal.at(k) * base.at(baseCount % baseSize);
            }
            newSignal.at(j) = static_cast<int>(fabs(static_cast<double>(newSignalInt))) % 10;
        } 

        for (unsigned int j = 0; j < signal.size(); ++j) {
            signal.at(j) = newSignal.at(j);
        }
    }

    for (int i = 0; i < 8; ++i) {
        cout << signal.at(i); 
    }
    cout << endl;

    return 0;
}