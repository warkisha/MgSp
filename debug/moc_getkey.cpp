/****************************************************************************
** Meta object code from reading C++ file 'getkey.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mgp/registration/getkey.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getkey.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_getKey_t {
    QByteArrayData data[11];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_getKey_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_getKey_t qt_meta_stringdata_getKey = {
    {
QT_MOC_LITERAL(0, 0, 6), // "getKey"
QT_MOC_LITERAL(1, 7, 11), // "signalNameK"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 22), // "on_next_Button_clicked"
QT_MOC_LITERAL(4, 43, 30), // "on_tockenchoose_Button_clicked"
QT_MOC_LITERAL(5, 74, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(6, 99, 22), // "on_back_Button_clicked"
QT_MOC_LITERAL(7, 122, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 144, 14), // "isAlphaNumeric"
QT_MOC_LITERAL(9, 159, 3), // "str"
QT_MOC_LITERAL(10, 163, 12) // "slotUserData"

    },
    "getKey\0signalNameK\0\0on_next_Button_clicked\0"
    "on_tockenchoose_Button_clicked\0"
    "on_checkBox_stateChanged\0"
    "on_back_Button_clicked\0on_pushButton_clicked\0"
    "isAlphaNumeric\0str\0slotUserData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_getKey[] = {

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
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   57,    2, 0x08 /* Private */,
       4,    0,   58,    2, 0x08 /* Private */,
       5,    0,   59,    2, 0x08 /* Private */,
       6,    0,   60,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    1,   62,    2, 0x08 /* Private */,
      10,    2,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

       0        // eod
};

void getKey::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<getKey *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalNameK((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_next_Button_clicked(); break;
        case 2: _t->on_tockenchoose_Button_clicked(); break;
        case 3: _t->on_checkBox_stateChanged(); break;
        case 4: _t->on_back_Button_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: { bool _r = _t->isAlphaNumeric((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->slotUserData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (getKey::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&getKey::signalNameK)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject getKey::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_getKey.data,
    qt_meta_data_getKey,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *getKey::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *getKey::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_getKey.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int getKey::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void getKey::signalNameK(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
