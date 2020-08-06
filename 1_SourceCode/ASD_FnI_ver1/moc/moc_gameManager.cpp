/****************************************************************************
** Meta object code from reading C++ file 'gameManager.h'
**
** Created: Sat Sep 14 13:45:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/gameManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gameManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      28,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   12,   12,   12, 0x0a,
      54,   12,   12,   12, 0x0a,
      64,   12,   12,   12, 0x0a,
      75,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_gameManager[] = {
    "gameManager\0\0updateShield()\0updateScore()\0"
    "exit_game()\0setPlay()\0setPause()\0"
    "setResume()\0"
};

void gameManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        gameManager *_t = static_cast<gameManager *>(_o);
        switch (_id) {
        case 0: _t->updateShield(); break;
        case 1: _t->updateScore(); break;
        case 2: _t->exit_game(); break;
        case 3: _t->setPlay(); break;
        case 4: _t->setPause(); break;
        case 5: _t->setResume(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData gameManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject gameManager::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_gameManager,
      qt_meta_data_gameManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gameManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gameManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gameManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gameManager))
        return static_cast<void*>(const_cast< gameManager*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int gameManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void gameManager::updateShield()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void gameManager::updateScore()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
