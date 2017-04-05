//
// Created by telepatheticman on 4/4/2017.
//

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
    void setKey(T newKey){m_Key = newKey;};
    void setValue(S newValue){m_Value = newValue;};
    void setId(int newId){m_Id = newId;};
protected:

};


#endif //HM6_KEYVALUE_H
