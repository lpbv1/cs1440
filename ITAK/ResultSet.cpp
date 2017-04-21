

#include "ResultSet.h"
void ResultSet::add(std::string key, std::string value) {
    if(Results.Found(key)){
        std::vector<std::string> temp = Results.getByKey(key).getValue();
        temp.push_back(value);
        Results.getByKey(key).setValue(temp);
    }else{
        std::vector<std::string> temp;
        temp.push_back(value);
        Results.add(key, temp);
        m_size++;
    }
}

void ResultSet::setType(std::string type) {
    m_type = type;
}

void ResultSet::print(std::ostream& out){
    out << "-vv-" << m_type << "-vv-" << std::endl << std::endl;
    for(int x = 0; x < m_size; x++){
        out << "\t" << Results.getByIndex(x).getKey() << std::endl;
        for(int y = 0 ; y < Results.getByIndex(x).getValue().size(); y++){
            out << "\t\t" << Results.getByIndex(x).getValue()[y] << std::endl;
        }
        out << std::endl;
    }
}
