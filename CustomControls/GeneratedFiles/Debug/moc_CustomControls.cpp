/****************************************************************************
** Meta object code from reading C++ file 'CustomControls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CustomControls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CustomControls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomControls_t {
    QByteArrayData data[12];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomControls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomControls_t qt_meta_stringdata_CustomControls = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CustomControls"
QT_MOC_LITERAL(1, 15, 26), // "on_progressbar_btn_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 24), // "on_sliderbar_btn_clicked"
QT_MOC_LITERAL(4, 68, 20), // "on_panel_btn_clicked"
QT_MOC_LITERAL(5, 89, 18), // "on_qwt_btn_clicked"
QT_MOC_LITERAL(6, 108, 24), // "on_animation_btn_clicked"
QT_MOC_LITERAL(7, 133, 26), // "on_otherbutton_btn_clicked"
QT_MOC_LITERAL(8, 160, 25), // "on_custom_win_btn_clicked"
QT_MOC_LITERAL(9, 186, 16), // "SetProgressValue"
QT_MOC_LITERAL(10, 203, 5), // "value"
QT_MOC_LITERAL(11, 209, 13) // "SetPanelValue"

    },
    "CustomControls\0on_progressbar_btn_clicked\0"
    "\0on_sliderbar_btn_clicked\0"
    "on_panel_btn_clicked\0on_qwt_btn_clicked\0"
    "on_animation_btn_clicked\0"
    "on_otherbutton_btn_clicked\0"
    "on_custom_win_btn_clicked\0SetProgressValue\0"
    "value\0SetPanelValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomControls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void CustomControls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomControls *_t = static_cast<CustomControls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_progressbar_btn_clicked(); break;
        case 1: _t->on_sliderbar_btn_clicked(); break;
        case 2: _t->on_panel_btn_clicked(); break;
        case 3: _t->on_qwt_btn_clicked(); break;
        case 4: _t->on_animation_btn_clicked(); break;
        case 5: _t->on_otherbutton_btn_clicked(); break;
        case 6: _t->on_custom_win_btn_clicked(); break;
        case 7: _t->SetProgressValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->SetPanelValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CustomControls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CustomControls.data,
      qt_meta_data_CustomControls,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CustomControls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomControls::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CustomControls.stringdata0))
        return static_cast<void*>(const_cast< CustomControls*>(this));
    return QWidget::qt_metacast(_clname);
}

int CustomControls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
