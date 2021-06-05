//
// Created by fracher on 2021/6/5.
//

#include "MakeEngine.h"
using namespace MakeEngine;

#ifdef _DEBUG
class A{
public:
    A() = default;
    ~A() = default;
    int Add(int a, int b) {
        return a + b;
    }
};
int Add(int a, int b) {
    return a + b;
}
MEString Add5S(MEString s1, MEString s2, MEString s3, MEString s4, MEString s5) {
    return s1 + s2 + s3 + s4 + s5;
}
void tests() {
    DBG_Log("Hello from test_bin!");

    A a;
    auto d = MEDelegate<int, int, int>::FromMethod<A, &A::Add>(&a);
    DBG_AssertEq("Test MEDelegate1", d.Execute(2, 3), 5);

    d = MEDelegate<int, int, int>::FromFunc<&Add>();
    DBG_AssertEq("Test MEDelegate2", d.Execute(2, 3), 5);

    typedef MEString Str;
    auto e = MEDelegate<Str, Str, Str, Str, Str, Str>::FromFunc<&Add5S>();
    DBG_AssertEq("Test MEDelegate3",
                 e.Execute("aa", "bb", "cc", "dd", "ee"),
                 "aabbccddee");
}
#endif // _DEBUG


#pragma clang diagnostic push    // cancel unused warning for argc, argv
#pragma ide diagnostic ignored "UnusedParameter"
int main(int argc, char* argv[]) {
#ifdef _DEBUG
    tests();
#endif
    MEWindow window{};
    if (!window.Init()) {
        return 1;
    }
    if (!window.Run()) {
        return 1;
    }
    if (!window.Dispose()) {
        return 1;
    }
    return 0;
}
#pragma clang diagnostic pop
