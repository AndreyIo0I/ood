project(ood)

set(HEADER_FILES
        "command/CAbstractCommand.h"
        "command/CAddItemCommand.h"
        "command/CChangeStringCommand.h"
        "command/CReplaceTextCommand.hpp"
        "command/CResizeImageCommand.hpp"
        CConstDocumentItem.h
        CDocument.h
        CDocumentItem.h
        CEditor.h
        CHistory.h
        ICommand.h
        IDocument.h
        IImage.h
        CImage.h
        IParagraph.h
        CMenu.h
        CParagraph.h
)

set(SOURCE_FILES
        "command/CAbstractCommand.cpp"
        "command/CChangeStringCommand.cpp"
        CConstDocumentItem.cpp
        CDocument.cpp
        CDocumentItem.cpp
        CHistory.cpp
        CImage.cpp
        CMenu.cpp
        CParagraph.cpp
        "command/CAddItemCommand.cpp"
)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES} "CHtmlSaver.h" "CHtmlSaver.cpp")