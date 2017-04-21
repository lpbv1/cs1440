

#ifndef ITAK_ANALYZER_H
#define ITAK_ANALYZER_H
#include "Dictionary.h"
#include "Configuration.h"
#include "ResultSet.h"
#include "Utils.h"
#include <algorithm>
#include <istream>
#include <vector>

class Analyzer {
protected:
    Configuration conf;
    ResultSet Result;

public:
    virtual ResultSet run(std::istream& in);
    Analyzer(Configuration newConf);
    Analyzer();
};


#endif //ITAK_ANALYZER_H
