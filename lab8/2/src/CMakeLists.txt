project(ood)

set(HEADER_FILES
        GumBallMachineWithState.h
        NaiveGumBallMachine.h
        )

add_library(src_lib INTERFACE ${HEADER_FILES})