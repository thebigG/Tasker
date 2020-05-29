/****************************************************************************
** Meta object code from reading C++ file 'CommStatsQWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CommStatsQWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommStatsQWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommStatsQWidget_t {
    QByteArrayData data[17];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommStatsQWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommStatsQWidget_t qt_meta_stringdata_CommStatsQWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CommStatsQWidget"
QT_MOC_LITERAL(1, 17, 18), // "saveCurrentSession"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "newCommitmentSlot"
QT_MOC_LITERAL(4, 55, 18), // "editCommitmentSlot"
QT_MOC_LITERAL(5, 74, 20), // "deleteCommitmentSlot"
QT_MOC_LITERAL(6, 95, 14), // "newSessionSlot"
QT_MOC_LITERAL(7, 110, 28), // "currentCommitmentChangedSlot"
QT_MOC_LITERAL(8, 139, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(9, 156, 21), // "itemDoubleClickedSlot"
QT_MOC_LITERAL(10, 178, 4), // "item"
QT_MOC_LITERAL(11, 183, 6), // "column"
QT_MOC_LITERAL(12, 190, 18), // "newLiveSessionSlot"
QT_MOC_LITERAL(13, 209, 24), // "on_statsQFrame_destroyed"
QT_MOC_LITERAL(14, 234, 16), // "previousSnapshot"
QT_MOC_LITERAL(15, 251, 12), // "nextSnapshot"
QT_MOC_LITERAL(16, 264, 26) // "updateLiveSessionStateSlot"

    },
    "CommStatsQWidget\0saveCurrentSession\0"
    "\0newCommitmentSlot\0editCommitmentSlot\0"
    "deleteCommitmentSlot\0newSessionSlot\0"
    "currentCommitmentChangedSlot\0"
    "QTreeWidgetItem*\0itemDoubleClickedSlot\0"
    "item\0column\0newLiveSessionSlot\0"
    "on_statsQFrame_destroyed\0previousSnapshot\0"
    "nextSnapshot\0updateLiveSessionStateSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommStatsQWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    1,   75,    2, 0x0a /* Public */,
       4,    1,   78,    2, 0x0a /* Public */,
       5,    1,   81,    2, 0x0a /* Public */,
       6,    1,   84,    2, 0x0a /* Public */,
       7,    2,   87,    2, 0x0a /* Public */,
       9,    2,   92,    2, 0x0a /* Public */,
      12,    0,   97,    2, 0x0a /* Public */,
      13,    0,   98,    2, 0x0a /* Public */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    2,    2,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CommStatsQWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommStatsQWidget *_t = static_cast<CommStatsQWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveCurrentSession(); break;
        case 1: _t->newCommitmentSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->editCommitmentSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->deleteCommitmentSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->newSessionSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->currentCommitmentChangedSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 6: _t->itemDoubleClickedSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->newLiveSessionSlot(); break;
        case 8: _t->on_statsQFrame_destroyed(); break;
        case 9: _t->previousSnapshot(); break;
        case 10: _t->nextSnapshot(); break;
        case 11: _t->updateLiveSessionStateSlot(); break;
        default: ;
        }
    }
}

const QMetaObject CommStatsQWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CommStatsQWidget.data,
      qt_meta_data_CommStatsQWidget,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
