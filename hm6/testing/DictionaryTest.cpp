
#include "DictionaryTest.h"

void DictionaryTest::constructorTest() {
    std::cout << "DictionaryTest::constructorTest" << std::endl;
    Dictionary<int, int>* test0 = new Dictionary<int, int>(10);
    if(test0->getCount() != 0){
        std::cout << "DictionaryConstructorTest0 failed: wrong count" << std::endl;
    }
    if(test0->getSize() != 10){
        std::cout << "DictionaryConstructorTest0 failed: wrong size" << std::endl;
    }

    Dictionary<int, std::string>* test1 = new Dictionary<int, std::string>(100);
    if(test1->getCount() != 0){
        std::cout << "DictionaryConstructorTest1 failed: wrong count" << std::endl;
    }
    if(test1->getSize() != 100){
        std::cout << "DictionaryConstructorTest1 failed: wrong size" << std::endl;
    }

    Dictionary<int, Person*>* test2 = new Dictionary<int, Person*>(2);
    if(test2->getCount() != 0){
        std::cout << "DictionaryConstructorTest2 failed: wrong count" << std::endl;
    }
    if(test2->getSize() != 2){
        std::cout << "DictionaryConstructorTest2 failed: wrong size" << std::endl;
    }

    Dictionary<int, Person*>* test3 = new Dictionary<int, Person*>(*test2);
    if(test3->getCount() != 0){
        std::cout << "DictionaryConstructorTest3 failed: wrong count" << std::endl;
    }
    if(test3->getSize() != 2){
        std::cout << "DictionaryConstructorTest3 failed: wrong size" << std::endl;
    }

    for(int x = 0; x < 20; x++){
        test0->add(x, x+1);
    }

    if(test0->getCount() != 20){
        std::cout << "DictionaryConstructorTest0 pt2 failed" << std::endl;
    }

    int temp = test0->getByKey(5).getValue();
    if(temp != 6){
        std::cout << "DictionaryConstructorTest0 pt3 failed... got: " << temp << std::endl;
    }

    bool passed = false;
    try{
        test0->add(3, 50);
    }catch(std::string ex){
        passed = true;
    }

    if(!passed){
        std::cout << "add exception failed" << std::endl;
    }

    try{
        test0->removeByIndex(8);
    }catch(std::string ex){
        std::cout << "test0 pt5 failed" << std::endl;
    }
}

