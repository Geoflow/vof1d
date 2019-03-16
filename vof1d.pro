SOURCES += \
    cell.cpp \
    mesh.cpp \
    main.cpp

HEADERS += \
    cell.h \
    mesh.h

INCLUDEPATH += /usr/include/armadillo_bits
LIBS += \
    -llapack \
    -lblas
