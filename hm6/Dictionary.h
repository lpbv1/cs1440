//
// Created by telepatheticman on 4/4/2017.
//

#ifndef HM6_DICTIONARY_H
#define HM6_DICTIONARY_H

#include "KeyValue.h"
#include <string>
#include <iostream>

template <typename T, typename S>
class Dictionary {
private:
    int m_Size;
    KeyValue* keyValue;
    int m_idTally;
    void resize();
    void update();
public:
    Dictionary();
    Dictionary(int size);
    ~Dictionary();
    Dictionary (const Dictionary &obj);
    void add(T newKey, S newValue);
    void removeById(int id);
    void removeByKey(T Key);
    KeyValue getById(int id);
    KeyValue& operator[](int id) const;
    KeyValue getByKey(T key){};
    int getCount(){return m_idTally;};
};


#endif //HM6_DICTIONARY_H
