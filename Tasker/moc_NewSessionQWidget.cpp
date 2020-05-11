/****************************************************************************
** Meta object code from reading C++ file 'NewSessionQWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "NewSessionQWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewSessionQWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewSessionQWidget_t {
    QByteArrayData data[7];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewSessionQWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewSessionQWidget_t qt_meta_stringdata_NewSessionQWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "NewSessionQWidget"
QT_MOC_LITERAL(1, 18, 14), // "backButtonSlot"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "startTimerButtonSlot"
QT_MOC_LITERAL(4, 55, 30), // "on_timerWindowQFrame_destroyed"
QT_MOC_LITERAL(5, 86, 16), // "dropDownTaskSlot"
QT_MOC_LITERAL(6, 103, 4) // "arg1"

    },
    "NewSessionQWidget\0backButtonSlot\0\0"
    "startTimerButtonSlot\0"
    "on_timerWindowQFrame_destroyed\0"
    "dropDownTaskSlot\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewSessionQWidget[] = {

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
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void NewSessionQWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewSessionQWidget *_t = static_cast<NewSessionQWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backButtonSlot(); break;
        case 1: _t->startTimerButtonSlot(); break;
        case 2: _t->on_timerWindowQFrame_destroyed(); break;
        case 3: _t->dropDownTaskSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NewSessionQWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NewSessionQWidget.data,
      qt_meta_data_NewSessionQWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NewSessionQWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewSessionQWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewSessionQWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int NewSessionQWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
