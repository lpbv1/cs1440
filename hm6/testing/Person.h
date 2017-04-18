//
// Created by telepatheticman on 4/14/17.
//

#ifndef HM6_PERSON_H
#define HM6_PERSON_H

#include <string>

class Person {
private:
    std::string m_name;
    int m_age;
public:
    Person(std::string name, int age);
    std::string getName(){return m_name;}
    int getAge(){return m_age;}
    void setName(std::string newName){m_name = newName;}
    void setAge(int newAge){m_age = newAge;}
    bool operator==(Person& rhs);
};


#endif //HM6_PERSON_H
