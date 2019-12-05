/****************************************************************************
** Meta object code from reading C++ file 'AudioListener.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Tasker/AudioListener.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AudioListener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Engine__AudioListener_t {
    QByteArrayData data[8];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Engine__AudioListener_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Engine__AudioListener_t qt_meta_stringdata_Engine__AudioListener = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Engine::AudioListener"
QT_MOC_LITERAL(1, 22, 12), // "signalThread"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 3), // "run"
QT_MOC_LITERAL(4, 40, 5), // "start"
QT_MOC_LITERAL(5, 46, 3), // "end"
QT_MOC_LITERAL(6, 50, 5), // "pause"
QT_MOC_LITERAL(7, 56, 6) // "update"

    },
    "Engine::AudioListener\0signalThread\0\0"
    "run\0start\0end\0pause\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Engine__AudioListener[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Engine::AudioListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AudioListener *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalThread(); break;
        case 1: _t->run(); break;
        case 2: _t->start(); break;
        case 3: _t->end(); break;
        case 4: _t->pause(); break;
        case 5: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AudioListener::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioListener::signalThread)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Engine::AudioListener::staticMetaObject = { {
    &Engine::Listener::staticMetaObject,
    qt_meta_stringdata_Engine__AudioListener.data,
    qt_meta_data_Engine__AudioListener,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Engine::AudioListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Engine::AudioListener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Engine__AudioListener.stringdata0))
        return static_cast<void*>(this);
    return Engine::Listener::qt_metacast(_clname);
}

int Engine::AudioListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Engine::Listener::qt_metacall(_c, _id, _a);
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
void Engine::AudioListener::signalThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
