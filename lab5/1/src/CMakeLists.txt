project(ood)

set(HEADER_FILES
        AbstractCommand.cpp
        AbstractCommand.h
        ChangeStringCommand.cpp
        ChangeStringCommand.h
        ConstDocumentItem.cpp
        ConstDocumentItem.h
        Document.cpp
        Document.h
        DocumentItem.cpp
        DocumentItem.h
        Editor.h
        History.h
        History.cpp
        ICommand.h
        IDocument.h
        IImage.h
        Image.cpp
        Image.h
        ImageImpl.cpp
        ImageImpl.h
        IParagraph.h
        Menu.cpp
        Menu.h
        Paragraph.cpp
        Paragraph.h
        )

add_library(src_lib INTERFACE ${HEADER_FILES})