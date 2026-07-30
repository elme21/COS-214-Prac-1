#ifndef RUNCHECKPOINT_H
#define RUNCHECKPOINT_H

#include <vector>
#include <string>

using namespace std;

class RunCheckpoint {
private:
    int stage;
    vector<string> records;

public:
    RunCheckpoint(int stage, vector<string> records);
    int getStage() const;
    vector<string> getRecords() const;
};

#endif