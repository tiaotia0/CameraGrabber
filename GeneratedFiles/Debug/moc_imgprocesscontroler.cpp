/****************************************************************************
** Meta object code from reading C++ file 'imgprocesscontroler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imgprocesscontroler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgprocesscontroler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageDisplayControler_t {
    QByteArrayData data[6];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageDisplayControler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageDisplayControler_t qt_meta_stringdata_ImageDisplayControler = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ImageDisplayControler"
QT_MOC_LITERAL(1, 22, 14), // "sendCalibImage"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 7), // "Img_ptr"
QT_MOC_LITERAL(4, 46, 16), // "sendDisplayImage"
QT_MOC_LITERAL(5, 63, 4) // "qImg"

    },
    "ImageDisplayControler\0sendCalibImage\0"
    "\0Img_ptr\0sendDisplayImage\0qImg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageDisplayControler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void, QMetaType::QImage,    5,

       0        // eod
};

void ImageDisplayControler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageDisplayControler *_t = static_cast<ImageDisplayControler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCalibImage((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 1: _t->sendDisplayImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageDisplayControler::*_t)(void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageDisplayControler::sendCalibImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ImageDisplayControler::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageDisplayControler::sendDisplayImage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ImageDisplayControler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageDisplayControler.data,
      qt_meta_data_ImageDisplayControler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageDisplayControler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageDisplayControler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageDisplayControler.stringdata0))
        return static_cast<void*>(const_cast< ImageDisplayControler*>(this));
    if (!strcmp(_clname, "Base_ImageContrler"))
        return static_cast< Base_ImageContrler*>(const_cast< ImageDisplayControler*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageDisplayControler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ImageDisplayControler::sendCalibImage(void * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageDisplayControler::sendDisplayImage(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_CameraCalibrateControler_t {
    QByteArrayData data[11];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraCalibrateControler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraCalibrateControler_t qt_meta_stringdata_CameraCalibrateControler = {
    {
QT_MOC_LITERAL(0, 0, 24), // "CameraCalibrateControler"
QT_MOC_LITERAL(1, 25, 18), // "sendLeftCalibImage"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 4), // "qimg"
QT_MOC_LITERAL(4, 50, 19), // "sendRightCalibImage"
QT_MOC_LITERAL(5, 70, 19), // "sendCalibrateStatus"
QT_MOC_LITERAL(6, 90, 16), // "QVector<QString>"
QT_MOC_LITERAL(7, 107, 4), // "Qvec"
QT_MOC_LITERAL(8, 112, 16), // "recieveLeftImage"
QT_MOC_LITERAL(9, 129, 7), // "img_ptr"
QT_MOC_LITERAL(10, 137, 17) // "recieveRightImage"

    },
    "CameraCalibrateControler\0sendLeftCalibImage\0"
    "\0qimg\0sendRightCalibImage\0sendCalibrateStatus\0"
    "QVector<QString>\0Qvec\0recieveLeftImage\0"
    "img_ptr\0recieveRightImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraCalibrateControler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   48,    2, 0x08 /* Private */,
      10,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar,    9,
    QMetaType::Void, QMetaType::VoidStar,    9,

       0        // eod
};

void CameraCalibrateControler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraCalibrateControler *_t = static_cast<CameraCalibrateControler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendLeftCalibImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->sendRightCalibImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->sendCalibrateStatus((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 3: _t->recieveLeftImage((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 4: _t->recieveRightImage((*reinterpret_cast< void*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraCalibrateControler::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraCalibrateControler::sendLeftCalibImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CameraCalibrateControler::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraCalibrateControler::sendRightCalibImage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CameraCalibrateControler::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraCalibrateControler::sendCalibrateStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CameraCalibrateControler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraCalibrateControler.data,
      qt_meta_data_CameraCalibrateControler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraCalibrateControler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraCalibrateControler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraCalibrateControler.stringdata0))
        return static_cast<void*>(const_cast< CameraCalibrateControler*>(this));
    if (!strcmp(_clname, "CameraCalibrator"))
        return static_cast< CameraCalibrator*>(const_cast< CameraCalibrateControler*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraCalibrateControler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CameraCalibrateControler::sendLeftCalibImage(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraCalibrateControler::sendRightCalibImage(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CameraCalibrateControler::sendCalibrateStatus(QVector<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
