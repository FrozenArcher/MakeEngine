//
// Created by fracher on 2021/6/5.
//
#include <ctime>

#include "METime.h"

MEString MakeEngine::GetTimeNowStr() {
    static time_t _theTime;

    time(&_theTime);
    return ctime(&_theTime);
}
