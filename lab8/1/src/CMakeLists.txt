project(ood)

set(HEADER_FILES
        NaiveGumBallMachine.h
        GumBallMachineWithState.h
        GumBallMachineWithDynamicallyCreatedState.h
        )

add_library(src_lib INTERFACE ${HEADER_FILES})