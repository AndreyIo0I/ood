project(ood)

set(HEADER_FILES
        GumBallMachineWithState.h
        )

add_library(src_lib INTERFACE ${HEADER_FILES})