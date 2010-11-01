TEMPLATE = app
TARGET = Compression
QT += core
HEADERS += Compressor.h
SOURCES += Compressor.cpp \
    main.cpp
FORMS += 
RESOURCES += 
### ++
# needed by Dumi:
# path to freetype libs
#
QMAKE_LFLAGS *= -L/local/dev/lib
#
### --
