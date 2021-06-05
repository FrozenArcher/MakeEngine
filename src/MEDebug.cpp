//
// Created by fracher on 2021/6/5.
//

#include "METime.h"
#include "MEBaseTypes.h"
#include <iostream>
using std::cout, std::endl;
namespace MakeEngine {
    void Log(const MEString& message) {
        cout << "[Log] " << GetTimeNowStr() << message << endl << endl;
    }
    void LogTest(const MEString& name, bool result) {
        cout << "[Test] " << GetTimeNowStr() << "Running test: " << name
             << "\nresult: " << (result ? "passed" : "failed")
             << endl << endl;
    }
}
