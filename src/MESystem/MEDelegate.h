//
// Created by fracher on 2021/6/5.
//

#include "MEBaseTypes.h"
#include <cstdio>

#ifndef MAKEENGINE_MEDELEGATE_H
#define MAKEENGINE_MEDELEGATE_H

namespace MakeEngine {
    template<typename TResult, typename PR1, typename PR2>
    class MEDelegate {
    public:
        MEDelegate() {
            _p = nullptr;
            _f = nullptr;
        }
        ~MEDelegate() = default;

    protected:
        typedef TResult(*FNew)(void *, PR1, PR2);

        template<TResult(*Fn)(PR1, PR2)>
        static TResult
        FunStub([[maybe_unused]] void * p, PR1 a1, PR2 a2) {
            return (Fn)(a1, a2);
        }

        template<class C, TResult(C::*Cf)(PR1, PR2)>
        static TResult MethodStub(void * p, PR1 a1, PR2 a2) {
            C* ap = (C *)p;
            return (ap->*Cf)(a1, a2);
        }

        static MEDelegate Create(void * p, FNew f) {
            MEDelegate temp{};
            temp._f = f;
            temp._p = p;
            return temp;
        }

    public:
        template<class C, TResult(C::*Cf)(PR1, PR2)>
        static MEDelegate FromMethod(C * p) {
            return Create(p, &MethodStub<C, Cf>);
        }

        template<TResult(*Fn)(PR1, PR2)>
        static MEDelegate FromFunc() {
            return Create(nullptr, &FunStub<Fn>);
        }

        TResult Execute(PR1 a1, PR2 a2) {
            return (*_f) (_p, a1, a2);
        }

    protected:
        void * _p;
        FNew _f;
    };
}


#endif //MAKEENGINE_MEDELEGATE_H
