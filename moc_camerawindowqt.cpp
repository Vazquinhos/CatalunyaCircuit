/****************************************************************************
** Meta object code from reading C++ file 'camerawindowqt.h'
**
** Created: Mon May 20 20:57:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Ui/camerawindowqt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camerawindowqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CameraWindowQt[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   34,   15,   15, 0x08,
     111,   15,   15,   15, 0x08,
     135,   15,   15,   15, 0x08,
     159,   15,   15,   15, 0x08,
     182,   15,   15,   15, 0x08,
     212,  202,   15,   15, 0x08,
     239,   15,   15,   15, 0x08,
     276,  270,   15,   15, 0x08,
     312,   15,   15,   15, 0x08,
     340,   15,   15,   15, 0x08,
     370,  270,   15,   15, 0x08,
     406,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CameraWindowQt[] = {
    "CameraWindowQt\0\0EditionFinished()\0"
    "current,\0"
    "on_listWidget_currentItemChanged(QListWidgetItem*,QListWidgetItem*)\0"
    "on_buttonBox_accepted()\0on_pushButton_clicked()\0"
    "on_pb_delete_clicked()\0on_pb_add_clicked()\0"
    "ap_camera\0NewCameraAdded(CameraAbs*)\0"
    "on_line_name_editingFinished()\0index\0"
    "on_cb_mode_currentIndexChanged(int)\0"
    "on_sb_yaw_editingFinished()\0"
    "on_sb_pitch_editingFinished()\0"
    "on_cb_type_currentIndexChanged(int)\0"
    "on_cb_zoom_editingFinished()\0"
};

void CameraWindowQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CameraWindowQt *_t = static_cast<CameraWindowQt *>(_o);
        switch (_id) {
        case 0: _t->EditionFinished(); break;
        case 1: _t->on_listWidget_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 2: _t->on_buttonBox_accepted(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pb_delete_clicked(); break;
        case 5: _t->on_pb_add_clicked(); break;
        case 6: _t->NewCameraAdded((*reinterpret_cast< CameraAbs*(*)>(_a[1]))); break;
        case 7: _t->on_line_name_editingFinished(); break;
        case 8: _t->on_cb_mode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_sb_yaw_editingFinished(); break;
        case 10: _t->on_sb_pitch_editingFinished(); break;
        case 11: _t->on_cb_type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_cb_zoom_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CameraWindowQt::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CameraWindowQt::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CameraWindowQt,
      qt_meta_data_CameraWindowQt, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CameraWindowQt::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CameraWindowQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CameraWindowQt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraWindowQt))
        return static_cast<void*>(const_cast< CameraWindowQt*>(this));
    return QDialog::qt_metacast(_clname);
}

int CameraWindowQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CameraWindowQt::EditionFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
