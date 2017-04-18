#include <iostream>
#include <string>
#include "Dictionary.h"

int main(){
    Dictionary<char, char>* rot13 = new Dictionary<char, char>(10);
    for(int x = 0; x < 26; x++){
        if(x < 13){
            rot13->add('a' + x, 'a' + x + 13);
        }
        if(x >= 13){
            rot13->add('a' + x, 'a' + x - 13);
        }
    }
    std::string key = "hello. This is a test string that is being displayed on the console.\nBelow this will be the encrypted version using rot13";
    std::string ecq;
    for(int x = 0; x < key.length(); x++){
        if(std::tolower(key[x]) >= 'a' && std::tolower(key[x]) <= 'z'){
            ecq += rot13->getByKey(std::tolower(key[x])).getValue();
        }
        else{
            ecq += key[x];
        }
    }

    std::cout << key << std::endl << std::endl << ecq << std::endl;

    return 0;
}