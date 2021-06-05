set(ME_INC ../include)

set(LIB_SRC_DIR
        MEBaseTypes.h
        MEGlobal.h
        MEDebug.h MEDebug.cpp
        METime.h METime.cpp

        ${ME_INC}/MakeEngine.h
        )

add_library(MakeEngine SHARED ${LIB_SRC_DIR})