
#include "KeyValueTest.h"

void KeyValueTest::testConstructors() {
    KeyValue<int, int> test0(0, 3, 0);
    KeyValue<int, std::string> test1(3, "hello", 5);
    KeyValue<char, bool> test2('g', true, 8);

    if(test0.getKey() == 0 && test0.getValue() == 3 && test0.getId() == 0){
        std::cout << "KeyValueTest0 passed" << std::endl;
    }else{
        std::cout << "KeyValueTest0 failed" << std::endl;
    }

    if(test1.getKey() == 3 && test1.getValue() == "hello" && test1.getId() == 5){
        std::cout << "KeyValueTest1 passed" << std::endl;
    }else{
        std::cout << "KeyValueTest1 failed" << std::endl;
    }

    if(test2.getKey() == 'g' && test2.getValue() && test2.getId() == 8){
        std::cout << "KeyValueTest2 passed" << std::endl;
    }else{
        std::cout << "KeyValueTest2 failed" << std::endl;
    }
    // causing compile errors. Skipping for now.
    // not when const though
    test2.setKey('T');
    test2.setValue(false);
    test2.setId(9);

    if(test2.getKey() == 'T' && !test2.getValue() && test2.getId() == 9){
        std::cout << "KeyValueTest2 passed" << std::endl;
    }else{
        std::cout << "KeyValueTest2 failed" << std::endl;
    }
}