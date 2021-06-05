//
// Created by fracher on 2021/6/5.
//

#include "MEDelegate.h"
#include "MEDebug.h"

namespace MakeEngine {
    MEDelegate::MEDelegate(MEString name) {
        _name = std::move(name);
    }
    void MEDelegate::Hello() {
        Log(_name);
    }
}
