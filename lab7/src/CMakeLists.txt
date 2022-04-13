project(ood)

set(HEADER_FILES
        IStyleEnumerator.h
        CCompositeLineStyle.h
        CCompositeFillStyle.h
        CommonTypes.h
        ICanvas.h
        ISlide.h
        IDrawable.h
        ILineStyle.h
        IGroupShape.h
        IShape.h
        IShapes.h
        IFillStyle.h
        CSlide.h
        CSimpleShape.h
        CGroupShape.h
        CShape.h
        CLineStyle.h
        CFillStyle.h
        CSvgCanvas.h
        CRectangle.h
        CTriangle.h
        CEllipse.h)

set(SOURCE_FILES
        CSlide.cpp
        CShape.cpp
        CCompositeLineStyle.cpp
        CCompositeFillStyle.cpp
        CLineStyle.cpp
        CFillStyle.cpp
        CSvgCanvas.cpp
        CRectangle.cpp
        CTriangle.cpp
        CGroupShape.cpp
        CEllipse.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})