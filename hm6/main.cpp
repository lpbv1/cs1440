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

    std::cout << test0->getById(4).getKey() << std::endl;
    return 0;
}