//
// Created by fracher on 2021/6/6.
//

#include "MEWindow.h"
#include "MEDebug.h"

namespace MakeEngine {
    bool MEWindow::Run() {
        while (true) {
            if (SDL_PollEvent(&_event)) {
                if (_event.type == SDL_QUIT) {
                    DBG_Log("Window quited.");
                    break;
                }
            }
        }
        return true;
    }

    bool MEWindow::Init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            DBG_Log(SDL_GetError());
            return false;
        }

        if (!InitWindow()) {
            return false;
        }

        return true;
    }

    bool MEWindow::Dispose() {
        SDL_DestroyWindow(_pWindow);
        SDL_Quit();
        return true;
    }

    bool MEWindow::InitWindow() {
        _pWindow = SDL_CreateWindow("Demo",
             SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             800, 600, SDL_WINDOW_SHOWN);
        if (_pWindow == nullptr) {
            DBG_Log(SDL_GetError());
            return false;
        }
        return true;
    }

    bool MEWindow::InitGraphics() {
        _pRenderer = SDL_CreateRenderer(_pWindow, -1,
             SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        return true;
    }
}


