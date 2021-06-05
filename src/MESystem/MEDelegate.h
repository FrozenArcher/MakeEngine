//
// Created by fracher on 2021/6/5.
//

#include "../MEBaseTypes.h"

#ifndef MAKEENGINE_MEDELEGATE_H
#define MAKEENGINE_MEDELEGATE_H

namespace MakeEngine {
    class MEDelegate {
    public:
        explicit MEDelegate(MEString);
        void Hello();

    private:
        MEString _name;
    };
}


#endif //MAKEENGINE_MEDELEGATE_H
