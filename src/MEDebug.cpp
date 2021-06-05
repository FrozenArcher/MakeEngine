//
// Created by fracher on 2021/6/5.
//

#include "METime.h"
#include <iostream>
using std::cout, std::endl;
namespace MakeEngine {
    void Log(const MEString& message) {
        cout << "[Log] " << GetTimeNowStr() << message << endl;
    }
}
