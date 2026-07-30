#ifndef TRANSFORMATIONREGISTRY_H
#define TRANSFORMATIONREGISTRY_H

#include "Transformation.h"
#include <map>
#include <string>

using namespace std;

class TransformationRegistry {
private:
    map<string, Transformation*> prototypes;

public:
    void registerStep(string key, Transformation* prototype);
    Transformation* create(string key);
    ~TransformationRegistry();
};

#endif