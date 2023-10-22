/****************************************************************************
** Meta object code from reading C++ file 'sonwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../index+wy/sonwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sonwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSsonwindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSsonwindowENDCLASS = QtMocHelpers::stringData(
    "sonwindow",
    "bt1",
    "",
    "bt2",
    "bt3",
    "bt4",
    "bt5",
    "bt6"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSsonwindowENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[10];
    char stringdata1[4];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[4];
    char stringdata5[4];
    char stringdata6[4];
    char stringdata7[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSsonwindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSsonwindowENDCLASS_t qt_meta_stringdata_CLASSsonwindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "sonwindow"
        QT_MOC_LITERAL(10, 3),  // "bt1"
        QT_MOC_LITERAL(14, 0),  // ""
        QT_MOC_LITERAL(15, 3),  // "bt2"
        QT_MOC_LITERAL(19, 3),  // "bt3"
        QT_MOC_LITERAL(23, 3),  // "bt4"
        QT_MOC_LITERAL(27, 3),  // "bt5"
        QT_MOC_LITERAL(31, 3)   // "bt6"
    },
    "sonwindow",
    "bt1",
    "",
    "bt2",
    "bt3",
    "bt4",
    "bt5",
    "bt6"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSsonwindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,
       5,    0,   53,    2, 0x06,    4 /* Public */,
       6,    0,   54,    2, 0x06,    5 /* Public */,
       7,    0,   55,    2, 0x06,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject sonwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSsonwindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSsonwindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSsonwindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<sonwindow, std::true_type>,
        // method 'bt1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bt2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bt3'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bt4'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bt5'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bt6'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void sonwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<sonwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->bt1(); break;
        case 1: _t->bt2(); break;
        case 2: _t->bt3(); break;
        case 3: _t->bt4(); break;
        case 4: _t->bt5(); break;
        case 5: _t->bt6(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (sonwindow::*)();
            if (_t _q_method = &sonwindow::bt1; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (sonwindow::*)();
            if (_t _q_method = &sonwindow::bt2; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (sonwindow::*)();
            if (_t _q_method = &sonwindow::bt3; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (sonwindow::*)();
            if (_t _q_method = &sonwindow::bt4; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (sonwindow::*)();
            if (_t _q_method = &sonwindow::bt5; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (sonwindow::*)();
            if (_t _q_method = &sonwindow::bt6; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *sonwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sonwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSsonwindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int sonwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void sonwindow::bt1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void sonwindow::bt2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void sonwindow::bt3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void sonwindow::bt4()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void sonwindow::bt5()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void sonwindow::bt6()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
