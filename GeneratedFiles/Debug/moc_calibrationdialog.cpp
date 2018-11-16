/****************************************************************************
** Meta object code from reading C++ file 'calibrationdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../calibrationdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibrationdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalibDialog_t {
    QByteArrayData data[9];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalibDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalibDialog_t qt_meta_stringdata_CalibDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CalibDialog"
QT_MOC_LITERAL(1, 12, 28), // "on_calibration_close_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 16), // "showCalibImage_1"
QT_MOC_LITERAL(4, 59, 4), // "qImg"
QT_MOC_LITERAL(5, 64, 16), // "showCalibImage_2"
QT_MOC_LITERAL(6, 81, 15), // "showCalibStatus"
QT_MOC_LITERAL(7, 97, 16), // "QVector<QString>"
QT_MOC_LITERAL(8, 114, 12) // "calib_status"

    },
    "CalibDialog\0on_calibration_close_clicked\0"
    "\0showCalibImage_1\0qImg\0showCalibImage_2\0"
    "showCalibStatus\0QVector<QString>\0"
    "calib_status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalibDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       5,    1,   38,    2, 0x08 /* Private */,
       6,    1,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    4,
    QMetaType::Void, QMetaType::QImage,    4,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void CalibDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CalibDialog *_t = static_cast<CalibDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_calibration_close_clicked(); break;
        case 1: _t->showCalibImage_1((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->showCalibImage_2((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->showCalibStatus((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    }
}

const QMetaObject CalibDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CalibDialog.data,
      qt_meta_data_CalibDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CalibDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalibDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CalibDialog.stringdata0))
        return static_cast<void*>(const_cast< CalibDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CalibDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_CaliParaSetDialog_t {
    QByteArrayData data[6];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CaliParaSetDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CaliParaSetDialog_t qt_meta_stringdata_CaliParaSetDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CaliParaSetDialog"
QT_MOC_LITERAL(1, 18, 17), // "sendCaliParameter"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "CaliParameter"
QT_MOC_LITERAL(4, 51, 9), // "cali_para"
QT_MOC_LITERAL(5, 61, 23) // "on_cali_set_btn_clicked"

    },
    "CaliParaSetDialog\0sendCaliParameter\0"
    "\0CaliParameter\0cali_para\0"
    "on_cali_set_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaliParaSetDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CaliParaSetDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CaliParaSetDialog *_t = static_cast<CaliParaSetDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCaliParameter((*reinterpret_cast< CaliParameter(*)>(_a[1]))); break;
        case 1: _t->on_cali_set_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CaliParameter >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CaliParaSetDialog::*_t)(CaliParameter );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CaliParaSetDialog::sendCaliParameter)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CaliParaSetDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CaliParaSetDialog.data,
      qt_meta_data_CaliParaSetDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CaliParaSetDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaliParaSetDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CaliParaSetDialog.stringdata0))
        return static_cast<void*>(const_cast< CaliParaSetDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CaliParaSetDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CaliParaSetDialog::sendCaliParameter(CaliParameter _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
