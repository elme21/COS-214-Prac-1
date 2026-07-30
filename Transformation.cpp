#include "Transformation.h"

Transformation::Transformation(string name) : name(name) {}

string Transformation::getName() const {
    return name;
}

Transformation::~Transformation() {}