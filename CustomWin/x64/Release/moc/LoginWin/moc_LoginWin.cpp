/****************************************************************************
** Meta object code from reading C++ file 'LoginWin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../LoginWin/LoginWin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginWin_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginWin_t qt_meta_stringdata_LoginWin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LoginWin"
QT_MOC_LITERAL(1, 9, 20), // "on_btn_close_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "on_btn_min_clicked"
QT_MOC_LITERAL(4, 50, 17), // "OpenStateMenuSlot"
QT_MOC_LITERAL(5, 68, 15), // "ChooseStateSlot"
QT_MOC_LITERAL(6, 84, 10) // "USER_STATE"

    },
    "LoginWin\0on_btn_close_clicked\0\0"
    "on_btn_min_clicked\0OpenStateMenuSlot\0"
    "ChooseStateSlot\0USER_STATE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void LoginWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginWin *_t = static_cast<LoginWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_close_clicked(); break;
        case 1: _t->on_btn_min_clicked(); break;
        case 2: _t->OpenStateMenuSlot(); break;
        case 3: _t->ChooseStateSlot((*reinterpret_cast< USER_STATE(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject LoginWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginWin.data,
      qt_meta_data_LoginWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginWin.stringdata0))
        return static_cast<void*>(const_cast< LoginWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoginWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
