#include "DeduplicateStep.h"

DeduplicateStep::DeduplicateStep() : Transformation("dedup") {}

Transformation* DeduplicateStep::clone() {
    return new DeduplicateStep();
}

vector<string> DeduplicateStep::apply(vector<string> records) {
    vector<string> result;
    for (size_t i = 0; i < records.size(); i++) {
        if (result.empty() || result.back() != records[i]) {
            result.push_back(records[i]);
        }
    }
    return result;
}