//
// Created by fracher on 2021/6/5.
//

#include <cstdio>

#ifndef MAKEENGINE_MEDEBUG_H
#define MAKEENGINE_MEDEBUG_H

#ifdef ME_DEBUG_MODE
#define _DEBUG
#endif

#include "MEBaseTypes.h"

namespace MakeEngine {
    void Log(const MEString&);
    void LogTest(const MEString&, bool);
}

#ifdef _DEBUG
#define DBG_Log(message) MakeEngine::Log((message))
#define DBG_AssertEq(name, val1, val2) LogTest((name), (val1) == (val2))
#else
#define DBG_Log(message)
#define DBG_AssertEq(name, val1, val2)
#endif

#endif //MAKEENGINE_MEDEBUG_H
