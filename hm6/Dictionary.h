
#ifndef HM6_DICTIONARY_H
#define HM6_DICTIONARY_H

#include "KeyValue.h"
#include <string>
#include <iostream>

template <typename T, typename S>
class Dictionary {
private:
    int m_size;
    KeyValue<T, S>** keyValues;
    int m_nextId = 0;
    int m_count = 0;
    void resize();
public:
    Dictionary();
    Dictionary(int size);
    ~Dictionary();
    Dictionary(const Dictionary& original);
    bool Found(T newKey);
    void add(T newKey, S newValue);
    int find(const T& key);
    void removeByIndex(int index);
    void removeByKey(const T& Key);
    const KeyValue<T, S>& getByIndex(int index) const;
    const KeyValue<T, S>& operator[](int index);
    const KeyValue<T, S>& getByKey(const T& key);
    int getCount(){return m_count;};
    int getSize(){return m_size;};
};

template<typename T, typename S>
Dictionary<T, S>::Dictionary() {
    m_size = 10;
    keyValues = new KeyValue<T, S>*[m_size];
}

template<typename T, typename S>
Dictionary<T, S>::Dictionary(int size){
    m_size = size;
    keyValues = new KeyValue<T, S>*[m_size];
}

template<typename T, typename S>
Dictionary<T, S>::~Dictionary(){
    for (int x = 0; x < m_count; x++){
        delete keyValues[x];
    }
    delete[]keyValues;
    keyValues = nullptr;
}

template<typename T, typename S>
Dictionary<T, S>::Dictionary(const Dictionary& original){
    keyValues = new KeyValue<T, S>*[original.m_size];
    m_size = original.m_size;
    for (int x = 0; x < m_size - 1; x++){
        keyValues[x] = original.keyValues[x];
    }

}

template<typename T, typename S>
void Dictionary<T, S>::resize() {
    if(m_count == m_size){
        m_size++;
    }else{
        m_size+=m_count + 1;
    }
    KeyValue<T, S>** temp = new KeyValue<T, S>*[m_size];
    for (int x = 0; x < m_count; x++){
        temp[x] = keyValues[x];
    }
    delete[]keyValues;
    keyValues = temp;
}


template<typename T, typename S>
const KeyValue<T, S>& Dictionary<T, S>::operator[](int index) {
    return getByIndex(index);
}

template <typename T, typename S>
bool Dictionary<T, S>::Found(T newKey) {
    bool isFound = false;
    try {
        const KeyValue<T, S> &temp = getByKey(newKey);
        isFound = true;
    } catch (std::string ex) {

    }
    return isFound;
}

template <typename T, typename S>
void Dictionary<T, S>::add(T newKey, S newValue){
    if(!Found(newKey)) {
        if (m_count >= m_size) {
            resize();
        }
        keyValues[m_count++] = new KeyValue<T, S>(newKey, newValue, m_nextId++);
    }else{
        std::string ex = "Duplicate key";
        throw ex;
    }
}

template<typename T, typename S>
void Dictionary<T, S>::removeByIndex(int index) {
    if (index >= m_count || index < 0) {
        std::string ex = "Index out of range";
        throw ex;
    }
    delete keyValues[index];
    for (int x = index; x < m_count - 1; x++) {
         keyValues[x] = keyValues[x + 1];
    }
    m_count--;
}

template <typename T, typename S>
void Dictionary<T, S>::removeByKey(const T& key){
    int index = find(key);
    removeByIndex(index);
}

template <typename T, typename S>
int Dictionary<T, S>::find(const T& key){
    for (int x = 0; x < m_count; x++) {
        if (keyValues[x]->getKey() == key) {
            return x;
        }
    }
    std::string ex = "No such key exists";
    throw ex;
}

template <typename T, typename S>
const KeyValue<T, S>& Dictionary<T, S>::getByKey(const T& key){
    int index = find(key);
    return getByIndex(index);
}

template<typename T, typename S>
const KeyValue<T, S>& Dictionary<T, S>::getByIndex(int index) const {
    if (index >= 0 && index < m_count) {
        return *keyValues[index];
    }
    std::string ex = "Index out of range";
    throw ex;
}

#endif //HM6_DICTIONARY_H
