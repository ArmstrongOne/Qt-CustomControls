/****************************************************************************
** Meta object code from reading C++ file 'LoginStateWid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../LoginWin/LoginStateWid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginStateWid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginStateWid_t {
    QByteArrayData data[9];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginStateWid_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginStateWid_t qt_meta_stringdata_LoginStateWid = {
    {
QT_MOC_LITERAL(0, 0, 13), // "LoginStateWid"
QT_MOC_LITERAL(1, 14, 11), // "ChooseState"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "USER_STATE"
QT_MOC_LITERAL(4, 38, 32), // "on_radiobtn_state_online_clicked"
QT_MOC_LITERAL(5, 71, 31), // "on_radiobtn_state_leave_clicked"
QT_MOC_LITERAL(6, 103, 30), // "on_radiobtn_state_busy_clicked"
QT_MOC_LITERAL(7, 134, 36), // "on_radiobtn_state_notdisturb_..."
QT_MOC_LITERAL(8, 171, 35) // "on_radiobtn_state_invisable_c..."

    },
    "LoginStateWid\0ChooseState\0\0USER_STATE\0"
    "on_radiobtn_state_online_clicked\0"
    "on_radiobtn_state_leave_clicked\0"
    "on_radiobtn_state_busy_clicked\0"
    "on_radiobtn_state_notdisturb_clicked\0"
    "on_radiobtn_state_invisable_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginStateWid[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginStateWid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginStateWid *_t = static_cast<LoginStateWid *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChooseState((*reinterpret_cast< USER_STATE(*)>(_a[1]))); break;
        case 1: _t->on_radiobtn_state_online_clicked(); break;
        case 2: _t->on_radiobtn_state_leave_clicked(); break;
        case 3: _t->on_radiobtn_state_busy_clicked(); break;
        case 4: _t->on_radiobtn_state_notdisturb_clicked(); break;
        case 5: _t->on_radiobtn_state_invisable_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginStateWid::*_t)(USER_STATE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginStateWid::ChooseState)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject LoginStateWid::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginStateWid.data,
      qt_meta_data_LoginStateWid,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginStateWid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginStateWid::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginStateWid.stringdata0))
        return static_cast<void*>(const_cast< LoginStateWid*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoginStateWid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LoginStateWid::ChooseState(USER_STATE _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
