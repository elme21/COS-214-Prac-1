#ifndef RESTAPICONNECTOR_H
#define RESTAPICONNECTOR_H

#include "Connector.h"

using namespace std;

class RestApiConnector : public Connector {
public:
    RestApiConnector();
    vector<string> extract() override;
};

#endif