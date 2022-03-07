/****************************************************************************
** Meta object code from reading C++ file 'jscontext.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jscontext.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jscontext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JsContext_t {
    QByteArrayData data[9];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JsContext_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JsContext_t qt_meta_stringdata_JsContext = {
    {
QT_MOC_LITERAL(0, 0, 9), // "JsContext"
QT_MOC_LITERAL(1, 10, 14), // "CoordinatesGet"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "lon"
QT_MOC_LITERAL(4, 30, 3), // "lat"
QT_MOC_LITERAL(5, 34, 14), // "ObjectIndexGet"
QT_MOC_LITERAL(6, 49, 5), // "index"
QT_MOC_LITERAL(7, 55, 14), // "getCoordinates"
QT_MOC_LITERAL(8, 70, 14) // "getObjectIndex"

    },
    "JsContext\0CoordinatesGet\0\0lon\0lat\0"
    "ObjectIndexGet\0index\0getCoordinates\0"
    "getObjectIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JsContext[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   42,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void JsContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JsContext *_t = static_cast<JsContext *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CoordinatesGet((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->ObjectIndexGet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->getCoordinates((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->getObjectIndex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (JsContext::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsContext::CoordinatesGet)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (JsContext::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsContext::ObjectIndexGet)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject JsContext::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JsContext.data,
      qt_meta_data_JsContext,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *JsContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JsContext::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JsContext.stringdata0))
        return static_cast<void*>(const_cast< JsContext*>(this));
    return QObject::qt_metacast(_clname);
}

int JsContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void JsContext::CoordinatesGet(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JsContext::ObjectIndexGet(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
