

#ifndef ITAK_RESULTSET_H
#define ITAK_RESULTSET_H
#include "Dictionary.h"
#include <vector>
#include <ostream>

class ResultSet {
private:
    Dictionary<std::string, std::vector<std::string>> Results;
    int m_size;
    std::string m_type;
public:
    void print(std::ostream& out);
    void add(std::string key, std::string value);
    void setType(std::string type);
};


#endif //ITAK_RESULTSET_H
