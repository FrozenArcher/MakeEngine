//
// Created by fracher on 2021/6/6.
//

#ifndef MAKEENGINE_MEWINDOW_H
#define MAKEENGINE_MEWINDOW_H

extern "C" {
#include <SDL2/SDL.h>
}

namespace MakeEngine {
    class MEWindow {
    public:
        bool Init();
        bool Run();
        bool Dispose();

    protected:
        SDL_Window *_pWindow;
        SDL_Event _event;
    };
}

#endif //MAKEENGINE_MEWINDOW_H
