/****************************************************************************
** Meta object code from reading C++ file 'trademark.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../trademark.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trademark.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TradeMark_t {
    QByteArrayData data[8];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TradeMark_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TradeMark_t qt_meta_stringdata_TradeMark = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 18),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 16),
QT_MOC_LITERAL(4, 47, 17),
QT_MOC_LITERAL(5, 65, 19),
QT_MOC_LITERAL(6, 85, 15),
QT_MOC_LITERAL(7, 101, 19)
    },
    "TradeMark\0handleButtonSelect\0\0"
    "handleButtonLeft\0handleButtonRight\0"
    "handleButtonReWater\0handleButtonCut\0"
    "handleButtonGetInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TradeMark[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TradeMark::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TradeMark *_t = static_cast<TradeMark *>(_o);
        switch (_id) {
        case 0: _t->handleButtonSelect(); break;
        case 1: _t->handleButtonLeft(); break;
        case 2: _t->handleButtonRight(); break;
        case 3: _t->handleButtonReWater(); break;
        case 4: _t->handleButtonCut(); break;
        case 5: _t->handleButtonGetInfo(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TradeMark::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TradeMark.data,
      qt_meta_data_TradeMark,  qt_static_metacall, 0, 0}
};


const QMetaObject *TradeMark::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TradeMark::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TradeMark.stringdata))
        return static_cast<void*>(const_cast< TradeMark*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TradeMark::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