void DictionaryTest::functionTest(){
    std::cout << "DictionaryTest::functionTest" << std::endl;
    Dictionary<int, int>* test0 = new Dictionary<int, int>(10);
    Dictionary<int, std::string>* test1 = new Dictionary<int, std::string>(10);
    Dictionary<int, Person*>* test2 = new Dictionary<int, Person*>(10);

    std::string addStr = "a";
    for(int x = 0; x < 15; x++){

        test0->add(x, x+1);
        test1->add(x, addStr);
        test2->add(x, new Person(addStr, x + 15));
        char add = 'a' + x + 1;
        addStr += add;
    }
    std::cout << "Test0" << std::endl;
    //test0 tests
    if (test0->getByIndex(3).getValue() != 4 && test0->getByKey(3).getKey() != 3){
        std::cout << "Get test 1 failed" << std::endl;
    }
    if(test0->getByIndex(14).getValue() != 15 && test0->getByKey(14).getKey() != 14){
        std::cout << "Get test 2 failed" << std::endl;
    }
    if((*test0)[3].getValue() != 4 && (*test0)[3].getKey() != 3){
        std::cout << "Get[] test 1 failed" << std::endl;
    }
    if((*test0)[13].getValue() != 14 && (*test0)[13].getKey() != 13){
        std::cout << "Get[] test 1 failed" << std::endl;
    }
    if (!test0->Found(6)){
        std::cout << "found function failed" << std::endl;
    }
    test0->removeByIndex(5);
    if((*test0)[6].getValue() != 8 && (*test0)[5].getKey() != 7){
        std::cout << "remove index failed" << std::endl;
    }
    test0->removeByKey(10);
    if((*test0)[9].getValue() != 12 && (*test0)[9].getKey() != 11){
        std::cout << "remove key failed" << std::endl;
    }

    //test1 tests
    std::cout << "test1" << std::endl;
    if (test1->getByIndex(3).getValue() != "abc" && test1->getByKey(3).getKey() != 3){
        std::cout << "Get test 1 failed" << std::endl;
    }
    if(test1->getByIndex(14).getValue() != "abcdefghijklmno" && test1->getByKey(14).getKey() != 14){
        std::cout << "Get test 2 failed" << std::endl;
    }
    if((*test1)[3].getValue() != "abc" && (*test1)[3].getKey() != 3){
        std::cout << "Get[] test 1 failed" << std::endl;
    }
    if((*test1)[13].getValue() != "abcdefghigklmn" && (*test1)[13].getKey() != 13){
        std::cout << "Get[] test 1 failed" << std::endl;
    }
    if (!test1->Found(6)){
        std::cout << "found function failed" << std::endl;
    }
    test1->removeByIndex(5);
    if((*test1)[6].getValue() != "abcdef" && (*test1)[6].getKey() != 7){
        std::cout << "remove index failed" << std::endl;
    }
    test1->removeByKey(10);
    if((*test1)[9].getValue() != "abcdefghijkl" && (*test1)[9].getKey() != 11){
        std::cout << "remove key failed" << std::endl;
    }

    std::cout << "test2" << std::endl;
    if (test2->getByIndex(3).getValue()->getName() != "abc" && test2->getByKey(3).getKey() != 3
        && test2->getByIndex(3).getValue()->getAge() != 18){
        std::cout << "Get test 1 failed" << std::endl;
    }
    if(test2->getByIndex(14).getValue()->getName() != "abcdefghijklmno" && test2->getByKey(14).getKey() != 14
       && test2->getByIndex(3).getValue()->getAge() != 29){
        std::cout << "Get test 2 failed" << std::endl;
    }
    if((*test2)[3].getValue()->getName() != "abc" && (*test2)[3].getKey() != 3
       && (*test2)[3].getValue()->getAge() != 18){
        std::cout << "Get[] test 1 failed" << std::endl;
    }
    if((*test2)[13].getValue()->getName() != "abcdefghigklmn" && (*test2)[13].getKey() != 13
       && (*test2)[13].getValue()->getAge() != 28){
        std::cout << "Get[] test 1 failed" << std::endl;
    }
    if (!test2->Found(6)){
        std::cout << "found function failed" << std::endl;
    }
    test2->removeByIndex(5);
    if((*test2)[6].getValue()->getName() != "abcdef" && (*test2)[6].getKey() != 7
       && (*test2)[6].getValue()->getAge() != 22){
        std::cout << "remove index failed" << std::endl;
    }
    test2->removeByKey(10);
    if((*test2)[9].getValue()->getName() != "abcdefghijkl" && (*test2)[9].getKey() != 11
       && (*test2)[9].getValue()->getAge() != 26){
        std::cout << "remove key failed" << std::endl;
    }

}

void DictionaryTest::exceptionTest(){
    std::cout << "DictionaryTest::exceptionTest" << std::endl;

    Dictionary<int, int>* test0 = new Dictionary<int, int>(10);

    for(int x = 0; x < 20; x++){
        test0->add(x, x+1);
    }

    int exceptionCount = 0;

    try{
        test0->add(3, 4);
    }catch(std::string ex){
        exceptionCount++;
    }
    try{
        test0->removeByIndex(30);
    }catch(std::string ex){
        exceptionCount++;
    }
    try{
        test0->removeByIndex(-2);
    }catch(std::string ex){
        exceptionCount++;
    }
    try{
        test0->removeByKey(30);
    }catch(std::string ex){
        exceptionCount++;
    }
    try{
        test0->removeByKey(-2);
    }catch(std::string ex){
        exceptionCount++;
    }
    try{
        test0->getByKey(30);
    }catch(std::string ex){
        exceptionCount++;
    }
    try{
        test0->getByKey(-2);
    }catch(std::string ex){
        exceptionCount++;
    }
    try{
        (*test0)[30];
    }catch(std::string ex){
        exceptionCount++;
    }
    try{
        (*test0)[-2];
    }catch(std::string ex){
        exceptionCount++;
    }
    try{
        (*test0)[5];
    }catch(std::string ex){
        exceptionCount++;
    }

    if(exceptionCount > 9){
        std::cout << "too many exceptions caught" << std::endl;
    }
    if(exceptionCount < 9){
        std::cout << "too few exceptions caught" << std::endl;
    }

}
