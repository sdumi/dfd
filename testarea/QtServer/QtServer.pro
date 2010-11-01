TEMPLATE = app
TARGET = QtServer
QT += core
QT += network
HEADERS += MultiClientServer.h
SOURCES += MultiClientServer.cpp \
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
