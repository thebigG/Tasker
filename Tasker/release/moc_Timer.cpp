/****************************************************************************
** Meta object code from reading C++ file 'Timer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Timer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Timer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Engine__Timer_t {
    QByteArrayData data[10];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Engine__Timer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Engine__Timer_t qt_meta_stringdata_Engine__Timer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Engine::Timer"
QT_MOC_LITERAL(1, 14, 4), // "tick"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "timerStarted"
QT_MOC_LITERAL(4, 33, 9), // "stopTimer"
QT_MOC_LITERAL(5, 43, 8), // "congrats"
QT_MOC_LITERAL(6, 52, 13), // "stopTimerSlot"
QT_MOC_LITERAL(7, 66, 10), // "tickUpdate"
QT_MOC_LITERAL(8, 77, 14), // "productiveSlot"
QT_MOC_LITERAL(9, 92, 16) // "unProductiveSlot"

    },
    "Engine::Timer\0tick\0\0timerStarted\0"
    "stopTimer\0congrats\0stopTimerSlot\0"
    "tickUpdate\0productiveSlot\0unProductiveSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Engine__Timer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Engine::Timer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Timer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tick(); break;
        case 1: _t->timerStarted(); break;
        case 2: _t->stopTimer(); break;
        case 3: _t->congrats(); break;
        case 4: _t->stopTimerSlot(); break;
        case 5: _t->tickUpdate(); break;
        case 6: _t->productiveSlot(); break;
        case 7: _t->unProductiveSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Timer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Timer::tick)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Timer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Timer::timerStarted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Timer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Timer::stopTimer)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Timer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Timer::congrats)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Engine::Timer::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_Engine__Timer.data,
    qt_meta_data_Engine__Timer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Engine::Timer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Engine::Timer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Engine__Timer.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Engine::Timer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Engine::Timer::tick()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Engine::Timer::timerStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Engine::Timer::stopTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Engine::Timer::congrats()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE