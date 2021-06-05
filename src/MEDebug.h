//
// Created by fracher on 2021/6/5.
//

#ifndef MAKEENGINE_MEDEBUG_H
#define MAKEENGINE_MEDEBUG_H

#ifdef ME_DEBUG_MODE
#define _DEBUG
#endif

namespace MakeEngine {
    void Log(const MEString&);
}

#ifdef _DEBUG
#define DBG_Log(message) MakeEngine::Log(message)
#else
#define DBG_Log(message)
#endif

#endif //MAKEENGINE_MEDEBUG_H
