/****************************************************************************
** Meta object code from reading C++ file 'wy_vector.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../index+wy/wy_vector.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wy_vector.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMyRectItemENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMyRectItemENDCLASS = QtMocHelpers::stringData(
    "MyRectItem",
    "addelem",
    "",
    "modifyelem",
    "deleteelem"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMyRectItemENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[11];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMyRectItemENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMyRectItemENDCLASS_t qt_meta_stringdata_CLASSMyRectItemENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MyRectItem"
        QT_MOC_LITERAL(11, 7),  // "addelem"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 10),  // "modifyelem"
        QT_MOC_LITERAL(31, 10)   // "deleteelem"
    },
    "MyRectItem",
    "addelem",
    "",
    "modifyelem",
    "deleteelem"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMyRectItemENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    0,   33,    2, 0x0a,    2 /* Public */,
       4,    0,   34,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyRectItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSMyRectItemENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMyRectItemENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMyRectItemENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyRectItem, std::true_type>,
        // method 'addelem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'modifyelem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteelem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MyRectItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyRectItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addelem(); break;
        case 1: _t->modifyelem(); break;
        case 2: _t->deleteelem(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MyRectItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyRectItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMyRectItemENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return QObject::qt_metacast(_clname);
}

int MyRectItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMyDataStructureENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMyDataStructureENDCLASS = QtMocHelpers::stringData(
    "MyDataStructure"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMyDataStructureENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMyDataStructureENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMyDataStructureENDCLASS_t qt_meta_stringdata_CLASSMyDataStructureENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15)   // "MyDataStructure"
    },
    "MyDataStructure"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMyDataStructureENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject MyDataStructure::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSMyDataStructureENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMyDataStructureENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMyDataStructureENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyDataStructure, std::true_type>
    >,
    nullptr
} };

