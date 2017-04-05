

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
    KeyValue(T Key, S Value, int Id);
    KeyValue(const KeyValue &obj);
    T getKey(){return m_Key;};
    S getValue(){return m_Value;};
    int getId(){return m_Id;};
    void setKey(T newKey) const{m_Key = newKey;};
    void setValue(S newValue) const{m_Value = newValue;};
    void setId(int newId) const {const m_Id = newId;};

};


#endif //HM6_KEYVALUE_H
