/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[333];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "weightSelected"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "appQuited"
QT_MOC_LITERAL(4, 37, 12), // "detectorInit"
QT_MOC_LITERAL(5, 50, 19), // "on_btn_save_clicked"
QT_MOC_LITERAL(6, 70, 20), // "on_btn_start_clicked"
QT_MOC_LITERAL(7, 91, 19), // "on_btn_stop_clicked"
QT_MOC_LITERAL(8, 111, 22), // "on_btn_connect_clicked"
QT_MOC_LITERAL(9, 134, 27), // "on_radioButton_fast_clicked"
QT_MOC_LITERAL(10, 162, 30), // "on_radioButton_precise_clicked"
QT_MOC_LITERAL(11, 193, 29), // "on_radioButton_medium_clicked"
QT_MOC_LITERAL(12, 223, 7), // "appQuit"
QT_MOC_LITERAL(13, 231, 7), // "speedUp"
QT_MOC_LITERAL(14, 239, 9), // "speedDown"
QT_MOC_LITERAL(15, 249, 8), // "openFile"
QT_MOC_LITERAL(16, 258, 10), // "screenShot"
QT_MOC_LITERAL(17, 269, 14), // "selectProjPath"
QT_MOC_LITERAL(18, 284, 13), // "selectOffMode"
QT_MOC_LITERAL(19, 298, 18), // "selectRealTimeMode"
QT_MOC_LITERAL(20, 317, 15) // "simulationPause"

    },
    "MainWindow\0weightSelected\0\0appQuited\0"
    "detectorInit\0on_btn_save_clicked\0"
    "on_btn_start_clicked\0on_btn_stop_clicked\0"
    "on_btn_connect_clicked\0"
    "on_radioButton_fast_clicked\0"
    "on_radioButton_precise_clicked\0"
    "on_radioButton_medium_clicked\0appQuit\0"
    "speedUp\0speedDown\0openFile\0screenShot\0"
    "selectProjPath\0selectOffMode\0"
    "selectRealTimeMode\0simulationPause"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    0,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    0,  121,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    0,  124,    2, 0x08 /* Private */,
      18,    0,  125,    2, 0x08 /* Private */,
      19,    0,  126,    2, 0x08 /* Private */,
      20,    0,  127,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->weightSelected(); break;
        case 1: _t->appQuited(); break;
        case 2: _t->detectorInit(); break;
        case 3: _t->on_btn_save_clicked(); break;
        case 4: _t->on_btn_start_clicked(); break;
        case 5: _t->on_btn_stop_clicked(); break;
        case 6: _t->on_btn_connect_clicked(); break;
        case 7: _t->on_radioButton_fast_clicked(); break;
        case 8: _t->on_radioButton_precise_clicked(); break;
        case 9: _t->on_radioButton_medium_clicked(); break;
        case 10: _t->appQuit(); break;
        case 11: _t->speedUp(); break;
        case 12: _t->speedDown(); break;
        case 13: _t->openFile(); break;
        case 14: _t->screenShot(); break;
        case 15: _t->selectProjPath(); break;
        case 16: _t->selectOffMode(); break;
        case 17: _t->selectRealTimeMode(); break;
        case 18: _t->simulationPause(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::weightSelected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::appQuited)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::weightSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::appQuited()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
