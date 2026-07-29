#ifndef CSVCONNECTOR_H
#define CSVCONNECTOR_H

#include "Connector.h"

using namespace std;

class CsvConnector : public Connector {

public:
    CsvConnector();
    vector<string> extract() override;
};

#endif