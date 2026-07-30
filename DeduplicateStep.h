#ifndef DEDUPLICATESTEP_H
#define DEDUPLICATESTEP_H

#include "Transformation.h"

class DeduplicateStep : public Transformation {
public:
    DeduplicateStep();
    Transformation* clone() override;
    vector<string> apply(vector<string> records) override;
};

#endif