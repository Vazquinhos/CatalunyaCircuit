/****************************************************************************
** Meta object code from reading C++ file 'newcameraqt.h'
**
** Created: Wed May 22 21:43:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Ui/newcameraqt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newcameraqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewCameraQt[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   12,   12,   12, 0x08,
      66,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewCameraQt[] = {
    "NewCameraQt\0\0NewCameraCreated(CameraAbs*)\0"
    "on_buttonBox_accepted()\0errorAcepted()\0"
};

void NewCameraQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewCameraQt *_t = static_cast<NewCameraQt *>(_o);
        switch (_id) {
        case 0: _t->NewCameraCreated((*reinterpret_cast< CameraAbs*(*)>(_a[1]))); break;
        case 1: _t->on_buttonBox_accepted(); break;
        case 2: _t->errorAcepted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NewCameraQt::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewCameraQt::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewCameraQt,
      qt_meta_data_NewCameraQt, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewCameraQt::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewCameraQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewCameraQt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewCameraQt))
        return static_cast<void*>(const_cast< NewCameraQt*>(this));
    if (!strcmp(_clname, "Ui::NewCameraQt"))
        return static_cast< Ui::NewCameraQt*>(const_cast< NewCameraQt*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewCameraQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void NewCameraQt::NewCameraCreated(CameraAbs * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
