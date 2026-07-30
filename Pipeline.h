#ifndef PIPELINE_H
#define PIPELINE_H

#include <vector>
#include <string>
#include "ConnectorFactory.h"
#include "Transformation.h"

using namespace std;

class RunCheckpoint;

class Pipeline {
protected:
    ConnectorFactory* factory;
    vector<Transformation*> steps;
    int stage;
    vector<string> records;

    void connect();
    virtual void extract() = 0;
    void transform();
    virtual void load() = 0;

public:
    Pipeline(ConnectorFactory* factory);
    void run();
    void addStep(Transformation* step);
    RunCheckpoint* createCheckpoint();
    void restore(RunCheckpoint* cp);
    virtual ~Pipeline();
};

#endif