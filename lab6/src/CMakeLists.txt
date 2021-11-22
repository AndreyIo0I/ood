project(ood)

set(HEADER_FILES
        app.h
        shape_drawing_lib.h
        modern_graphics_lib.h
        graphics_lib.h
        )

set(SOURCE_FILES
        app.cpp
        shape_drawing_lib.cpp
        modern_graphics_lib.cpp
        graphics_lib.cpp
        )

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})