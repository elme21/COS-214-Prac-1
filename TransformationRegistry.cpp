#include "TransformationRegistry.h"

void TransformationRegistry::registerStep(string key, Transformation* prototype) {
    map<string, Transformation*>::iterator it = prototypes.find(key);
    if (it != prototypes.end()) {
        delete it->second;
    }
    prototypes[key] = prototype;
}

Transformation* TransformationRegistry::create(string key) {
    map<string, Transformation*>::iterator it = prototypes.find(key);
    if (it == prototypes.end()) {
        return nullptr;
    }
    return it->second->clone();
}

TransformationRegistry::~TransformationRegistry() {
    for (map<string, Transformation*>::iterator it = prototypes.begin(); it != prototypes.end(); ++it) {
        delete it->second;
    }
}