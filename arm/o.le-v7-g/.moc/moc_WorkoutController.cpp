/****************************************************************************
** Meta object code from reading C++ file 'WorkoutController.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/WorkoutController.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WorkoutController.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gymme__WorkoutController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       7,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x05,
      49,   25,   25,   25, 0x05,
      75,   25,   25,   25, 0x05,
      89,   25,   25,   25, 0x05,
     108,   25,   25,   25, 0x05,
     128,   25,   25,   25, 0x05,
     146,   25,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
     163,   25,   25,   25, 0x08,

 // methods: signature, parameters, type, tag, flags
     190,   25,  185,   25, 0x02,
     201,   25,   25,   25, 0x02,
     209,   25,   25,   25, 0x02,
     223,   25,   25,   25, 0x02,
     232,   25,   25,   25, 0x02,
     239,   25,   25,   25, 0x02,
     251,   25,   25,   25, 0x02,
     262,   25,   25,   25, 0x02,

 // properties: name, type, flags
     281,  277, 0x02495001,
     295,  277, 0x02495001,
     320,  312, 0x0a495001,
     332,  312, 0x0a495001,
     342,  312, 0x0a495001,
     353,  312, 0x0a495001,
     369,  185, 0x01495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

       0        // eod
};

static const char qt_meta_stringdata_gymme__WorkoutController[] = {
    "gymme::WorkoutController\0\0"
    "exerciseCountChanged()\0exerciseSetCountChanged()\0"
    "timeChanged()\0totalTimeChanged()\0"
    "bufferTimeChanged()\0activityChanged()\0"
    "nowWastingTime()\0timerIntervalPassed()\0"
    "bool\0isActive()\0start()\0togglePause()\0"
    "buffer()\0stop()\0startRest()\0stopRest()\0"
    "nextExercise()\0int\0exerciseCount\0"
    "exerciseSetCount\0QString\0currentTime\0"
    "totalTime\0bufferTime\0currentActivity\0"
    "isWastingTime\0"
};

void gymme::WorkoutController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WorkoutController *_t = static_cast<WorkoutController *>(_o);
        switch (_id) {
        case 0: _t->exerciseCountChanged(); break;
        case 1: _t->exerciseSetCountChanged(); break;
        case 2: _t->timeChanged(); break;
        case 3: _t->totalTimeChanged(); break;
        case 4: _t->bufferTimeChanged(); break;
        case 5: _t->activityChanged(); break;
        case 6: _t->nowWastingTime(); break;
        case 7: _t->timerIntervalPassed(); break;
        case 8: { bool _r = _t->isActive();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->start(); break;
        case 10: _t->togglePause(); break;
        case 11: _t->buffer(); break;
        case 12: _t->stop(); break;
        case 13: _t->startRest(); break;
        case 14: _t->stopRest(); break;
        case 15: _t->nextExercise(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData gymme::WorkoutController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject gymme::WorkoutController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_gymme__WorkoutController,
      qt_meta_data_gymme__WorkoutController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gymme::WorkoutController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gymme::WorkoutController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gymme::WorkoutController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gymme__WorkoutController))
        return static_cast<void*>(const_cast< WorkoutController*>(this));
    return QObject::qt_metacast(_clname);
}

int gymme::WorkoutController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = exerciseCount(); break;
        case 1: *reinterpret_cast< int*>(_v) = exerciseSetCount(); break;
        case 2: *reinterpret_cast< QString*>(_v) = currentTimeAsQString(); break;
        case 3: *reinterpret_cast< QString*>(_v) = totalTimeAsQString(); break;
        case 4: *reinterpret_cast< QString*>(_v) = bufferTimeAsQString(); break;
        case 5: *reinterpret_cast< QString*>(_v) = currentActivity(); break;
        case 6: *reinterpret_cast< bool*>(_v) = isWastingTime(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void gymme::WorkoutController::exerciseCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void gymme::WorkoutController::exerciseSetCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void gymme::WorkoutController::timeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void gymme::WorkoutController::totalTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void gymme::WorkoutController::bufferTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void gymme::WorkoutController::activityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void gymme::WorkoutController::nowWastingTime()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
