
#include "KeyValue.h"

KeyValue::KeyValue() {

}

template <typename T, typename S>
KeyValue::KeyValue(T Key, S Value, int Id) {
    m_Key = Key;
    m_Value = Value;
    m_Id = Id;
}

KeyValue::KeyValue(const KeyValue &obj) {
    obj.setKey(m_Key);
    obj.setValue(m_Value);
    obj.setId(m_Id);
}
