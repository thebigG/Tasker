/****************************************************************************
** Meta object code from reading C++ file 'CommStatsQWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Tasker/CommStatsQWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommStatsQWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommStatsQWidget_t {
    QByteArrayData data[11];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommStatsQWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommStatsQWidget_t qt_meta_stringdata_CommStatsQWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CommStatsQWidget"
QT_MOC_LITERAL(1, 17, 23), // "addCommitmentButtonSlot"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 26), // "removeCommitmentButtonSlot"
QT_MOC_LITERAL(4, 69, 28), // "currentCommitmentChangedSlot"
QT_MOC_LITERAL(5, 98, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 115, 18), // "newLiveSessionSlot"
QT_MOC_LITERAL(7, 134, 24), // "on_statsQFrame_destroyed"
QT_MOC_LITERAL(8, 159, 43), // "on_commitmentsQTreeWidget_ite..."
QT_MOC_LITERAL(9, 203, 4), // "item"
QT_MOC_LITERAL(10, 208, 6) // "column"

    },
    "CommStatsQWidget\0addCommitmentButtonSlot\0"
    "\0removeCommitmentButtonSlot\0"
    "currentCommitmentChangedSlot\0"
    "QTreeWidgetItem*\0newLiveSessionSlot\0"
    "on_statsQFrame_destroyed\0"
    "on_commitmentsQTreeWidget_itemDoubleClicked\0"
    "item\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommStatsQWidget[] = {

 // content:
       8,       // revision
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
       4,    2,   46,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    2,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    9,   10,

       0        // eod
};

void CommStatsQWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommStatsQWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addCommitmentButtonSlot(); break;
        case 1: _t->removeCommitmentButtonSlot(); break;
        case 2: _t->currentCommitmentChangedSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 3: _t->newLiveSessionSlot(); break;
        case 4: _t->on_statsQFrame_destroyed(); break;
        case 5: _t->on_commitmentsQTreeWidget_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommStatsQWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CommStatsQWidget.data,
    qt_meta_data_CommStatsQWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommStatsQWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommStatsQWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommStatsQWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CommStatsQWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
