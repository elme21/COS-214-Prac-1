#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include "RunCheckpoint.h"
#include <vector>

using namespace std;

class CheckpointManager {
private:
    vector<RunCheckpoint*> history;

public:
    void save(RunCheckpoint* cp);
    RunCheckpoint* undo();
    ~CheckpointManager();
};

#endif