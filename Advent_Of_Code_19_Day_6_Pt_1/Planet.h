#ifndef PLANET_H_
#define PLANET_H_
#include <iostream>
#include <string>

using std::string;

class Planet {
    public:
        string name;
        Planet* directOrbitPtr;

        Planet(string name);

        void SetDirectOrbit(Planet* planetPtr);

        string GetName() const;

        Planet* GetDirectOrbit();
};

#endif