

#ifndef HM6_KEYVALUE_H
#define HM6_KEYVALUE_H

template <typename T, typename S>
class KeyValue {
private:
    T* m_Key;
    S* m_Value;
    int* m_Id;
public:
    KeyValue();
    KeyValue(T Key, S Value, int Id);
    KeyValue(const KeyValue &obj);
    T getKey();
    S getValue();
    int getId();
    void setKey(T newKey) const;
    void setValue(S newValue) const;
    void setId(int newId) const;

};

template <typename T, typename S>
KeyValue<T, S>::KeyValue() {

}

template <typename T, typename S>
KeyValue<T, S>::KeyValue(T Key, S Value, int Id) {
    *m_Key = Key;
    *m_Value = Value;
    *m_Id = Id;
}

template <typename T, typename S>
KeyValue<T, S>::KeyValue(const KeyValue &obj) {
    obj.setKey(m_Key);
    obj.setValue(m_Value);
    obj.setId(m_Id);
}

template <typename T, typename S>
T KeyValue<T, S>::getKey(){
    return *m_Key;
}

template <typename T, typename S>
S KeyValue<T, S>::getValue(){
    return *m_Value;
}

template <typename T, typename S>
int KeyValue<T, S>::getId(){
    return *m_Id;
}

template <typename T, typename S>
void KeyValue<T, S>::setKey(T newKey) const{
    *m_Key = newKey;
}

template <typename T, typename S>
void KeyValue<T, S>::setValue(S newValue) const{
    *m_Value = newValue;
}

template <typename T, typename S>
void KeyValue<T, S>::setId(int newId) const{
    m_Id = &newId;
}


#endif //HM6_KEYVALUE_H
