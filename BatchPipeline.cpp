#include "BatchPipeline.h"
#include "Connector.h"
#include <iostream>

BatchPipeline::BatchPipeline(ConnectorFactory* factory) : Pipeline(factory) {}

void BatchPipeline::extract() 
{
    Connector* connector = factory->createConnector();
    records = connector->extract();
    cout << "Batch extract: " << records.size() << " records" << endl;
    stage = 2;
    delete connector;
}

void BatchPipeline::load() 
{
    cout << "Batch load: " << records.size() << " records written" << endl;
    stage = 4;
}