/****************************************************************************
** Meta object code from reading C++ file 'CreateCommitmentQWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CreateCommitmentQWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateCommitmentQWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CreateCommitmentQWidget_t {
    QByteArrayData data[9];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateCommitmentQWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateCommitmentQWidget_t qt_meta_stringdata_CreateCommitmentQWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "CreateCommitmentQWidget"
QT_MOC_LITERAL(1, 24, 14), // "commitmentEdit"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 26), // "createCommitmentButtonSlot"
QT_MOC_LITERAL(4, 67, 14), // "backButtonSlot"
QT_MOC_LITERAL(5, 82, 18), // "noEndDateCheckSlot"
QT_MOC_LITERAL(6, 101, 35), // "on_createCommitmentQFrame_des..."
QT_MOC_LITERAL(7, 137, 38), // "currentIndexCommitmentModeCom..."
QT_MOC_LITERAL(8, 176, 33) // "currentIndexFrequencyComboBox..."

    },
    "CreateCommitmentQWidget\0commitmentEdit\0"
    "\0createCommitmentButtonSlot\0backButtonSlot\0"
    "noEndDateCheckSlot\0"
    "on_createCommitmentQFrame_destroyed\0"
    "currentIndexCommitmentModeComboBoxSlot\0"
    "currentIndexFrequencyComboBoxSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateCommitmentQWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void CreateCommitmentQWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateCommitmentQWidget *_t = static_cast<CreateCommitmentQWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commitmentEdit(); break;
        case 1: _t->createCommitmentButtonSlot(); break;
        case 2: _t->backButtonSlot(); break;
        case 3: _t->noEndDateCheckSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_createCommitmentQFrame_destroyed(); break;
        case 5: _t->currentIndexCommitmentModeComboBoxSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->currentIndexFrequencyComboBoxSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CreateCommitmentQWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateCommitmentQWidget::commitmentEdit)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CreateCommitmentQWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CreateCommitmentQWidget.data,
      qt_meta_data_CreateCommitmentQWidget,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CreateCommitmentQWidget::commitmentEdit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
