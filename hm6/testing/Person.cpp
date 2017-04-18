//
// Created by telepatheticman on 4/14/17.
//

#include "Person.h"

Person::Person(std::string name, int age){
    m_name = name;
    m_age = age;
}

bool Person::operator==(Person &rhs) {
    return (m_name == rhs.m_name && m_age == rhs.m_age);
}
