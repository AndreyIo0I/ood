project(ood)

set(HEADER_FILES
        CPainter.h
        IShapeFactory.h
        ICanvas.h
        IDesigner.h
        CDesigner.h
        CPictureDraft.h
        CShape.h
        Color.h
        CRectangle.h
        Point.h
        CTriangle.h
        CEllipse.h
        CRegularPolygon.h
        CShapeFactory.h
        CSvgCanvas.h
        )

set(SOURCE_FILES
        CSvgCanvas.cpp
        CPainter.cpp
        CShapeFactory.cpp
        CDesigner.cpp
        CPictureDraft.cpp
        CShape.cpp
        CRectangle.cpp
        CTriangle.cpp
        CEllipse.cpp
        CRegularPolygon.cpp
        )

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})