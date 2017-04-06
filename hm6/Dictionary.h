
#ifndef HM6_DICTIONARY_H
#define HM6_DICTIONARY_H

#include "KeyValue.h"
#include <string>
#include <iostream>

template <typename T, typename S>
class Dictionary {
private:
    int m_Size;
    KeyValue<T, S>* keyValue;
    int m_idTally;
    void resize();
    void update();
public:
    Dictionary();
    Dictionary(int size);
    ~Dictionary();
    Dictionary(Dictionary &obj);
    void add(T newKey, S newValue);
    void removeById(int id);
    void removeByKey(T Key);
    KeyValue<T, S> getById(int id);
    KeyValue<T, S>& operator[](int id) const;
    KeyValue<T, S>& getByKey(T key);
    int getCount(){return m_idTally;};
};

template<typename T, typename S>
Dictionary<T, S>::Dictionary() {
    m_idTally = 0;
    m_Size = 10;
    keyValue = new KeyValue<T, S>[m_Size];
}

template<typename T, typename S>
Dictionary<T, S>::Dictionary(int size){
    m_idTally = 0;
    m_Size = size;
    keyValue = new KeyValue<T, S>[m_Size];
}

template<typename T, typename S>
Dictionary<T, S>::~Dictionary(){
    keyValue = nullptr;
    delete[]keyValue;
}

template<typename T, typename S>
Dictionary<T, S>::Dictionary(Dictionary &obj){

}

template<typename T, typename S>
void Dictionary<T, S>::resize() {
    m_Size++;
    KeyValue<T, S>* temp = new KeyValue<T, S>[m_Size];
    for (int x = 0; x < m_Size - 1; x++){
        temp[x] = keyValue[x];
    }
    delete[]keyValue;
    keyValue = temp;
    temp = nullptr;
}

template<typename T, typename S>
void Dictionary<T, S>::update() {
    for (int x = 0; x < m_idTally; x++){
        keyValue[x].setId(x);
    }
}

template<typename T, typename S>
KeyValue<T, S>& Dictionary<T, S>::operator[](int id) const {
    if(id < m_idTally) {
        return keyValue[id];
    }else{
        std::string ex = "id out of range";
        throw ex;
    }
}
template <typename T, typename S>
void Dictionary<T, S>::add(T newKey, S newValue){
/*    std::string check = "";
    try {
        KeyValue<T, S> temp = getByKey(newKey);
    }catch(std::string ex){
        check = ex;
    }*/
//    if(check == "No such key exists") {
        if (m_idTally < m_Size) {
            keyValue[m_idTally].setKey(newKey);
            keyValue[m_idTally].setValue(newValue);
            keyValue[m_idTally].setId(m_idTally);
            m_idTally++;
        } else {
            resize();
            keyValue[m_idTally].setKey(newKey);
            keyValue[m_idTally].setValue(newValue);
            keyValue[m_idTally].setId(m_idTally);
            m_idTally++;
        }
    /*}else{
        std::string ex = "Duplicate key";
        throw ex;
    }*/
}

template<typename T, typename S>
void Dictionary<T, S>::removeById(int id) {
    if (id >= m_idTally || id < 0) {
        std::string ex = "No such id";
        throw ex;
    }
    KeyValue<T, S>* temp = new KeyValue<T, S>[m_Size - 1];
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
}

template <typename T, typename S>
void Dictionary<T, S>::removeByKey(T Key){
    KeyValue<T, S> temp;
    try {
        temp = getByKey(Key);
    }catch(std::string ex){
        throw ex;
    }
    try {
        removeById(temp.getId());
    }catch(std::string ex){
        throw ex;
    }
}

template <typename T, typename S>
KeyValue<T, S>& Dictionary<T, S>::getByKey(T key){
    for (int x = 0; x < m_idTally; x++) {
        if (keyValue[x].getKey() == key) {
            return keyValue[x];
        }
    }
    std::string ex = "No such key exists";
    throw ex;
}

template<typename T, typename S>
KeyValue<T, S> Dictionary<T, S>::getById(int id) {
    if (id < m_idTally) {
        return keyValue[id];
    }
    std::string ex = "id out of range";
    throw ex;
}

#endif //HM6_DICTIONARY_H
