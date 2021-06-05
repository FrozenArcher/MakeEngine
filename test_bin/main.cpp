//
// Created by fracher on 2021/6/5.
//

#include "MakeEngine.h"
using namespace MakeEngine;

int main() {
    DBG_Log("Hello from test_bin!");

    auto* pDelegate = new MEDelegate("YHY");
    pDelegate->Hello();
    delete pDelegate;
}
