/****************************************************************************
** Meta object code from reading C++ file 'CreateCommitmentQWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Tasker/CreateCommitmentQWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateCommitmentQWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CreateCommitmentQWidget_t {
    QByteArrayData data[7];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateCommitmentQWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateCommitmentQWidget_t qt_meta_stringdata_CreateCommitmentQWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "CreateCommitmentQWidget"
QT_MOC_LITERAL(1, 24, 34), // "on_dropDownTaskQComboBox_acti..."
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 4), // "arg1"
QT_MOC_LITERAL(4, 65, 26), // "createCommitmentButtonSlot"
QT_MOC_LITERAL(5, 92, 14), // "backButtonSlot"
QT_MOC_LITERAL(6, 107, 35) // "on_createCommitmentQFrame_des..."

    },
    "CreateCommitmentQWidget\0"
    "on_dropDownTaskQComboBox_activated\0\0"
    "arg1\0createCommitmentButtonSlot\0"
    "backButtonSlot\0on_createCommitmentQFrame_destroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateCommitmentQWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateCommitmentQWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CreateCommitmentQWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_dropDownTaskQComboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->createCommitmentButtonSlot(); break;
        case 2: _t->backButtonSlot(); break;
        case 3: _t->on_createCommitmentQFrame_destroyed(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CreateCommitmentQWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CreateCommitmentQWidget.data,
    qt_meta_data_CreateCommitmentQWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CreateCommitmentQWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateCommitmentQWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreateCommitmentQWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CreateCommitmentQWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
