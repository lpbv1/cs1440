//
// Created by telepatheticman on 4/4/2017.
//

#include "Dictionary.h"

Dictionary::Dictionary() {
    m_idTally = 0;
    m_Size = 10;
    keyValue = new KeyValue[m_Size];
}

Dictionary::Dictionary(int size){
    m_idTally = 0;
    m_Size = size;
    keyValue = new KeyValue[m_Size];
}

Dictionary::~Dictionary(){
    keyValue = nullptr;
    delete[]keyValue;
}

Dictionary::Dictionary (const Dictionary &obj){

}

void Dictionary::resize() {
    m_Size++;
    KeyValue* temp = new KeyValue[m_Size];
    for (int x = 0; x < m_Size - 1; x++){
        temp[x] = keyValue[x];
    }
    delete[]keyValue;
    keyValue = temp;
    temp = nullptr;
}

void Dictionary::update() {
    for (int x = 0; x < m_idTally; x++){
        keyValue[x].setId(x);
    }
}

KeyValue& Dictionary::operator[](int id) const {
    if(id < m_idTally) {
        return keyValue[id];
    }else{
        throw "id out of range";
    }
}
template <typename T, typename S>
void Dictionary::add(T newKey, S newValue){
    if(m_idTally < m_Size){
        keyValue[m_idTally].setKey(newKey);
        keyValue[m_idTally].setValue(newValue);
        keyValue[m_idTally].setId(m_idTally);
        m_idTally++;
    }else{
        resize();
        keyValue[m_idTally].setKey(newKey);
        keyValue[m_idTally].setValue(newValue);
        keyValue[m_idTally].setId(m_idTally);
        m_idTally++;
    }
}

void Dictionary::removeById(int id) {
    try {
        if (id >= m_idTally || id < 0) {
            throw "No such id";
        }
        KeyValue *temp = new KeyValue[m_Size - 1];
        for (int x = 0; x < m_Size - 1; x++) {
            if (x < id) {
                temp[x] = keyValue[x];
            } else if (x >= id) {
                temp[x] = keyValue[x + 1];
            }
        }
        delete[]keyValue;
        keyValue = temp;
        temp = nullptr;
        m_idTally--;
        update();
    }catch (std::string e){
        std::cout << e << std::endl;
    }
}

template <typename T, typename S>
void Dictionary::removeByKey(T Key){

}

template <typename T, typename S>
KeyValue Dictionary::getByKey(T key){
    for(int x = 0; x < m_idTally; x++){
        if (keyValue[x].getKey() == key){
            return keyValue[x];
        }
    }
    throw "No such key exists";
}

KeyValue Dictionary::getById(int id) {
    if(id < m_idTally) {
        return keyValue[id];
    }
    throw "No such keyValue exists";
}