//
// Created by fracher on 2021/6/5.
//

#ifndef MAKEENGINE_DEBUG_H
#define MAKEENGINE_DEBUG_H

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

#endif //MAKEENGINE_DEBUG_H
