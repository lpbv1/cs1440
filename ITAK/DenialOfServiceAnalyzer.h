
#ifndef ITAK_DENIALOFSERVICEANALYZER_H
#define ITAK_DENIALOFSERVICEANALYZER_H
#include "Analyzer.h"

class DenialOfServiceAnalyzer : public Analyzer{
private:

public:
    ResultSet run(std::istream& in);
    DenialOfServiceAnalyzer(Configuration newConf);
};


#endif //ITAK_DENIALOFSERVICEANALYZER_H
