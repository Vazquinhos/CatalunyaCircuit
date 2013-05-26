/****************************************************************************
** Meta object code from reading C++ file 'carviewer.h'
**
** Created: Sun May 26 23:40:30 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Objects/carviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'carviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CarViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      28,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CarViewer[] = {
    "CarViewer\0\0shiftCarToNext()\0"
    "shiftCarToPrevious()\0"
};

void CarViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CarViewer *_t = static_cast<CarViewer *>(_o);
        switch (_id) {
        case 0: _t->shiftCarToNext(); break;
        case 1: _t->shiftCarToPrevious(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CarViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CarViewer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CarViewer,
      qt_meta_data_CarViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CarViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CarViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CarViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CarViewer))
        return static_cast<void*>(const_cast< CarViewer*>(this));
    return QObject::qt_metacast(_clname);
}

int CarViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
