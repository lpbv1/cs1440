#include "DictionaryTest.h"
#include "KeyValueTest.h"

int main(){

    DictionaryTest* testDiction = new DictionaryTest();
    KeyValueTest* testKey = new KeyValueTest();
    testKey->testConstructors();
    testDiction->constructorTest();
    testDiction->functionTest();
    testDiction->exceptionTest();

    return 0;
}