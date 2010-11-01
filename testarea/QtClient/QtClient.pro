TEMPLATE = app
TARGET = QtClient
QT += core
QT += network
HEADERS += QtClient.h
SOURCES += QtClient.cpp \
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