void MyDataStructure::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *MyDataStructure::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyDataStructure::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMyDataStructureENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyDataStructure::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSceneHolderENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSceneHolderENDCLASS = QtMocHelpers::stringData(
    "SceneHolder",
    "vec_add",
    "",
    "item_index",
    "num",
    "loc",
    "update",
    "vec_remove",
    "vec_modify",
    "vec_hilight",
    "color",
    "vec_lolight",
    "new_item",
    "MyVector*",
    "MyStack*",
    "addarray",
    "addstack",
    "pushelem",
    "sort",
    "speedup",
    "pushtostack"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSceneHolderENDCLASS_t {
    uint offsetsAndSizes[42];
    char stringdata0[12];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[4];
    char stringdata5[4];
    char stringdata6[7];
    char stringdata7[11];
    char stringdata8[11];
    char stringdata9[12];
    char stringdata10[6];
    char stringdata11[12];
    char stringdata12[9];
    char stringdata13[10];
    char stringdata14[9];
    char stringdata15[9];
    char stringdata16[9];
    char stringdata17[9];
    char stringdata18[5];
    char stringdata19[8];
    char stringdata20[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSceneHolderENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSceneHolderENDCLASS_t qt_meta_stringdata_CLASSSceneHolderENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "SceneHolder"
        QT_MOC_LITERAL(12, 7),  // "vec_add"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 10),  // "item_index"
        QT_MOC_LITERAL(32, 3),  // "num"
        QT_MOC_LITERAL(36, 3),  // "loc"
        QT_MOC_LITERAL(40, 6),  // "update"
        QT_MOC_LITERAL(47, 10),  // "vec_remove"
        QT_MOC_LITERAL(58, 10),  // "vec_modify"
        QT_MOC_LITERAL(69, 11),  // "vec_hilight"
        QT_MOC_LITERAL(81, 5),  // "color"
        QT_MOC_LITERAL(87, 11),  // "vec_lolight"
        QT_MOC_LITERAL(99, 8),  // "new_item"
        QT_MOC_LITERAL(108, 9),  // "MyVector*"
        QT_MOC_LITERAL(118, 8),  // "MyStack*"
        QT_MOC_LITERAL(127, 8),  // "addarray"
        QT_MOC_LITERAL(136, 8),  // "addstack"
        QT_MOC_LITERAL(145, 8),  // "pushelem"
        QT_MOC_LITERAL(154, 4),  // "sort"
        QT_MOC_LITERAL(159, 7),  // "speedup"
        QT_MOC_LITERAL(167, 11)   // "pushtostack"
    },
    "SceneHolder",
    "vec_add",
    "",
    "item_index",
    "num",
    "loc",
    "update",
    "vec_remove",
    "vec_modify",
    "vec_hilight",
    "color",
    "vec_lolight",
    "new_item",
    "MyVector*",
    "MyStack*",
    "addarray",
    "addstack",
    "pushelem",
    "sort",
    "speedup",
    "pushtostack"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSceneHolderENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   98,    2, 0x0a,    1 /* Public */,
       6,    0,  105,    2, 0x0a,    5 /* Public */,
       7,    2,  106,    2, 0x0a,    6 /* Public */,
       8,    3,  111,    2, 0x0a,    9 /* Public */,
       9,    3,  118,    2, 0x0a,   13 /* Public */,
      11,    2,  125,    2, 0x0a,   17 /* Public */,
      12,    1,  130,    2, 0x0a,   20 /* Public */,
      12,    1,  133,    2, 0x0a,   22 /* Public */,
      15,    0,  136,    2, 0x0a,   24 /* Public */,
      16,    0,  137,    2, 0x0a,   25 /* Public */,
      17,    0,  138,    2, 0x0a,   26 /* Public */,
      18,    0,  139,    2, 0x0a,   27 /* Public */,
      19,    0,  140,    2, 0x0a,   28 /* Public */,
      20,    0,  141,    2, 0x0a,   29 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    5,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor,    3,    5,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    5,
    QMetaType::Int, 0x80000000 | 13,    2,
    QMetaType::Int, 0x80000000 | 14,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SceneHolder::staticMetaObject = { {
    QMetaObject::SuperData::link<sonwindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSSceneHolderENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSceneHolderENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSceneHolderENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SceneHolder, std::true_type>,
        // method 'vec_add'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'update'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'vec_remove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'vec_modify'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'vec_hilight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>,
        // method 'vec_lolight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'new_item'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<MyVector *, std::false_type>,
        // method 'new_item'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<MyStack *, std::false_type>,
        // method 'addarray'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addstack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushelem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'speedup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushtostack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SceneHolder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SceneHolder *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->vec_add((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->update(); break;
        case 2: _t->vec_remove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->vec_modify((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->vec_hilight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 5: _t->vec_lolight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: { int _r = _t->new_item((*reinterpret_cast< std::add_pointer_t<MyVector*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->new_item((*reinterpret_cast< std::add_pointer_t<MyStack*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->addarray(); break;
        case 9: _t->addstack(); break;
        case 10: _t->pushelem(); break;
        case 11: _t->sort(); break;
        case 12: _t->speedup(); break;
        case 13: _t->pushtostack(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MyVector* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MyStack* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *SceneHolder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SceneHolder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSceneHolderENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return sonwindow::qt_metacast(_clname);
}

int SceneHolder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = sonwindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMyVectorENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMyVectorENDCLASS = QtMocHelpers::stringData(
    "MyVector",
    "getindex",
    "",
    "sigupdate",
    "workDone",
    "add",
    "item_index",
    "num",
    "mysize",
    "remove",
    "loc",
    "hilight",
    "color",
    "lolight",
    "modifi",
    "acceptindex",
    "index"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMyVectorENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[9];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[11];
    char stringdata7[4];
    char stringdata8[7];
    char stringdata9[7];
    char stringdata10[4];
    char stringdata11[8];
    char stringdata12[6];
    char stringdata13[8];
    char stringdata14[7];
    char stringdata15[12];
    char stringdata16[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMyVectorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMyVectorENDCLASS_t qt_meta_stringdata_CLASSMyVectorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "MyVector"
        QT_MOC_LITERAL(9, 8),  // "getindex"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 9),  // "sigupdate"
        QT_MOC_LITERAL(29, 8),  // "workDone"
        QT_MOC_LITERAL(38, 3),  // "add"
        QT_MOC_LITERAL(42, 10),  // "item_index"
        QT_MOC_LITERAL(53, 3),  // "num"
        QT_MOC_LITERAL(57, 6),  // "mysize"
        QT_MOC_LITERAL(64, 6),  // "remove"
        QT_MOC_LITERAL(71, 3),  // "loc"
        QT_MOC_LITERAL(75, 7),  // "hilight"
        QT_MOC_LITERAL(83, 5),  // "color"
        QT_MOC_LITERAL(89, 7),  // "lolight"
        QT_MOC_LITERAL(97, 6),  // "modifi"
        QT_MOC_LITERAL(104, 11),  // "acceptindex"
        QT_MOC_LITERAL(116, 5)   // "index"
    },
    "MyVector",
    "getindex",
    "",
    "sigupdate",
    "workDone",
    "add",
    "item_index",
    "num",
    "mysize",
    "remove",
    "loc",
    "hilight",
    "color",
    "lolight",
    "modifi",
    "acceptindex",
    "index"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMyVectorENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    0,   69,    2, 0x06,    2 /* Public */,
       4,    0,   70,    2, 0x06,    3 /* Public */,
       5,    3,   71,    2, 0x06,    4 /* Public */,
       9,    2,   78,    2, 0x06,    8 /* Public */,
      11,    3,   83,    2, 0x06,   11 /* Public */,
      13,    2,   90,    2, 0x06,   15 /* Public */,
      14,    3,   95,    2, 0x06,   18 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    1,  102,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor,    6,   10,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,   10,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyVector::staticMetaObject = { {
    QMetaObject::SuperData::link<MyDataStructure::staticMetaObject>(),
    qt_meta_stringdata_CLASSMyVectorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMyVectorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMyVectorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyVector, std::true_type>,
        // method 'getindex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sigupdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'workDone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'add'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'remove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'hilight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>,
        // method 'lolight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'modifi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'acceptindex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MyVector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyVector *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getindex(); break;
        case 1: _t->sigupdate(); break;
        case 2: _t->workDone(); break;
        case 3: _t->add((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->remove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->hilight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 6: _t->lolight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->modifi((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->acceptindex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyVector::*)();
            if (_t _q_method = &MyVector::getindex; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyVector::*)();
            if (_t _q_method = &MyVector::sigupdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyVector::*)();
            if (_t _q_method = &MyVector::workDone; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyVector::*)(int , int , int );
            if (_t _q_method = &MyVector::add; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyVector::*)(int , int );
            if (_t _q_method = &MyVector::remove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyVector::*)(int , int , QColor );
            if (_t _q_method = &MyVector::hilight; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MyVector::*)(int , int );
            if (_t _q_method = &MyVector::lolight; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MyVector::*)(int , int , int );
            if (_t _q_method = &MyVector::modifi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *MyVector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyVector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMyVectorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return MyDataStructure::qt_metacast(_clname);
}

int MyVector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyDataStructure::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyVector::getindex()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyVector::sigupdate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyVector::workDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyVector::add(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyVector::remove(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyVector::hilight(int _t1, int _t2, QColor _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyVector::lolight(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyVector::modifi(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMyStackENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMyStackENDCLASS = QtMocHelpers::stringData(
    "MyStack"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMyStackENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMyStackENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMyStackENDCLASS_t qt_meta_stringdata_CLASSMyStackENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7)   // "MyStack"
    },
    "MyStack"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMyStackENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject MyStack::staticMetaObject = { {
    QMetaObject::SuperData::link<MyVector::staticMetaObject>(),
    qt_meta_stringdata_CLASSMyStackENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMyStackENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMyStackENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyStack, std::true_type>
    >,
    nullptr
} };

void MyStack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *MyStack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyStack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMyStackENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return MyVector::qt_metacast(_clname);
}

int MyStack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyVector::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
