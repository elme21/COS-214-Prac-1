#include "Pipeline.h"
#include "RunCheckpoint.h"
#include "Connector.h"
#include <iostream>

Pipeline::Pipeline(ConnectorFactory* factory) : factory(factory), stage(0) {}

void Pipeline::addStep(Transformation* step) 
{
    if (step == nullptr) {
        return;
    }
    steps.push_back(step);
}

void Pipeline::run() 
{
    connect();
    extract();
    transform();
    load();
}

void Pipeline::connect() 
{
    Connector* connector = factory->createConnector();
    cout << "Connecting to " << connector->getSource() << endl;
    stage = 1;
    delete connector;
}

void Pipeline::transform() 
{
    for (size_t i = 0; i < steps.size(); i++) {
        records = steps[i]->apply(records);
    }
    stage = 3;
}

RunCheckpoint* Pipeline::createCheckpoint() 
{
    return new RunCheckpoint(stage, records);
}

void Pipeline::restore(RunCheckpoint* cp) 
{
    if (cp == nullptr) 
    {
        return;
    }
    stage = cp->getStage();
    records = cp->getRecords();
}

Pipeline::~Pipeline() 
{
    delete factory;
    for (size_t i = 0; i < steps.size(); i++) 
    {
        delete steps[i];
    }
}