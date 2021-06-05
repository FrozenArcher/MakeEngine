set(ME_INC ../include)

set(LIB_SRC_DIR
        ${ME_INC}/MakeEngine.h

        MEBaseTypes.h
        MEGlobal.h
        MEDebug.h MEDebug.cpp
        METime.h METime.cpp

        MESystem/MEDelegate.cpp MESystem/MEDelegate.h
        MEApplication/MEWindow.cpp MEApplication/MEWindow.h
        )

add_library(MakeEngine SHARED ${LIB_SRC_DIR})