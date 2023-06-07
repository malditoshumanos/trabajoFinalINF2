/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../pinkVSgray/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[44];
    char stringdata0[11];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[7];
    char stringdata5[7];
    char stringdata6[9];
    char stringdata7[18];
    char stringdata8[10];
    char stringdata9[7];
    char stringdata10[20];
    char stringdata11[11];
    char stringdata12[8];
    char stringdata13[15];
    char stringdata14[9];
    char stringdata15[11];
    char stringdata16[18];
    char stringdata17[16];
    char stringdata18[16];
    char stringdata19[16];
    char stringdata20[20];
    char stringdata21[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 9),  // "collision"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 7),  // "player*"
        QT_MOC_LITERAL(30, 6),  // "player"
        QT_MOC_LITERAL(37, 6),  // "props*"
        QT_MOC_LITERAL(44, 8),  // "rectItem"
        QT_MOC_LITERAL(53, 17),  // "colisionProyectil"
        QT_MOC_LITERAL(71, 9),  // "playerAct"
        QT_MOC_LITERAL(81, 6),  // "damage"
        QT_MOC_LITERAL(88, 19),  // "colisionDisparoProp"
        QT_MOC_LITERAL(108, 10),  // "propsLife*"
        QT_MOC_LITERAL(119, 7),  // "propAct"
        QT_MOC_LITERAL(127, 14),  // "colisionPickUp"
        QT_MOC_LITERAL(142, 8),  // "pickUpId"
        QT_MOC_LITERAL(151, 10),  // "updateGame"
        QT_MOC_LITERAL(162, 17),  // "collisionDetected"
        QT_MOC_LITERAL(180, 15),  // "cooldownEndedP1"
        QT_MOC_LITERAL(196, 15),  // "cooldownEndedP2"
        QT_MOC_LITERAL(212, 15),  // "disparoRecibido"
        QT_MOC_LITERAL(228, 19),  // "propDisparoRecibido"
        QT_MOC_LITERAL(248, 13)   // "recogioPickUp"
    },
    "MainWindow",
    "collision",
    "",
    "player*",
    "player",
    "props*",
    "rectItem",
    "colisionProyectil",
    "playerAct",
    "damage",
    "colisionDisparoProp",
    "propsLife*",
    "propAct",
    "colisionPickUp",
    "pickUpId",
    "updateGame",
    "collisionDetected",
    "cooldownEndedP1",
    "cooldownEndedP2",
    "disparoRecibido",
    "propDisparoRecibido",
    "recogioPickUp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   80,    2, 0x06,    1 /* Public */,
       7,    2,   85,    2, 0x06,    4 /* Public */,
      10,    2,   90,    2, 0x06,    7 /* Public */,
      13,    2,   95,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,  100,    2, 0x0a,   13 /* Public */,
      16,    2,  101,    2, 0x0a,   14 /* Public */,
      17,    0,  106,    2, 0x0a,   17 /* Public */,
      18,    0,  107,    2, 0x0a,   18 /* Public */,
      19,    2,  108,    2, 0x0a,   19 /* Public */,
      20,    2,  113,    2, 0x0a,   22 /* Public */,
      21,    2,  118,    2, 0x0a,   25 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    8,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Char,    8,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    8,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Char,    8,   14,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->collision((*reinterpret_cast< std::add_pointer_t<player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<props*>>(_a[2]))); break;
        case 1: _t->colisionProyectil((*reinterpret_cast< std::add_pointer_t<player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->colisionDisparoProp((*reinterpret_cast< std::add_pointer_t<propsLife*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->colisionPickUp((*reinterpret_cast< std::add_pointer_t<player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char>>(_a[2]))); break;
        case 4: _t->updateGame(); break;
        case 5: _t->collisionDetected((*reinterpret_cast< std::add_pointer_t<player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<props*>>(_a[2]))); break;
        case 6: _t->cooldownEndedP1(); break;
        case 7: _t->cooldownEndedP2(); break;
        case 8: _t->disparoRecibido((*reinterpret_cast< std::add_pointer_t<player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->propDisparoRecibido((*reinterpret_cast< std::add_pointer_t<propsLife*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 10: _t->recogioPickUp((*reinterpret_cast< std::add_pointer_t<player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(player * , props * );
            if (_t _q_method = &MainWindow::collision; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(player * , int );
            if (_t _q_method = &MainWindow::colisionProyectil; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(propsLife * , int );
            if (_t _q_method = &MainWindow::colisionDisparoProp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(player * , char );
            if (_t _q_method = &MainWindow::colisionPickUp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<player *, std::false_type>, QtPrivate::TypeAndForceComplete<props *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<player *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<propsLife *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<player *, std::false_type>, QtPrivate::TypeAndForceComplete<char, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<player *, std::false_type>, QtPrivate::TypeAndForceComplete<props *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<player *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<propsLife *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<player *, std::false_type>, QtPrivate::TypeAndForceComplete<char, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::collision(player * _t1, props * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::colisionProyectil(player * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::colisionDisparoProp(propsLife * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::colisionPickUp(player * _t1, char _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
