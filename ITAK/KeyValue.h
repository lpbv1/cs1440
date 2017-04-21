

#ifndef HM6_KEYVALUE_H
#define HM6_KEYVALUE_H

template <typename T, typename S>
class KeyValue {
private:
    T m_Key;
    S m_Value;
    int m_Id;
public:
    KeyValue();
    KeyValue(const T& Key, const S& Value, int Id);
    const T& getKey() const;
    const S& getValue() const;
    int getId() const;
    void setKey(const T& newKey);
    const void setValue(const S& newValue) const;
    void setId(int newId);

};

template <typename T, typename S>
KeyValue<T, S>::KeyValue() {

}

template <typename T, typename S>
KeyValue<T, S>::KeyValue(const T& Key, const S& Value, int Id) {
    m_Key = Key;
    m_Value = Value;
    m_Id = Id;
}

template <typename T, typename S>
const T& KeyValue<T, S>::getKey() const{
    return m_Key;
}

template <typename T, typename S>
const S& KeyValue<T, S>::getValue() const{
    return m_Value;
}

template <typename T, typename S>
int KeyValue<T, S>::getId() const{
    return m_Id;
}

template <typename T, typename S>
void KeyValue<T, S>::setKey(const T& newKey) {
    m_Key = newKey;
}

template <typename T, typename S>
const void KeyValue<T, S>::setValue(const S& newValue) const {
    m_Value = newValue;
}

template <typename T, typename S>
void KeyValue<T, S>::setId(int newId) {
    m_Id = newId;
}


#endif //HM6_KEYVALUE_H
