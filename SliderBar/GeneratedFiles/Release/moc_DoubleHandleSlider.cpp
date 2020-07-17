/****************************************************************************
** Meta object code from reading C++ file 'DoubleHandleSlider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DoubleHandleSlider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DoubleHandleSlider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoubleHandleSlider_t {
    QByteArrayData data[5];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoubleHandleSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoubleHandleSlider_t qt_meta_stringdata_DoubleHandleSlider = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DoubleHandleSlider"
QT_MOC_LITERAL(1, 19, 20), // "MinHandleValueChange"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 9), // "cur_value"
QT_MOC_LITERAL(4, 51, 20) // "MaxHandleValueChange"

    },
    "DoubleHandleSlider\0MinHandleValueChange\0"
    "\0cur_value\0MaxHandleValueChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoubleHandleSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void DoubleHandleSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DoubleHandleSlider *_t = static_cast<DoubleHandleSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MinHandleValueChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->MaxHandleValueChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DoubleHandleSlider::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DoubleHandleSlider::MinHandleValueChange)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DoubleHandleSlider::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DoubleHandleSlider::MaxHandleValueChange)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DoubleHandleSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DoubleHandleSlider.data,
      qt_meta_data_DoubleHandleSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DoubleHandleSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoubleHandleSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DoubleHandleSlider.stringdata0))
        return static_cast<void*>(const_cast< DoubleHandleSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int DoubleHandleSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DoubleHandleSlider::MinHandleValueChange(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DoubleHandleSlider::MaxHandleValueChange(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
