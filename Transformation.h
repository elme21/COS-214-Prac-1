#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <string>
#include <vector>

using namespace std;

class Transformation {
protected:
    string name;

public:
    Transformation(string name);
    virtual Transformation* clone() = 0;
    virtual vector<string> apply(vector<string> records) = 0;
    string getName() const;
    virtual ~Transformation();
};

#endif