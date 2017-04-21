

#ifndef ITAK_CONFIGURATION_H
#define ITAK_CONFIGURATION_H
#include "Dictionary.h"
#include <string>

class Configuration {
private:
    Dictionary<std::string, std::string> confValues;
    int m_size;
public:
    void addParam(std::string key, std::string value);
    void removeParam(std::string key);
    std::string getValStr(std::string key);
    int getValInt(std::string key);
    double getValDub(std::string key);
    int getSize(){return m_size;};
};


#endif //ITAK_CONFIGURATION_H
