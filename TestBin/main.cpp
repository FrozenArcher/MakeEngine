#include <iostream>
#include <string>

#include "library.h"
#include "debug.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    hello();
//#ifdef _DEBUG
//    printf("debug");
//#endif
    DBG_Log("debug");
    return 0;
}
