#include "StreamingPipeline.h"
#include "Connector.h"
#include <iostream>

StreamingPipeline::StreamingPipeline(ConnectorFactory* factory) : Pipeline(factory) {}

void StreamingPipeline::extract() 
{
    Connector* connector = factory->createConnector();
    records = connector->extract();
    cout << "Streaming extract: " << records.size() << " records" << endl;
    stage = 2;
    delete connector;
}

void StreamingPipeline::load() 
{
    cout << "Streaming load: " << records.size() << " records streamed" << endl;
    stage = 4;
}