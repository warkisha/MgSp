/****************************************************************************
** Meta object code from reading C++ file 'eventlog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mgp/mainDialog/EventLog/eventlog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventlog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventLog_t {
    QByteArrayData data[11];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EventLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EventLog_t qt_meta_stringdata_EventLog = {
    {
QT_MOC_LITERAL(0, 0, 8), // "EventLog"
QT_MOC_LITERAL(1, 9, 9), // "updatePsw"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 42, 29), // "on_setting_pushButton_clicked"
QT_MOC_LITERAL(5, 72, 30), // "on_closeSetting_Button_clicked"
QT_MOC_LITERAL(6, 103, 29), // "on_deletMainAc_Button_clicked"
QT_MOC_LITERAL(7, 133, 28), // "on_changeMain_Button_clicked"
QT_MOC_LITERAL(8, 162, 33), // "on_change_MainAc_Button_2_cli..."
QT_MOC_LITERAL(9, 196, 32), // "on_closeChangePsw_Button_clicked"
QT_MOC_LITERAL(10, 229, 12) // "slotUserInfo"

    },
    "EventLog\0updatePsw\0\0on_pushButton_clicked\0"
    "on_setting_pushButton_clicked\0"
    "on_closeSetting_Button_clicked\0"
    "on_deletMainAc_Button_clicked\0"
    "on_changeMain_Button_clicked\0"
    "on_change_MainAc_Button_2_clicked\0"
    "on_closeChangePsw_Button_clicked\0"
    "slotUserInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   62,    2, 0x08 /* Private */,
       4,    0,   63,    2, 0x08 /* Private */,
       5,    0,   64,    2, 0x08 /* Private */,
       6,    0,   65,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void EventLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventLog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePsw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_setting_pushButton_clicked(); break;
        case 3: _t->on_closeSetting_Button_clicked(); break;
        case 4: _t->on_deletMainAc_Button_clicked(); break;
        case 5: _t->on_changeMain_Button_clicked(); break;
        case 6: _t->on_change_MainAc_Button_2_clicked(); break;
        case 7: _t->on_closeChangePsw_Button_clicked(); break;
        case 8: _t->slotUserInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EventLog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EventLog::updatePsw)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EventLog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_EventLog.data,
    qt_meta_data_EventLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EventLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventLog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EventLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void EventLog::updatePsw(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
