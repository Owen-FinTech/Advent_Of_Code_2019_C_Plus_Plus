#include "Planet.h"
#include <iostream>
#include <string>

using std::string;

Planet::Planet(string name) {
    this->name = name;
    this->directOrbitPtr = nullptr;
}

void Planet::SetDirectOrbit(Planet* planetPtr) {
    this->directOrbitPtr = planetPtr;
}

string Planet::GetName() const{
    return this->name;
}

Planet* Planet::GetDirectOrbit() {
    return this->directOrbitPtr;
}

