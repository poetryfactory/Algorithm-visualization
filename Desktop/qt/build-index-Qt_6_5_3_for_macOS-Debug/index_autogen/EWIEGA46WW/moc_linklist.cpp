/****************************************************************************
** Meta object code from reading C++ file 'linklist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../index/linklist.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linklist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSLinkListENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSLinkListENDCLASS = QtMocHelpers::stringData(
    "LinkList",
    "on_pushButtonInit_clicked",
    "",
    "on_pushButtonClear_clicked",
    "on_pushButtonInsert_clicked",
    "on_pushButtonRandomInsert5_clicked",
    "on_pushButtonDelete_clicked",
    "on_pushButtonLocate_clicked",
    "on_horizontalSlider_valueChanged",
    "value"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLinkListENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[9];
    char stringdata1[26];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[28];
    char stringdata5[35];
    char stringdata6[28];
    char stringdata7[28];
    char stringdata8[33];
    char stringdata9[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLinkListENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLinkListENDCLASS_t qt_meta_stringdata_CLASSLinkListENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "LinkList"
        QT_MOC_LITERAL(9, 25),  // "on_pushButtonInit_clicked"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 26),  // "on_pushButtonClear_clicked"
        QT_MOC_LITERAL(63, 27),  // "on_pushButtonInsert_clicked"
        QT_MOC_LITERAL(91, 34),  // "on_pushButtonRandomInsert5_cl..."
        QT_MOC_LITERAL(126, 27),  // "on_pushButtonDelete_clicked"
        QT_MOC_LITERAL(154, 27),  // "on_pushButtonLocate_clicked"
        QT_MOC_LITERAL(182, 32),  // "on_horizontalSlider_valueChanged"
        QT_MOC_LITERAL(215, 5)   // "value"
    },
    "LinkList",
    "on_pushButtonInit_clicked",
    "",
    "on_pushButtonClear_clicked",
    "on_pushButtonInsert_clicked",
    "on_pushButtonRandomInsert5_clicked",
    "on_pushButtonDelete_clicked",
    "on_pushButtonLocate_clicked",
    "on_horizontalSlider_valueChanged",
    "value"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLinkListENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    1,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject LinkList::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSLinkListENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLinkListENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLinkListENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LinkList, std::true_type>,
        // method 'on_pushButtonInit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonClear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonInsert_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonRandomInsert5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonDelete_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonLocate_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void LinkList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LinkList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButtonInit_clicked(); break;
        case 1: _t->on_pushButtonClear_clicked(); break;
        case 2: _t->on_pushButtonInsert_clicked(); break;
        case 3: _t->on_pushButtonRandomInsert5_clicked(); break;
        case 4: _t->on_pushButtonDelete_clicked(); break;
        case 5: _t->on_pushButtonLocate_clicked(); break;
        case 6: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *LinkList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinkList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLinkListENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LinkList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
