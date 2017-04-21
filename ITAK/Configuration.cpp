

#include "Configuration.h"
void Configuration::addParam(std::string key, std::string value) {
    try{
        confValues.add(key, value);
        m_size++;
    }catch(std::string ex){

    }
}

void Configuration::removeParam(std::string key) {
    try{
        confValues.removeByKey(key);
        m_size--;
    }catch(std::string ex){

    }
}

std::string Configuration::getValStr(std::string key) {
    return confValues.getByKey(key).getValue();
}

int Configuration::getValInt(std::string key) {
    int temp = 0;
    try{
        temp = std::stoi(confValues.getByKey(key).getValue());
    }catch(std::exception ex){

    }
    return temp;
}

double Configuration::getValDub(std::string key) {
    double temp = 0;
    try{
        temp = std::stod(confValues.getByKey(key).getValue());
    }catch(std::exception ex){

    }
    return temp;
}