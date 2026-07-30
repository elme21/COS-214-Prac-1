#include "AggregateByRegionStep.h"

AggregateByRegionStep::AggregateByRegionStep() : Transformation("aggregate") {}

    Transformation* AggregateByRegionStep::clone() {
        return new AggregateByRegionStep();
}

vector<string> AggregateByRegionStep::apply(vector<string> records) {
    return {"COUNT=" + to_string(records.size())};
}