

#include "PortScanAnalyzer.h"

PortScanAnalyzer::PortScanAnalyzer(Configuration newConf)
        : Analyzer(newConf){

}

ResultSet PortScanAnalyzer::run(std::istream& in){
    Dictionary<std::string, Dictionary<std::string, std::string>> analysis;
    while(!in.eof()) {
        std::string temp = "";
        in >> temp;
        split(temp, ',', row, 4);
        data.push_back(row);
    }
    std::reverse(data.begin(), data.end());

}