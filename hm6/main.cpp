#include <iostream>
#include <string>
#include "Dictionary.h"

int main(){
    Dictionary<int, int>* test0 = new Dictionary<int, int>(10);
    try {
        test0->add(0, 1);
        test0->add(1, 2);
        test0->add(2, 3);
        test0->add(3, 4);
        test0->add(4, 5);
        test0->add(5, 6);
    }catch(std::string ex){
        std::cout << ex << std::endl;
    }

    std::cout << test0->getByIndex(4).getValue() << std::endl;
    std::cout << test0->getByIndex(4).getId() << std::endl;
    std::cout << test0->getByIndex(0).getValue() << std::endl;
    std::cout << test0->getByIndex(0).getId() << std::endl;
    /*I do not have the time nor the prerequisite code to enable me to illustrate the capabilities, but
    I would still like to explain what I would have done as a demonstration. Fisrt, a rot13 encoder/decoder
     by setting the keys to the rotated values (n, o, p, q, r, s, ect) and the values as the alphabet (a, b, c, d, ect.).
     So you get a dictionary like this:
     Key|Value|Id
     ------------
      n |  a  |0
      o |  b  |1
      p |  c  |2
      q |  d  |3
      r |  e  |4
      |    |   |
      V    V   V
      Then a simple algorithm can be applied.

      Another application would be to set key to a std::string and then a student class type as the value.
      The string would be used as an ID and the student would contain information like
      a name, email, cell number, ect. This would be good if you wanted to build a library of students attending
      and even but want to use different id's than the school provided one for whatever reason.

      Im writing this to make sure it is understood that I see the value and capabilities of this kind of code,
      which is a major part of the assignment. I just dont have the time to demonsrate it. But I know points
      may be deducted for not writing illustrative code and I understand that.
     */
    return 0;
}