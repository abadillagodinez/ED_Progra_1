/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Primer_Proyecto_Programado/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_btnQuick_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "on_btnRandom_clicked"
QT_MOC_LITERAL(4, 53, 29), // "on_cbxDato_currentTextChanged"
QT_MOC_LITERAL(5, 83, 4), // "arg1"
QT_MOC_LITERAL(6, 88, 25), // "on_sbxRango1_valueChanged"
QT_MOC_LITERAL(7, 114, 25), // "on_sbxRango2_valueChanged"
QT_MOC_LITERAL(8, 140, 19), // "on_btnShell_clicked"
QT_MOC_LITERAL(9, 160, 23), // "on_btnInsertion_clicked"
QT_MOC_LITERAL(10, 184, 19), // "on_btnMerge_clicked"
QT_MOC_LITERAL(11, 204, 22), // "on_btnSeletion_clicked"
QT_MOC_LITERAL(12, 227, 25), // "on_btnDobleBubble_clicked"
QT_MOC_LITERAL(13, 253, 18), // "on_btnHeap_clicked"
QT_MOC_LITERAL(14, 272, 20) // "on_btnBubble_clicked"

    },
    "MainWindow\0on_btnQuick_clicked\0\0"
    "on_btnRandom_clicked\0on_cbxDato_currentTextChanged\0"
    "arg1\0on_sbxRango1_valueChanged\0"
    "on_sbxRango2_valueChanged\0on_btnShell_clicked\0"
    "on_btnInsertion_clicked\0on_btnMerge_clicked\0"
    "on_btnSeletion_clicked\0on_btnDobleBubble_clicked\0"
    "on_btnHeap_clicked\0on_btnBubble_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       6,    1,   79,    2, 0x08 /* Private */,
       7,    1,   82,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnQuick_clicked(); break;
        case 1: _t->on_btnRandom_clicked(); break;
        case 2: _t->on_cbxDato_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_sbxRango1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_sbxRango2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_btnShell_clicked(); break;
        case 6: _t->on_btnInsertion_clicked(); break;
        case 7: _t->on_btnMerge_clicked(); break;
        case 8: _t->on_btnSeletion_clicked(); break;
        case 9: _t->on_btnDobleBubble_clicked(); break;
        case 10: _t->on_btnHeap_clicked(); break;
        case 11: _t->on_btnBubble_clicked(); break;
        default: ;
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
QT_END_MOC_NAMESPACE
