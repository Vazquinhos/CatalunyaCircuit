/****************************************************************************
** Meta object code from reading C++ file 'modelManager.h'
**
** Created: Mon May 20 00:38:01 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Objects/modelManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModelManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      27,   23,   13,   13, 0x05,
      52,   42,   13,   13, 0x05,
      74,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ModelManager[] = {
    "ModelManager\0\0finish()\0err\0error(QString)\0"
    "model,val\0NewModel(QString,int)\0"
    "NModels(int)\0loadModels()\0"
};

void ModelManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModelManager *_t = static_cast<ModelManager *>(_o);
        switch (_id) {
        case 0: _t->finish(); break;
        case 1: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->NewModel((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->NModels((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->loadModels(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ModelManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModelManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModelManager,
      qt_meta_data_ModelManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModelManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModelManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModelManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModelManager))
        return static_cast<void*>(const_cast< ModelManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ModelManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ModelManager::finish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ModelManager::error(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModelManager::NewModel(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ModelManager::NModels(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
