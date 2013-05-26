/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun May 26 23:36:05 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Ui/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

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
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   11,   11,   11, 0x08,
      50,   11,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
      94,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     119,   11,   11,   11, 0x08,
     132,   11,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     229,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0StartAnimation()\0"
    "on_cameras_clicked()\0on_import_2_clicked()\0"
    "on_export_2_clicked()\0on_cars_clicked()\0"
    "Menu()\0showMySelf()\0on_about_clicked()\0"
    "CarEditingFinish()\0on_play_clicked()\0"
    "on_pause_clicked()\0on_trajects_clicked()\0"
    "on_lights_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->StartAnimation(); break;
        case 1: _t->on_cameras_clicked(); break;
        case 2: _t->on_import_2_clicked(); break;
        case 3: _t->on_export_2_clicked(); break;
        case 4: _t->on_cars_clicked(); break;
        case 5: _t->Menu(); break;
        case 6: _t->showMySelf(); break;
        case 7: _t->on_about_clicked(); break;
        case 8: _t->CarEditingFinish(); break;
        case 9: _t->on_play_clicked(); break;
        case 10: _t->on_pause_clicked(); break;
        case 11: _t->on_trajects_clicked(); break;
        case 12: _t->on_lights_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MainWindow::StartAnimation()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
