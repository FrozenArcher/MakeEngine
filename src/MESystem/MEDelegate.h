//
// Created by fracher on 2021/6/5.
//

#include "MEBaseTypes.h"
#include <cstdio>

#ifndef MAKEENGINE_MEDELEGATE_H
#define MAKEENGINE_MEDELEGATE_H

namespace MakeEngine {
    template<typename TResult, typename... TArgs>
    class MEDelegate {
    public:
        MEDelegate() {
            _p = nullptr;
            _f = nullptr;
        }
        ~MEDelegate() = default;

    protected:
        typedef TResult(*FNew)(void *, TArgs...);

        template<TResult(*Fn)(TArgs...)>
        static TResult
        FunStub([[maybe_unused]] void * p, TArgs ...args) {
            return (Fn)(args...);
        }

        template<class C, TResult(C::*Cf)(TArgs...)>
        static TResult MethodStub(void * p, TArgs ...args) {
            C* ap = (C *)p;
            return (ap->*Cf)(args...);
        }

        static MEDelegate Create(void * p, FNew f) {
            MEDelegate temp{};
            temp._f = f;
            temp._p = p;
            return temp;
        }

    public:
        template<class C, TResult(C::*Cf)(TArgs...)>
        static MEDelegate FromMethod(C * p) {
            return Create(p, &MethodStub<C, Cf>);
        }

        template<TResult(*Fn)(TArgs...)>
        static MEDelegate FromFunc() {
            return Create(nullptr, &FunStub<Fn>);
        }

        TResult Execute(TArgs ...args) {
            return (*_f) (_p, args...);
        }

    protected:
        void * _p;
        FNew _f;
    };
}
#endif //MAKEENGINE_MEDELEGATE_H
