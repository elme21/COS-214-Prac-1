#ifndef AGGREGATEBYREGIONSTEP_H
#define AGGREGATEBYREGIONSTEP_H

#include "Transformation.h"

class AggregateByRegionStep : public Transformation {
public:
    AggregateByRegionStep();
    Transformation* clone() override;
    vector<string> apply(vector<string> records) override;
};

#endif