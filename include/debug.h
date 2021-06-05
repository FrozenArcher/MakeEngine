//
// Created by fracher on 2021/6/5.
//

#include <cstdio>
#include "MakeEngine.h"

#ifndef MAKEENGINE_DEBUG_H
#define MAKEENGINE_DEBUG_H

#ifdef ME_DEBUG_MODE
#define _DEBUG
#endif
#ifdef _DEBUG
#define DBG_Log(message) printf("[Log] Time: %s" message,\
    MakeEngine::GetTimeNowStr().c_str())
#else
#define DBG_Log(message)
#endif

#endif //MAKEENGINE_DEBUG_H
