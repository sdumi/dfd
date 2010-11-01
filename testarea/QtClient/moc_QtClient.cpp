/****************************************************************************
** Meta object code from reading C++ file 'QtClient.h'
**
** Created: Fri Oct 22 17:14:31 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QtClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtClient[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x09,
      28,    9,    9,    9, 0x09,
      35,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QtClient[] = {
    "QtClient\0\0clientConnected()\0read()\0"
    "showError()\0"
};

const QMetaObject QtClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtClient,
      qt_meta_data_QtClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtClient))
        return static_cast<void*>(const_cast< QtClient*>(this));
    return QObject::qt_metacast(_clname);
}

int QtClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clientConnected(); break;
        case 1: read(); break;
        case 2: showError(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
