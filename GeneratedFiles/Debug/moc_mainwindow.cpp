/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "on_set_1_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "on_set_2_clicked"
QT_MOC_LITERAL(4, 46, 10), // "openEditor"
QT_MOC_LITERAL(5, 57, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 74, 4), // "item"
QT_MOC_LITERAL(7, 79, 6), // "column"
QT_MOC_LITERAL(8, 86, 11), // "closeEditor"
QT_MOC_LITERAL(9, 98, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(10, 122, 23), // "on_actionPlay_triggered"
QT_MOC_LITERAL(11, 146, 31), // "on_actionSetImagePath_triggered"
QT_MOC_LITERAL(12, 178, 31), // "on_actionSetCalibPath_triggered"
QT_MOC_LITERAL(13, 210, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(14, 234, 25), // "on_actionRecord_triggered"
QT_MOC_LITERAL(15, 260, 28), // "on_actionCalibrate_triggered"
QT_MOC_LITERAL(16, 289, 32), // "on_actionCalib_capture_triggered"
QT_MOC_LITERAL(17, 322, 11), // "showImage_1"
QT_MOC_LITERAL(18, 334, 4), // "qImg"
QT_MOC_LITERAL(19, 339, 11), // "showImage_2"
QT_MOC_LITERAL(20, 351, 20), // "receiveCaliParameter"
QT_MOC_LITERAL(21, 372, 13), // "CaliParameter"
QT_MOC_LITERAL(22, 386, 9), // "cali_para"
QT_MOC_LITERAL(23, 396, 19) // "continue_calib_func"

    },
    "MainWindow\0on_set_1_clicked\0\0"
    "on_set_2_clicked\0openEditor\0"
    "QTreeWidgetItem*\0item\0column\0closeEditor\0"
    "on_actionLoad_triggered\0on_actionPlay_triggered\0"
    "on_actionSetImagePath_triggered\0"
    "on_actionSetCalibPath_triggered\0"
    "on_actionStop_triggered\0"
    "on_actionRecord_triggered\0"
    "on_actionCalibrate_triggered\0"
    "on_actionCalib_capture_triggered\0"
    "showImage_1\0qImg\0showImage_2\0"
    "receiveCaliParameter\0CaliParameter\0"
    "cali_para\0continue_calib_func"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    2,   96,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    1,  110,    2, 0x08 /* Private */,
      19,    1,  113,    2, 0x08 /* Private */,
      20,    1,  116,    2, 0x08 /* Private */,
      23,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,   18,
    QMetaType::Void, QMetaType::QImage,   18,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_set_1_clicked(); break;
        case 1: _t->on_set_2_clicked(); break;
        case 2: _t->openEditor((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->closeEditor(); break;
        case 4: _t->on_actionLoad_triggered(); break;
        case 5: _t->on_actionPlay_triggered(); break;
        case 6: _t->on_actionSetImagePath_triggered(); break;
        case 7: _t->on_actionSetCalibPath_triggered(); break;
        case 8: _t->on_actionStop_triggered(); break;
        case 9: _t->on_actionRecord_triggered(); break;
        case 10: _t->on_actionCalibrate_triggered(); break;
        case 11: _t->on_actionCalib_capture_triggered(); break;
        case 12: _t->showImage_1((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 13: _t->showImage_2((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 14: _t->receiveCaliParameter((*reinterpret_cast< CaliParameter(*)>(_a[1]))); break;
        case 15: _t->continue_calib_func(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CaliParameter >(); break;
            }
            break;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
