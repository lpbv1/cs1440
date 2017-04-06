
#include "DictionaryTest.h"

void DictionaryTest::constructorTest() {
    Dictionary<int, int>* test0 = new Dictionary<int, int>(10);
    if(test0->getCount() == 0){
        std::cout << "DictionaryConstructorTest0 pt1 passed" << std::endl;
    }else{
        std::cout << "DictionaryConstructorTest0 pt1 failed" << std::endl;
    }

    for(int x = 0; x < 20; x++){
        test0->add(x, x+1);
    }

    if(test0->getCount() == 20){
        std::cout << "DictionaryConstructorTest0 pt2 passed" << std::endl;
    }else{
        std::cout << "DictionaryConstructorTest0 pt2 failed" << std::endl;
    }

    int temp = test0->getByKey(5).getValue();
    if(temp == 6){
        std::cout << "DictionaryConstructorTest0 pt3 passed" << std::endl;
    }else{
        std::cout << "DictionaryConstructorTest0 pt3 failed... got: " << temp << std::endl;
    }

    std::cout << "If no duplicate key message appears, test0 pt4 failed" << std::endl;
    try{
        test0->add(3, 50);
    }catch(std::string ex){
        std::cout << ex << ": test0 pt4 passed" << std::endl;
    }

    try{
        test0->removeById(8);
    }catch(std::string ex){
        std::cout << "test0 pt5 failed" << std::endl;
    }
}
