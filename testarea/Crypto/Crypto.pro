TEMPLATE = app
TARGET = Crypto
QT += core
HEADERS += Crypto.h
SOURCES += Crypto.cpp \
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
