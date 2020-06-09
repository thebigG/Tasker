/****************************************************************************
** Meta object code from reading C++ file 'AudioDevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AudioDevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AudioDevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Engine__AudioDevice_t {
    QByteArrayData data[10];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Engine__AudioDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Engine__AudioDevice_t qt_meta_stringdata_Engine__AudioDevice = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Engine::AudioDevice"
QT_MOC_LITERAL(1, 20, 9), // "audioRead"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "readData"
QT_MOC_LITERAL(4, 40, 5), // "char*"
QT_MOC_LITERAL(5, 46, 4), // "data"
QT_MOC_LITERAL(6, 51, 6), // "maxlen"
QT_MOC_LITERAL(7, 58, 9), // "writeData"
QT_MOC_LITERAL(8, 68, 11), // "const char*"
QT_MOC_LITERAL(9, 80, 3) // "len"

    },
    "Engine::AudioDevice\0audioRead\0\0readData\0"
    "char*\0data\0maxlen\0writeData\0const char*\0"
    "len"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Engine__AudioDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   30,    2, 0x0a /* Public */,
       7,    2,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::LongLong, 0x80000000 | 4, QMetaType::LongLong,    5,    6,
    QMetaType::LongLong, 0x80000000 | 8, QMetaType::LongLong,    5,    9,

       0        // eod
};

void Engine::AudioDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AudioDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->audioRead(); break;
        case 1: { qint64 _r = _t->readData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        case 2: { qint64 _r = _t->writeData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AudioDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioDevice::audioRead)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Engine::AudioDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QIODevice::staticMetaObject>(),
    qt_meta_stringdata_Engine__AudioDevice.data,
    qt_meta_data_Engine__AudioDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Engine::AudioDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Engine::AudioDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Engine__AudioDevice.stringdata0))
        return static_cast<void*>(this);
    return QIODevice::qt_metacast(_clname);
}

int Engine::AudioDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Engine::AudioDevice::audioRead()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
