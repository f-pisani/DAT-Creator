/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/MainWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[384];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "DAT_Loaded"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "DAT_Modified"
QT_MOC_LITERAL(4, 36, 10), // "DAT_Closed"
QT_MOC_LITERAL(5, 47, 19), // "updateTreeViewModel"
QT_MOC_LITERAL(6, 67, 9), // "s_addFile"
QT_MOC_LITERAL(7, 77, 17), // "s_extractSelected"
QT_MOC_LITERAL(8, 95, 16), // "s_renameSelected"
QT_MOC_LITERAL(9, 112, 16), // "s_removeSelected"
QT_MOC_LITERAL(10, 129, 13), // "updateMenuBar"
QT_MOC_LITERAL(11, 143, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(12, 166, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(13, 190, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(14, 214, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(15, 241, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(16, 266, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(17, 290, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(18, 315, 38), // "on_treeView_customContextMenu..."
QT_MOC_LITERAL(19, 354, 3), // "pos"
QT_MOC_LITERAL(20, 358, 10), // "closeEvent"
QT_MOC_LITERAL(21, 369, 12), // "QCloseEvent*"
QT_MOC_LITERAL(22, 382, 1) // "e"

    },
    "MainWindow\0DAT_Loaded\0\0DAT_Modified\0"
    "DAT_Closed\0updateTreeViewModel\0s_addFile\0"
    "s_extractSelected\0s_renameSelected\0"
    "s_removeSelected\0updateMenuBar\0"
    "on_actionNew_triggered\0on_actionLoad_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionQuit_triggered\0"
    "on_actionAbout_triggered\0"
    "on_treeView_customContextMenuRequested\0"
    "pos\0closeEvent\0QCloseEvent*\0e"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    1,  120,    2, 0x08 /* Private */,
      20,    1,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   19,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DAT_Loaded(); break;
        case 1: _t->DAT_Modified(); break;
        case 2: _t->DAT_Closed(); break;
        case 3: _t->updateTreeViewModel(); break;
        case 4: _t->s_addFile(); break;
        case 5: _t->s_extractSelected(); break;
        case 6: _t->s_renameSelected(); break;
        case 7: _t->s_removeSelected(); break;
        case 8: _t->updateMenuBar(); break;
        case 9: _t->on_actionNew_triggered(); break;
        case 10: _t->on_actionLoad_triggered(); break;
        case 11: _t->on_actionSave_triggered(); break;
        case 12: _t->on_actionSave_As_triggered(); break;
        case 13: _t->on_actionClose_triggered(); break;
        case 14: _t->on_actionQuit_triggered(); break;
        case 15: _t->on_actionAbout_triggered(); break;
        case 16: _t->on_treeView_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 17: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::DAT_Loaded)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::DAT_Modified)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::DAT_Closed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::DAT_Loaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::DAT_Modified()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::DAT_Closed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
