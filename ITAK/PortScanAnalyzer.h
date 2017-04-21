
#ifndef ITAK_PORTSCANANALYZER_H
#define ITAK_PORTSCANANALYZER_H
#include "Analyzer.h"

class PortScanAnalyzer : public Analyzer{
private:
    std::string* row;
    std::vector<std::string*> data;
public:
    ResultSet run(std::istream& in);
    PortScanAnalyzer(Configuration newConf);
};


#endif //ITAK_PORTSCANANALYZER_H
