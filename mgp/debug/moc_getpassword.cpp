/****************************************************************************
** Meta object code from reading C++ file 'getpassword.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../registration/getpassword.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getpassword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_getPassword_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_getPassword_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_getPassword_t qt_meta_stringdata_getPassword = {
    {
QT_MOC_LITERAL(0, 0, 11), // "getPassword"
QT_MOC_LITERAL(1, 12, 14), // "signalUserData"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 22), // "on_next_Button_clicked"
QT_MOC_LITERAL(4, 51, 22), // "on_back_Button_clicked"
QT_MOC_LITERAL(5, 74, 25), // "on_lookpsw_Button_clicked"
QT_MOC_LITERAL(6, 100, 8), // "slotName"
QT_MOC_LITERAL(7, 109, 9), // "slotNameK"
QT_MOC_LITERAL(8, 119, 4), // "hide"
QT_MOC_LITERAL(9, 124, 5) // "error"

    },
    "getPassword\0signalUserData\0\0"
    "on_next_Button_clicked\0on_back_Button_clicked\0"
    "on_lookpsw_Button_clicked\0slotName\0"
    "slotNameK\0hide\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_getPassword[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   59,    2, 0x08 /* Private */,
       4,    0,   60,    2, 0x08 /* Private */,
       5,    0,   61,    2, 0x08 /* Private */,
       6,    1,   62,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       8,    0,   68,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void getPassword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<getPassword *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUserData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_next_Button_clicked(); break;
        case 2: _t->on_back_Button_clicked(); break;
        case 3: _t->on_lookpsw_Button_clicked(); break;
        case 4: _t->slotName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slotNameK((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->hide(); break;
        case 7: _t->error(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (getPassword::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&getPassword::signalUserData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject getPassword::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_getPassword.data,
    qt_meta_data_getPassword,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *getPassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *getPassword::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_getPassword.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int getPassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void getPassword::signalUserData(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
