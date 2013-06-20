/****************************************************************************
** Meta object code from reading C++ file 'JVlibForm.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "JVlibForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JVlibForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Save_Dialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      37,   12,   12,   12, 0x08,
      61,   12,   12,   12, 0x08,
      83,   12,   12,   12, 0x08,
     105,   12,   12,   12, 0x08,
     132,   12,   12,   12, 0x08,
     153,   12,   12,   12, 0x08,
     175,   12,   12,   12, 0x08,
     197,   12,   12,   12, 0x08,
     228,   12,   12,   12, 0x08,
     253,   12,   12,   12, 0x08,
     279,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Save_Dialog[] = {
    "Save_Dialog\0\0slotSaveDialog_accept()\0"
    "slotSaveDialog_cancel()\0slotSaveDialog_help()\0"
    "slotSave_System(bool)\0slotSave_Performance(bool)\0"
    "slotSave_Patch(bool)\0slotSave_Rhythm(bool)\0"
    "slotSave_Tuning(bool)\0"
    "slotSave_UserPerformance(bool)\0"
    "slotSave_UserPatch(bool)\0"
    "slotSave_UserRhythm(bool)\0"
    "slotSave_UserDump(bool)\0"
};

const QMetaObject Save_Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Save_Dialog,
      qt_meta_data_Save_Dialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Save_Dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Save_Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Save_Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Save_Dialog))
        return static_cast<void*>(const_cast< Save_Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Save_Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotSaveDialog_accept(); break;
        case 1: slotSaveDialog_cancel(); break;
        case 2: slotSaveDialog_help(); break;
        case 3: slotSave_System((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: slotSave_Performance((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: slotSave_Patch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: slotSave_Rhythm((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: slotSave_Tuning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: slotSave_UserPerformance((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: slotSave_UserPatch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: slotSave_UserRhythm((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: slotSave_UserDump((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
static const uint qt_meta_data_JVlibForm[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
     667,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   10,   10,   10, 0x08,
      47,   10,   42,   10, 0x08,
      54,   10,   42,   10, 0x08,
      63,   10,   10,   10, 0x08,
      71,   10,   10,   10, 0x08,
      86,   10,   10,   10, 0x08,
      96,   10,   10,   10, 0x08,
     109,   10,   10,   10, 0x08,
     123,   10,   10,   10, 0x08,
     140,   10,   10,   10, 0x08,
     158,   10,   10,   10, 0x08,
     180,   10,   10,   10, 0x08,
     211,   10,  203,   10, 0x08,
     229,   10,  203,   10, 0x08,
     242,   10,   10,   10, 0x08,
     259,   10,   10,   10, 0x08,
     277,   10,   10,   10, 0x08,
     305,   10,   10,   10, 0x08,
     327,   10,   10,   10, 0x08,
     346,   10,   10,   10, 0x08,
     393,   10,  389,   10, 0x08,
     425,   10,   10,   10, 0x08,
     461,   10,   10,   10, 0x08,
     496,   10,   10,   10, 0x08,
     540,   10,   10,   10, 0x08,
     589,   10,   10,   10, 0x08,
     639,   10,   10,   10, 0x08,
     689,   10,   10,   10, 0x08,
     741,   10,   10,   10, 0x08,
     797,   10,   10,   10, 0x08,
     845,   10,   10,   10, 0x08,
     895,   10,   10,   10, 0x08,
     929,   10,   10,   10, 0x08,
     965,   10,   10,   10, 0x08,
    1001,   10,   10,   10, 0x08,
    1033,   10,   10,   10, 0x08,
    1068,   10,   10,   10, 0x08,
    1103,   10,   10,   10, 0x08,
    1143,   10,   10,   10, 0x08,
    1188,   10,   10,   10, 0x08,
    1230,   10,   10,   10, 0x08,
    1278,   10,   10,   10, 0x08,
    1323,   10,   10,   10, 0x08,
    1367,   10,   10,   10, 0x08,
    1410,   10,   10,   10, 0x08,
    1451,   10,   10,   10, 0x08,
    1496,   10,   10,   10, 0x08,
    1535,   10,   10,   10, 0x08,
    1579,   10,   10,   10, 0x08,
    1623,   10,   10,   10, 0x08,
    1667,   10,   10,   10, 0x08,
    1711,   10,   10,   10, 0x08,
    1755,   10,   10,   10, 0x08,
    1799,   10,   10,   10, 0x08,
    1843,   10,   10,   10, 0x08,
    1887,   10,   10,   10, 0x08,
    1923,   10,   10,   10, 0x08,
    1955,   10,   10,   10, 0x08,
    1984,   10,   10,   10, 0x08,
    2021,   10,   10,   10, 0x08,
    2066,   10,   10,   10, 0x08,
    2105,   10,   10,   10, 0x08,
    2134,   10,   10,   10, 0x08,
    2177,   10,   10,   10, 0x08,
    2224,   10,   10,   10, 0x08,
    2268,   10,   10,   10, 0x08,
    2312,   10,   10,   10, 0x08,
    2355,   10,   10,   10, 0x08,
    2399,   10,   10,   10, 0x08,
    2446,   10,   10,   10, 0x08,
    2493,   10,   10,   10, 0x08,
    2538,   10,   10,   10, 0x08,
    2594,   10,   10,   10, 0x08,
    2644,   10,   10,   10, 0x08,
    2696,   10,   10,   10, 0x08,
    2731,   10,   10,   10, 0x08,
    2777,   10,   10,   10, 0x08,
    2829,   10,   10,   10, 0x08,
    2875,   10,   10,   10, 0x08,
    2919,   10,   10,   10, 0x08,
    2961,   10,   10,   10, 0x08,
    3008,   10,   10,   10, 0x08,
    3051,   10,   10,   10, 0x08,
    3095,   10,   10,   10, 0x08,
    3135,   10,   10,   10, 0x08,
    3173,   10,   10,   10, 0x08,
    3218,   10,   10,   10, 0x08,
    3263,   10,   10,   10, 0x08,
    3309,   10,   10,   10, 0x08,
    3351,   10,   10,   10, 0x08,
    3395,   10,   10,   10, 0x08,
    3439,   10,   10,   10, 0x08,
    3481,   10,   10,   10, 0x08,
    3529,   10,   10,   10, 0x08,
    3575,   10,   10,   10, 0x08,
    3614,   10,   10,   10, 0x08,
    3658,   10,   10,   10, 0x08,
    3700,   10,   10,   10, 0x08,
    3747,   10,   10,   10, 0x08,
    3790,   10,   10,   10, 0x08,
    3834,   10,   10,   10, 0x08,
    3880,   10,   10,   10, 0x08,
    3932,   10,   10,   10, 0x08,
    3972,   10,   10,   10, 0x08,
    4010,   10,   10,   10, 0x08,
    4055,   10,   10,   10, 0x08,
    4100,   10,   10,   10, 0x08,
    4146,   10,   10,   10, 0x08,
    4188,   10,   10,   10, 0x08,
    4232,   10,   10,   10, 0x08,
    4276,   10,   10,   10, 0x08,
    4318,   10,   10,   10, 0x08,
    4366,   10,   10,   10, 0x08,
    4412,   10,   10,   10, 0x08,
    4451,   10,   10,   10, 0x08,
    4495,   10,   10,   10, 0x08,
    4537,   10,   10,   10, 0x08,
    4584,   10,   10,   10, 0x08,
    4627,   10,   10,   10, 0x08,
    4671,   10,   10,   10, 0x08,
    4717,   10,   10,   10, 0x08,
    4769,   10,   10,   10, 0x08,
    4809,   10,   10,   10, 0x08,
    4847,   10,   10,   10, 0x08,
    4892,   10,   10,   10, 0x08,
    4937,   10,   10,   10, 0x08,
    4983,   10,   10,   10, 0x08,
    5025,   10,   10,   10, 0x08,
    5069,   10,   10,   10, 0x08,
    5113,   10,   10,   10, 0x08,
    5155,   10,   10,   10, 0x08,
    5203,   10,   10,   10, 0x08,
    5249,   10,   10,   10, 0x08,
    5288,   10,   10,   10, 0x08,
    5332,   10,   10,   10, 0x08,
    5374,   10,   10,   10, 0x08,
    5421,   10,   10,   10, 0x08,
    5464,   10,   10,   10, 0x08,
    5508,   10,   10,   10, 0x08,
    5554,   10,   10,   10, 0x08,
    5606,   10,   10,   10, 0x08,
    5646,   10,   10,   10, 0x08,
    5684,   10,   10,   10, 0x08,
    5729,   10,   10,   10, 0x08,
    5774,   10,   10,   10, 0x08,
    5820,   10,   10,   10, 0x08,
    5862,   10,   10,   10, 0x08,
    5906,   10,   10,   10, 0x08,
    5950,   10,   10,   10, 0x08,
    5992,   10,   10,   10, 0x08,
    6040,   10,   10,   10, 0x08,
    6086,   10,   10,   10, 0x08,
    6125,   10,   10,   10, 0x08,
    6169,   10,   10,   10, 0x08,
    6211,   10,   10,   10, 0x08,
    6258,   10,   10,   10, 0x08,
    6301,   10,   10,   10, 0x08,
    6345,   10,   10,   10, 0x08,
    6391,   10,   10,   10, 0x08,
    6443,   10,   10,   10, 0x08,
    6483,   10,   10,   10, 0x08,
    6521,   10,   10,   10, 0x08,
    6566,   10,   10,   10, 0x08,
    6611,   10,   10,   10, 0x08,
    6657,   10,   10,   10, 0x08,
    6699,   10,   10,   10, 0x08,
    6743,   10,   10,   10, 0x08,
    6787,   10,   10,   10, 0x08,
    6829,   10,   10,   10, 0x08,
    6877,   10,   10,   10, 0x08,
    6923,   10,   10,   10, 0x08,
    6962,   10,   10,   10, 0x08,
    7006,   10,   10,   10, 0x08,
    7048,   10,   10,   10, 0x08,
    7095,   10,   10,   10, 0x08,
    7138,   10,   10,   10, 0x08,
    7182,   10,   10,   10, 0x08,
    7228,   10,   10,   10, 0x08,
    7280,   10,   10,   10, 0x08,
    7320,   10,   10,   10, 0x08,
    7358,   10,   10,   10, 0x08,
    7403,   10,   10,   10, 0x08,
    7448,   10,   10,   10, 0x08,
    7494,   10,   10,   10, 0x08,
    7536,   10,   10,   10, 0x08,
    7580,   10,   10,   10, 0x08,
    7624,   10,   10,   10, 0x08,
    7666,   10,   10,   10, 0x08,
    7714,   10,   10,   10, 0x08,
    7760,   10,   10,   10, 0x08,
    7799,   10,   10,   10, 0x08,
    7843,   10,   10,   10, 0x08,
    7885,   10,   10,   10, 0x08,
    7932,   10,   10,   10, 0x08,
    7975,   10,   10,   10, 0x08,
    8019,   10,   10,   10, 0x08,
    8065,   10,   10,   10, 0x08,
    8117,   10,   10,   10, 0x08,
    8157,   10,   10,   10, 0x08,
    8195,   10,   10,   10, 0x08,
    8240,   10,   10,   10, 0x08,
    8285,   10,   10,   10, 0x08,
    8331,   10,   10,   10, 0x08,
    8373,   10,   10,   10, 0x08,
    8417,   10,   10,   10, 0x08,
    8461,   10,   10,   10, 0x08,
    8503,   10,   10,   10, 0x08,
    8551,   10,   10,   10, 0x08,
    8597,   10,   10,   10, 0x08,
    8636,   10,   10,   10, 0x08,
    8680,   10,   10,   10, 0x08,
    8722,   10,   10,   10, 0x08,
    8769,   10,   10,   10, 0x08,
    8812,   10,   10,   10, 0x08,
    8856,   10,   10,   10, 0x08,
    8902,   10,   10,   10, 0x08,
    8954,   10,   10,   10, 0x08,
    8994,   10,   10,   10, 0x08,
    9032,   10,   10,   10, 0x08,
    9077,   10,   10,   10, 0x08,
    9122,   10,   10,   10, 0x08,
    9168,   10,   10,   10, 0x08,
    9210,   10,   10,   10, 0x08,
    9254,   10,   10,   10, 0x08,
    9298,   10,   10,   10, 0x08,
    9340,   10,   10,   10, 0x08,
    9388,   10,   10,   10, 0x08,
    9434,   10,   10,   10, 0x08,
    9473,   10,   10,   10, 0x08,
    9517,   10,   10,   10, 0x08,
    9559,   10,   10,   10, 0x08,
    9606,   10,   10,   10, 0x08,
    9649,   10,   10,   10, 0x08,
    9693,   10,   10,   10, 0x08,
    9739,   10,   10,   10, 0x08,
    9791,   10,   10,   10, 0x08,
    9831,   10,   10,   10, 0x08,
    9869,   10,   10,   10, 0x08,
    9914,   10,   10,   10, 0x08,
    9959,   10,   10,   10, 0x08,
    10005,   10,   10,   10, 0x08,
    10047,   10,   10,   10, 0x08,
    10091,   10,   10,   10, 0x08,
    10135,   10,   10,   10, 0x08,
    10177,   10,   10,   10, 0x08,
    10225,   10,   10,   10, 0x08,
    10271,   10,   10,   10, 0x08,
    10310,   10,   10,   10, 0x08,
    10355,   10,   10,   10, 0x08,
    10398,   10,   10,   10, 0x08,
    10446,   10,   10,   10, 0x08,
    10490,   10,   10,   10, 0x08,
    10535,   10,   10,   10, 0x08,
    10582,   10,   10,   10, 0x08,
    10635,   10,   10,   10, 0x08,
    10676,   10,   10,   10, 0x08,
    10715,   10,   10,   10, 0x08,
    10761,   10,   10,   10, 0x08,
    10807,   10,   10,   10, 0x08,
    10854,   10,   10,   10, 0x08,
    10897,   10,   10,   10, 0x08,
    10942,   10,   10,   10, 0x08,
    10987,   10,   10,   10, 0x08,
    11030,   10,   10,   10, 0x08,
    11079,   10,   10,   10, 0x08,
    11126,   10,   10,   10, 0x08,
    11166,   10,   10,   10, 0x08,
    11211,   10,   10,   10, 0x08,
    11254,   10,   10,   10, 0x08,
    11302,   10,   10,   10, 0x08,
    11346,   10,   10,   10, 0x08,
    11391,   10,   10,   10, 0x08,
    11438,   10,   10,   10, 0x08,
    11491,   10,   10,   10, 0x08,
    11532,   10,   10,   10, 0x08,
    11571,   10,   10,   10, 0x08,
    11617,   10,   10,   10, 0x08,
    11663,   10,   10,   10, 0x08,
    11710,   10,   10,   10, 0x08,
    11753,   10,   10,   10, 0x08,
    11798,   10,   10,   10, 0x08,
    11843,   10,   10,   10, 0x08,
    11886,   10,   10,   10, 0x08,
    11935,   10,   10,   10, 0x08,
    11982,   10,   10,   10, 0x08,
    12022,   10,   10,   10, 0x08,
    12067,   10,   10,   10, 0x08,
    12110,   10,   10,   10, 0x08,
    12158,   10,   10,   10, 0x08,
    12202,   10,   10,   10, 0x08,
    12247,   10,   10,   10, 0x08,
    12294,   10,   10,   10, 0x08,
    12347,   10,   10,   10, 0x08,
    12388,   10,   10,   10, 0x08,
    12427,   10,   10,   10, 0x08,
    12473,   10,   10,   10, 0x08,
    12519,   10,   10,   10, 0x08,
    12566,   10,   10,   10, 0x08,
    12609,   10,   10,   10, 0x08,
    12654,   10,   10,   10, 0x08,
    12699,   10,   10,   10, 0x08,
    12742,   10,   10,   10, 0x08,
    12791,   10,   10,   10, 0x08,
    12838,   10,   10,   10, 0x08,
    12878,   10,   10,   10, 0x08,
    12923,   10,   10,   10, 0x08,
    12966,   10,   10,   10, 0x08,
    13014,   10,   10,   10, 0x08,
    13058,   10,   10,   10, 0x08,
    13103,   10,   10,   10, 0x08,
    13150,   10,   10,   10, 0x08,
    13203,   10,   10,   10, 0x08,
    13244,   10,   10,   10, 0x08,
    13283,   10,   10,   10, 0x08,
    13329,   10,   10,   10, 0x08,
    13375,   10,   10,   10, 0x08,
    13422,   10,   10,   10, 0x08,
    13465,   10,   10,   10, 0x08,
    13510,   10,   10,   10, 0x08,
    13555,   10,   10,   10, 0x08,
    13598,   10,   10,   10, 0x08,
    13647,   10,   10,   10, 0x08,
    13694,   10,   10,   10, 0x08,
    13734,   10,   10,   10, 0x08,
    13779,   10,   10,   10, 0x08,
    13822,   10,   10,   10, 0x08,
    13870,   10,   10,   10, 0x08,
    13914,   10,   10,   10, 0x08,
    13959,   10,   10,   10, 0x08,
    14006,   10,   10,   10, 0x08,
    14059,   10,   10,   10, 0x08,
    14100,   10,   10,   10, 0x08,
    14139,   10,   10,   10, 0x08,
    14185,   10,   10,   10, 0x08,
    14231,   10,   10,   10, 0x08,
    14278,   10,   10,   10, 0x08,
    14321,   10,   10,   10, 0x08,
    14366,   10,   10,   10, 0x08,
    14411,   10,   10,   10, 0x08,
    14454,   10,   10,   10, 0x08,
    14503,   10,   10,   10, 0x08,
    14550,   10,   10,   10, 0x08,
    14590,   10,   10,   10, 0x08,
    14635,   10,   10,   10, 0x08,
    14678,   10,   10,   10, 0x08,
    14726,   10,   10,   10, 0x08,
    14770,   10,   10,   10, 0x08,
    14815,   10,   10,   10, 0x08,
    14862,   10,   10,   10, 0x08,
    14915,   10,   10,   10, 0x08,
    14956,   10,   10,   10, 0x08,
    14995,   10,   10,   10, 0x08,
    15041,   10,   10,   10, 0x08,
    15087,   10,   10,   10, 0x08,
    15134,   10,   10,   10, 0x08,
    15177,   10,   10,   10, 0x08,
    15222,   10,   10,   10, 0x08,
    15267,   10,   10,   10, 0x08,
    15310,   10,   10,   10, 0x08,
    15359,   10,   10,   10, 0x08,
    15406,   10,   10,   10, 0x08,
    15446,   10,   10,   10, 0x08,
    15491,   10,   10,   10, 0x08,
    15534,   10,   10,   10, 0x08,
    15582,   10,   10,   10, 0x08,
    15626,   10,   10,   10, 0x08,
    15671,   10,   10,   10, 0x08,
    15718,   10,   10,   10, 0x08,
    15771,   10,   10,   10, 0x08,
    15812,   10,   10,   10, 0x08,
    15851,   10,   10,   10, 0x08,
    15897,   10,   10,   10, 0x08,
    15943,   10,   10,   10, 0x08,
    15990,   10,   10,   10, 0x08,
    16033,   10,   10,   10, 0x08,
    16078,   10,   10,   10, 0x08,
    16123,   10,   10,   10, 0x08,
    16166,   10,   10,   10, 0x08,
    16215,   10,   10,   10, 0x08,
    16262,   10,   10,   10, 0x08,
    16302,   10,   10,   10, 0x08,
    16325,   10,   10,   10, 0x08,
    16346,   10,   10,   10, 0x08,
    16368,   10,   10,   10, 0x08,
    16387,   10,   10,   10, 0x08,
    16410,   10,   10,   10, 0x08,
    16433,   10,   10,   10, 0x08,
    16457,   10,   10,   10, 0x08,
    16483,   10,   10,   10, 0x08,
    16509,   10,   10,   10, 0x08,
    16536,   10,   10,   10, 0x08,
    16563,   10,   10,   10, 0x08,
    16581,   10,   10,   10, 0x08,
    16599,   10,   10,   10, 0x08,
    16617,   10,   10,   10, 0x08,
    16635,   10,   10,   10, 0x08,
    16653,   10,   10,   10, 0x08,
    16671,   10,   10,   10, 0x08,
    16689,   10,   10,   10, 0x08,
    16707,   10,   10,   10, 0x08,
    16725,   10,   10,   10, 0x08,
    16743,   10,   10,   10, 0x08,
    16761,   10,   10,   10, 0x08,
    16779,   10,   10,   10, 0x08,
    16810,   10,   10,   10, 0x08,
    16857,   10,   10,   10, 0x08,
    16898,   10,   10,   10, 0x08,
    16935,   10,   10,   10, 0x08,
    16975,   10,   10,   10, 0x08,
    17013,   10,   10,   10, 0x08,
    17058,   10,   10,   10, 0x08,
    17107,   10,   10,   10, 0x08,
    17152,   10,   10,   10, 0x08,
    17195,   10,   10,   10, 0x08,
    17245,   10,   10,   10, 0x08,
    17298,   10,   10,   10, 0x08,
    17351,   10,   10,   10, 0x08,
    17404,   10,   10,   10, 0x08,
    17447,   10,   10,   10, 0x08,
    17491,   10,   10,   10, 0x08,
    17534,   10,   10,   10, 0x08,
    17578,   10,   10,   10, 0x08,
    17614,   10,   10,   10, 0x08,
    17650,   10,   10,   10, 0x08,
    17686,   10,   10,   10, 0x08,
    17722,   10,   10,   10, 0x08,
    17769,   10,   10,   10, 0x08,
    17813,   10,   10,   10, 0x08,
    17853,   10,   10,   10, 0x08,
    17900,   10,   10,   10, 0x08,
    17945,   10,   10,   10, 0x08,
    17990,   10,   10,   10, 0x08,
    18036,   10,   10,   10, 0x08,
    18075,   10,   10,   10, 0x08,
    18128,   10,   10,   10, 0x08,
    18172,   10,   10,   10, 0x08,
    18228,   10,   10,   10, 0x08,
    18284,   10,   10,   10, 0x08,
    18325,   10,   10,   10, 0x08,
    18386,   10,   10,   10, 0x08,
    18435,   10,   10,   10, 0x08,
    18483,   10,   10,   10, 0x08,
    18538,   10,   10,   10, 0x08,
    18590,   10,   10,   10, 0x08,
    18639,   10,   10,   10, 0x08,
    18687,   10,   10,   10, 0x08,
    18736,   10,   10,   10, 0x08,
    18788,   10,   10,   10, 0x08,
    18840,   10,   10,   10, 0x08,
    18897,   10,   10,   10, 0x08,
    18956,   10,   10,   10, 0x08,
    19015,   10,   10,   10, 0x08,
    19066,   10,   10,   10, 0x08,
    19117,   10,   10,   10, 0x08,
    19146,   10,   10,   10, 0x08,
    19187,   10,   10,   10, 0x08,
    19227,   10,   10,   10, 0x08,
    19273,   10,   10,   10, 0x08,
    19325,   10,   10,   10, 0x08,
    19377,   10,   10,   10, 0x08,
    19424,   10,   10,   10, 0x08,
    19469,   10,   10,   10, 0x08,
    19514,   10,   10,   10, 0x08,
    19559,   10,   10,   10, 0x08,
    19604,   10,   10,   10, 0x08,
    19649,   10,   10,   10, 0x08,
    19694,   10,   10,   10, 0x08,
    19739,   10,   10,   10, 0x08,
    19784,   10,   10,   10, 0x08,
    19829,   10,   10,   10, 0x08,
    19874,   10,   10,   10, 0x08,
    19919,   10,   10,   10, 0x08,
    19964,   10,   10,   10, 0x08,
    20013,   10,   10,   10, 0x08,
    20063,   10,   10,   10, 0x08,
    20107,   10,   10,   10, 0x08,
    20151,   10,   10,   10, 0x08,
    20196,   10,   10,   10, 0x08,
    20235,   10,   10,   10, 0x08,
    20283,   10,   10,   10, 0x08,
    20331,   10,   10,   10, 0x08,
    20374,   10,   10,   10, 0x08,
    20422,   10,   10,   10, 0x08,
    20465,   10,   10,   10, 0x08,
    20508,   10,   10,   10, 0x08,
    20551,   10,   10,   10, 0x08,
    20594,   10,   10,   10, 0x08,
    20637,   10,   10,   10, 0x08,
    20680,   10,   10,   10, 0x08,
    20723,   10,   10,   10, 0x08,
    20766,   10,   10,   10, 0x08,
    20809,   10,   10,   10, 0x08,
    20852,   10,   10,   10, 0x08,
    20895,   10,   10,   10, 0x08,
    20938,   10,   10,   10, 0x08,
    20981,   10,   10,   10, 0x08,
    21022,   10,   10,   10, 0x08,
    21067,   10,   10,   10, 0x08,
    21110,   10,   10,   10, 0x08,
    21143,   10,   10,   10, 0x08,
    21192,   10,   10,   10, 0x08,
    21241,   10,   10,   10, 0x08,
    21290,   10,   10,   10, 0x08,
    21339,   10,   10,   10, 0x08,
    21385,   10,   10,   10, 0x08,
    21430,   10,   10,   10, 0x08,
    21475,   10,   10,   10, 0x08,
    21521,   10,   10,   10, 0x08,
    21568,   10,   10,   10, 0x08,
    21615,   10,   10,   10, 0x08,
    21674,   10,   10,   10, 0x08,
    21733,   10,   10,   10, 0x08,
    21789,   10,   10,   10, 0x08,
    21845,   10,   10,   10, 0x08,
    21900,   10,   10,   10, 0x08,
    21956,   10,   10,   10, 0x08,
    22012,   10,   10,   10, 0x08,
    22067,   10,   10,   10, 0x08,
    22121,   10,   10,   10, 0x08,
    22161,   10,   10,   10, 0x08,
    22217,   10,   10,   10, 0x08,
    22266,   10,   10,   10, 0x08,
    22309,   10,   10,   10, 0x08,
    22358,   10,   10,   10, 0x08,
    22407,   10,   10,   10, 0x08,
    22449,   10,   10,   10, 0x08,
    22491,   10,   10,   10, 0x08,
    22533,   10,   10,   10, 0x08,
    22575,   10,   10,   10, 0x08,
    22616,   10,   10,   10, 0x08,
    22657,   10,   10,   10, 0x08,
    22698,   10,   10,   10, 0x08,
    22744,   10,   10,   10, 0x08,
    22790,   10,   10,   10, 0x08,
    22836,   10,   10,   10, 0x08,
    22882,   10,   10,   10, 0x08,
    22939,   10,   10,   10, 0x08,
    22992,   10,   10,   10, 0x08,
    23045,   10,   10,   10, 0x08,
    23102,   10,   10,   10, 0x08,
    23159,   10,   10,   10, 0x08,
    23214,   10,   10,   10, 0x08,
    23256,   10,   10,   10, 0x08,
    23298,   10,   10,   10, 0x08,
    23340,   10,   10,   10, 0x08,
    23382,   10,   10,   10, 0x08,
    23423,   10,   10,   10, 0x08,
    23464,   10,   10,   10, 0x08,
    23505,   10,   10,   10, 0x08,
    23546,   10,   10,   10, 0x08,
    23592,   10,   10,   10, 0x08,
    23638,   10,   10,   10, 0x08,
    23684,   10,   10,   10, 0x08,
    23733,   10,   10,   10, 0x08,
    23779,   10,   10,   10, 0x08,
    23821,   10,   10,   10, 0x08,
    23878,   10,   10,   10, 0x08,
    23931,   10,   10,   10, 0x08,
    23984,   10,   10,   10, 0x08,
    24041,   10,   10,   10, 0x08,
    24095,   10,   10,   10, 0x08,
    24154,   10,   10,   10, 0x08,
    24201,   10,   10,   10, 0x08,
    24249,   10,   10,   10, 0x08,
    24293,   10,   10,   10, 0x08,
    24336,   10,   10,   10, 0x08,
    24391,   10,   10,   10, 0x08,
    24447,   10,   10,   10, 0x08,
    24487,   10,   10,   10, 0x08,
    24529,   10,   10,   10, 0x08,
    24573,   10,   10,   10, 0x08,
    24626,   10,   10,   10, 0x08,
    24677,   10,   10,   10, 0x08,
    24717,   10,   10,   10, 0x08,
    24757,   10,   10,   10, 0x08,
    24797,   10,   10,   10, 0x08,
    24837,   10,   10,   10, 0x08,
    24876,   10,   10,   10, 0x08,
    24915,   10,   10,   10, 0x08,
    24954,   10,   10,   10, 0x08,
    24993,   10,   10,   10, 0x08,
    25037,   10,   10,   10, 0x08,
    25081,   10,   10,   10, 0x08,
    25125,   10,   10,   10, 0x08,
    25176,   10,   10,   10, 0x08,
    25227,   10,   10,   10, 0x08,
    25270,   10,   10,   10, 0x08,
    25302,   10,   10,   10, 0x08,
    25346,   10,   10,   10, 0x08,
    25395,   10,   10,   10, 0x08,
    25423,   10,   10,   10, 0x08,
    25465,   10,   10,   10, 0x08,
    25507,   10,   10,   10, 0x08,
    25557,   10,   10,   10, 0x08,
    25602,   10,   10,   10, 0x08,
    25648,   10,   10,   10, 0x08,
    25693,   10,   10,   10, 0x08,
    25738,   10,   10,   10, 0x08,
    25784,   10,   10,   10, 0x08,
    25829,   10,   10,   10, 0x08,
    25875,   10,   10,   10, 0x08,
    25920,   10,   10,   10, 0x08,
    25965,   10,   10,   10, 0x08,
    26011,   10,   10,   10, 0x08,
    26056,   10,   10,   10, 0x08,
    26102,   10,   10,   10, 0x08,
    26124,   10,   10,   10, 0x08,
    26151,   10,   10,   10, 0x08,
    26183,   10,   10,   10, 0x08,
    26222,   10,   10,   10, 0x08,
    26258,   10,   10,   10, 0x08,
    26294,   10,   10,   10, 0x08,
    26332,   10,   10,   10, 0x08,
    26384,   10,   10,   10, 0x08,
    26435,   10,   10,   10, 0x08,
    26484,   10,   10,   10, 0x08,
    26537,   10,   10,   10, 0x08,
    26594,   10,   10,   10, 0x08,
    26651,   10,   10,   10, 0x08,
    26707,   10,   10,   10, 0x08,
    26764,   10,   10,   10, 0x08,
    26810,   10,   10,   10, 0x08,
    26855,   10,   10,   10, 0x08,
    26903,   10,   10,   10, 0x08,
    26949,   10,   10,   10, 0x08,
    26993,   10,   10,   10, 0x08,
    27037,   10,   10,   10, 0x08,
    27084,   10,   10,   10, 0x08,
    27130,   10,   10,   10, 0x08,
    27176,   10,   10,   10, 0x08,
    27215,   10,   10,   10, 0x08,
    27257,   10,   10,   10, 0x08,
    27303,   10,   10,   10, 0x08,
    27349,   10,   10,   10, 0x08,
    27395,   10,   10,   10, 0x08,
    27441,   10,   10,   10, 0x08,
    27486,   10,   10,   10, 0x08,
    27531,   10,   10,   10, 0x08,
    27576,   10,   10,   10, 0x08,
    27621,   10,   10,   10, 0x08,
    27671,   10,   10,   10, 0x08,
    27715,   10,   10,   10, 0x08,
    27759,   10,   10,   10, 0x08,
    27803,   10,   10,   10, 0x08,
    27847,   10,   10,   10, 0x08,
    27890,   10,   10,   10, 0x08,
    27933,   10,   10,   10, 0x08,
    27976,   10,   10,   10, 0x08,
    28024,   10,   10,   10, 0x08,
    28068,   10,   10,   10, 0x08,
    28112,   10,   10,   10, 0x08,
    28156,   10,   10,   10, 0x08,
    28200,   10,   10,   10, 0x08,
    28243,   10,   10,   10, 0x08,
    28286,   10,   10,   10, 0x08,
    28329,   10,   10,   10, 0x08,
    28372,   10,   10,   10, 0x08,
    28423,   10,   10,   10, 0x08,
    28472,   10,   10,   10, 0x08,
    28520,   10,   10,   10, 0x08,
    28568,   10,   10,   10, 0x08,
    28617,   10,   10,   10, 0x08,
    28664,   10,   10,   10, 0x08,
    28720,   10,   10,   10, 0x08,
    28765,   10,   10,   10, 0x08,
    28808,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_JVlibForm[] = {
    "JVlibForm\0\0noteval(const QString*)\0"
    "open()\0bool\0save()\0saveAs()\0about()\0"
    "selectedPort()\0HelpDoc()\0slotConfig()\0"
    "slotOffline()\0slotactionCopy()\0"
    "slotactionWrite()\0slotactionBulk_Dump()\0"
    "slotactionWhats_This()\0QString\0"
    "funcNoteCalc(int)\0Pan2Deg(int)\0"
    "slotSysSetPerf()\0slotSysSetPatch()\0"
    "slotSysSetPerformanceMode()\0"
    "slotSysSetPatchMode()\0slotSysSetGmMode()\0"
    "on_SysMode_select_currentIndexChanged(int)\0"
    "int\0on_System_Sync_button_clicked()\0"
    "on_SysPatchNumber_valueChanged(int)\0"
    "on_SysPerfNumber_valueChanged(int)\0"
    "on_SysClock_select_currentIndexChanged(int)\0"
    "on_SysTapControl_select_currentIndexChanged(int)\0"
    "on_SysHoldControl_select_currentIndexChanged(int)\0"
    "on_SysPeakControl_select_currentIndexChanged(int)\0"
    "on_SysVolumeControl_select_currentIndexChanged(int)\0"
    "on_SysAftertouchControl_select_currentIndexChanged(int)\0"
    "on_SysPatchRecvChannel_select_valueChanged(int)\0"
    "on_SysControlRecvChannel_select_valueChanged(int)\0"
    "on_System_Upload_button_clicked()\0"
    "on_System_LoadData_button_clicked()\0"
    "on_System_SaveData_button_clicked()\0"
    "on_EFX_switch_stateChanged(int)\0"
    "on_Chorus_switch_stateChanged(int)\0"
    "on_Reverb_switch_stateChanged(int)\0"
    "on_PatchRemain_switch_stateChanged(int)\0"
    "on_AcceptProgramChg_switch_stateChanged(int)\0"
    "on_AcceptBankSel_switch_stateChanged(int)\0"
    "on_AcceptControlChange_switch_stateChanged(int)\0"
    "on_AcceptModulation_switch_stateChanged(int)\0"
    "on_AcceptVolumeChg_switch_stateChanged(int)\0"
    "on_AcceptHold1Chg_switch_stateChanged(int)\0"
    "on_AcceptBender_switch_stateChanged(int)\0"
    "on_AcceptAftertouch_switch_stateChanged(int)\0"
    "on_SysPreviewMode_switch_toggled(bool)\0"
    "on_SysPreviewNote1_select_valueChanged(int)\0"
    "on_SysPreviewNote2_select_valueChanged(int)\0"
    "on_SysPreviewNote3_select_valueChanged(int)\0"
    "on_SysPreviewNote4_select_valueChanged(int)\0"
    "on_SysPreviewNote1_volume_valueChanged(int)\0"
    "on_SysPreviewNote2_volume_valueChanged(int)\0"
    "on_SysPreviewNote3_volume_valueChanged(int)\0"
    "on_SysPreviewNote4_volume_valueChanged(int)\0"
    "on_SysTestTone_button_clicked(bool)\0"
    "on_SysPlayMidi_button_clicked()\0"
    "on_SysPanic_button_clicked()\0"
    "on_MainTabWidget_currentChanged(int)\0"
    "on_PerfGroup_select_currentIndexChanged(int)\0"
    "on_PerfNumber_select_valueChanged(int)\0"
    "on_PerfSync_button_clicked()\0"
    "on_PerfReverbTime_select_valueChanged(int)\0"
    "on_PerfReverbFeedback_select_valueChanged(int)\0"
    "on_PerfReverbLevel_select_valueChanged(int)\0"
    "on_PerfChorusLevel_select_valueChanged(int)\0"
    "on_PerfChorusRate_select_valueChanged(int)\0"
    "on_PerfChorusDepth_select_valueChanged(int)\0"
    "on_PerfChorusPreDelay_select_valueChanged(int)\0"
    "on_PerfChorusFeedback_select_valueChanged(int)\0"
    "on_PerfDefaultTempo_select_valueChanged(int)\0"
    "on_PerfReverbHiFreqDamp_select_currentIndexChanged(int)\0"
    "on_PerfReverbType_select_currentIndexChanged(int)\0"
    "on_PerfChorusOutput_select_currentIndexChanged(int)\0"
    "on_PerfName_edit_editingFinished()\0"
    "on_Part1_PatchNumber_select_valueChanged(int)\0"
    "on_Part1_PatchGroup_select_currentIndexChanged(int)\0"
    "on_PartsRangeLimitEnable_select_toggled(bool)\0"
    "on_Part1_Transpose_select_valueChanged(int)\0"
    "on_Part1_TuneAdj_select_valueChanged(int)\0"
    "on_Part1_VoiceReserve_select_valueChanged(int)\0"
    "on_Part1_LowLimit_select_valueChanged(int)\0"
    "on_Part1_HighLimit_select_valueChanged(int)\0"
    "on_Part1_Level_select_valueChanged(int)\0"
    "on_Part1_Pan_select_valueChanged(int)\0"
    "on_Part1_ChorusSend_select_valueChanged(int)\0"
    "on_Part1_ReverbSend_select_valueChanged(int)\0"
    "on_Part1_OutputLevel_select_valueChanged(int)\0"
    "on_Part1_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part1_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part1_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part1_ReceiveHold_enable_toggled(bool)\0"
    "on_Part1_Output_select_currentIndexChanged(int)\0"
    "on_Part1_MidiChannel_select_valueChanged(int)\0"
    "on_Part1_TestTone_switch_toggled(bool)\0"
    "on_Part2_Transpose_select_valueChanged(int)\0"
    "on_Part2_TuneAdj_select_valueChanged(int)\0"
    "on_Part2_VoiceReserve_select_valueChanged(int)\0"
    "on_Part2_LowLimit_select_valueChanged(int)\0"
    "on_Part2_HighLimit_select_valueChanged(int)\0"
    "on_Part2_PatchNumber_select_valueChanged(int)\0"
    "on_Part2_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part2_Level_select_valueChanged(int)\0"
    "on_Part2_Pan_select_valueChanged(int)\0"
    "on_Part2_ChorusSend_select_valueChanged(int)\0"
    "on_Part2_ReverbSend_select_valueChanged(int)\0"
    "on_Part2_OutputLevel_select_valueChanged(int)\0"
    "on_Part2_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part2_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part2_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part2_ReceiveHold_enable_toggled(bool)\0"
    "on_Part2_Output_select_currentIndexChanged(int)\0"
    "on_Part2_MidiChannel_select_valueChanged(int)\0"
    "on_Part2_TestTone_switch_toggled(bool)\0"
    "on_Part3_Transpose_select_valueChanged(int)\0"
    "on_Part3_TuneAdj_select_valueChanged(int)\0"
    "on_Part3_VoiceReserve_select_valueChanged(int)\0"
    "on_Part3_LowLimit_select_valueChanged(int)\0"
    "on_Part3_HighLimit_select_valueChanged(int)\0"
    "on_Part3_PatchNumber_select_valueChanged(int)\0"
    "on_Part3_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part3_Level_select_valueChanged(int)\0"
    "on_Part3_Pan_select_valueChanged(int)\0"
    "on_Part3_ChorusSend_select_valueChanged(int)\0"
    "on_Part3_ReverbSend_select_valueChanged(int)\0"
    "on_Part3_OutputLevel_select_valueChanged(int)\0"
    "on_Part3_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part3_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part3_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part3_ReceiveHold_enable_toggled(bool)\0"
    "on_Part3_Output_select_currentIndexChanged(int)\0"
    "on_Part3_MidiChannel_select_valueChanged(int)\0"
    "on_Part3_TestTone_switch_toggled(bool)\0"
    "on_Part4_Transpose_select_valueChanged(int)\0"
    "on_Part4_TuneAdj_select_valueChanged(int)\0"
    "on_Part4_VoiceReserve_select_valueChanged(int)\0"
    "on_Part4_LowLimit_select_valueChanged(int)\0"
    "on_Part4_HighLimit_select_valueChanged(int)\0"
    "on_Part4_PatchNumber_select_valueChanged(int)\0"
    "on_Part4_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part4_Level_select_valueChanged(int)\0"
    "on_Part4_Pan_select_valueChanged(int)\0"
    "on_Part4_ChorusSend_select_valueChanged(int)\0"
    "on_Part4_ReverbSend_select_valueChanged(int)\0"
    "on_Part4_OutputLevel_select_valueChanged(int)\0"
    "on_Part4_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part4_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part4_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part4_ReceiveHold_enable_toggled(bool)\0"
    "on_Part4_Output_select_currentIndexChanged(int)\0"
    "on_Part4_MidiChannel_select_valueChanged(int)\0"
    "on_Part4_TestTone_switch_toggled(bool)\0"
    "on_Part5_Transpose_select_valueChanged(int)\0"
    "on_Part5_TuneAdj_select_valueChanged(int)\0"
    "on_Part5_VoiceReserve_select_valueChanged(int)\0"
    "on_Part5_LowLimit_select_valueChanged(int)\0"
    "on_Part5_HighLimit_select_valueChanged(int)\0"
    "on_Part5_PatchNumber_select_valueChanged(int)\0"
    "on_Part5_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part5_Level_select_valueChanged(int)\0"
    "on_Part5_Pan_select_valueChanged(int)\0"
    "on_Part5_ChorusSend_select_valueChanged(int)\0"
    "on_Part5_ReverbSend_select_valueChanged(int)\0"
    "on_Part5_OutputLevel_select_valueChanged(int)\0"
    "on_Part5_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part5_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part5_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part5_ReceiveHold_enable_toggled(bool)\0"
    "on_Part5_Output_select_currentIndexChanged(int)\0"
    "on_Part5_MidiChannel_select_valueChanged(int)\0"
    "on_Part5_TestTone_switch_toggled(bool)\0"
    "on_Part6_Transpose_select_valueChanged(int)\0"
    "on_Part6_TuneAdj_select_valueChanged(int)\0"
    "on_Part6_VoiceReserve_select_valueChanged(int)\0"
    "on_Part6_LowLimit_select_valueChanged(int)\0"
    "on_Part6_HighLimit_select_valueChanged(int)\0"
    "on_Part6_PatchNumber_select_valueChanged(int)\0"
    "on_Part6_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part6_Level_select_valueChanged(int)\0"
    "on_Part6_Pan_select_valueChanged(int)\0"
    "on_Part6_ChorusSend_select_valueChanged(int)\0"
    "on_Part6_ReverbSend_select_valueChanged(int)\0"
    "on_Part6_OutputLevel_select_valueChanged(int)\0"
    "on_Part6_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part6_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part6_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part6_ReceiveHold_enable_toggled(bool)\0"
    "on_Part6_Output_select_currentIndexChanged(int)\0"
    "on_Part6_MidiChannel_select_valueChanged(int)\0"
    "on_Part6_TestTone_switch_toggled(bool)\0"
    "on_Part7_Transpose_select_valueChanged(int)\0"
    "on_Part7_TuneAdj_select_valueChanged(int)\0"
    "on_Part7_VoiceReserve_select_valueChanged(int)\0"
    "on_Part7_LowLimit_select_valueChanged(int)\0"
    "on_Part7_HighLimit_select_valueChanged(int)\0"
    "on_Part7_PatchNumber_select_valueChanged(int)\0"
    "on_Part7_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part7_Level_select_valueChanged(int)\0"
    "on_Part7_Pan_select_valueChanged(int)\0"
    "on_Part7_ChorusSend_select_valueChanged(int)\0"
    "on_Part7_ReverbSend_select_valueChanged(int)\0"
    "on_Part7_OutputLevel_select_valueChanged(int)\0"
    "on_Part7_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part7_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part7_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part7_ReceiveHold_enable_toggled(bool)\0"
    "on_Part7_Output_select_currentIndexChanged(int)\0"
    "on_Part7_MidiChannel_select_valueChanged(int)\0"
    "on_Part7_TestTone_switch_toggled(bool)\0"
    "on_Part8_Transpose_select_valueChanged(int)\0"
    "on_Part8_TuneAdj_select_valueChanged(int)\0"
    "on_Part8_VoiceReserve_select_valueChanged(int)\0"
    "on_Part8_LowLimit_select_valueChanged(int)\0"
    "on_Part8_HighLimit_select_valueChanged(int)\0"
    "on_Part8_PatchNumber_select_valueChanged(int)\0"
    "on_Part8_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part8_Level_select_valueChanged(int)\0"
    "on_Part8_Pan_select_valueChanged(int)\0"
    "on_Part8_ChorusSend_select_valueChanged(int)\0"
    "on_Part8_ReverbSend_select_valueChanged(int)\0"
    "on_Part8_OutputLevel_select_valueChanged(int)\0"
    "on_Part8_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part8_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part8_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part8_ReceiveHold_enable_toggled(bool)\0"
    "on_Part8_Output_select_currentIndexChanged(int)\0"
    "on_Part8_MidiChannel_select_valueChanged(int)\0"
    "on_Part8_TestTone_switch_toggled(bool)\0"
    "on_Part9_Transpose_select_valueChanged(int)\0"
    "on_Part9_TuneAdj_select_valueChanged(int)\0"
    "on_Part9_VoiceReserve_select_valueChanged(int)\0"
    "on_Part9_LowLimit_select_valueChanged(int)\0"
    "on_Part9_HighLimit_select_valueChanged(int)\0"
    "on_Part9_PatchNumber_select_valueChanged(int)\0"
    "on_Part9_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part9_Level_select_valueChanged(int)\0"
    "on_Part9_Pan_select_valueChanged(int)\0"
    "on_Part9_ChorusSend_select_valueChanged(int)\0"
    "on_Part9_ReverbSend_select_valueChanged(int)\0"
    "on_Part9_OutputLevel_select_valueChanged(int)\0"
    "on_Part9_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part9_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part9_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part9_ReceiveHold_enable_toggled(bool)\0"
    "on_Part9_Output_select_currentIndexChanged(int)\0"
    "on_Part9_MidiChannel_select_valueChanged(int)\0"
    "on_Part9_TestTone_switch_toggled(bool)\0"
    "on_Part10_Transpose_select_valueChanged(int)\0"
    "on_Part10_TuneAdj_select_valueChanged(int)\0"
    "on_Part10_VoiceReserve_select_valueChanged(int)\0"
    "on_Part10_LowLimit_select_valueChanged(int)\0"
    "on_Part10_HighLimit_select_valueChanged(int)\0"
    "on_Part10_PatchNumber_select_valueChanged(int)\0"
    "on_Part10_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part10_Level_select_valueChanged(int)\0"
    "on_Part10_Pan_select_valueChanged(int)\0"
    "on_Part10_ChorusSend_select_valueChanged(int)\0"
    "on_Part10_ReverbSend_select_valueChanged(int)\0"
    "on_Part10_OutputLevel_select_valueChanged(int)\0"
    "on_Part10_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part10_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part10_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part10_ReceiveHold_enable_toggled(bool)\0"
    "on_Part10_Output_select_currentIndexChanged(int)\0"
    "on_Part10_MidiChannel_select_valueChanged(int)\0"
    "on_Part10_TestTone_switch_toggled(bool)\0"
    "on_Part11_Transpose_select_valueChanged(int)\0"
    "on_Part11_TuneAdj_select_valueChanged(int)\0"
    "on_Part11_VoiceReserve_select_valueChanged(int)\0"
    "on_Part11_LowLimit_select_valueChanged(int)\0"
    "on_Part11_HighLimit_select_valueChanged(int)\0"
    "on_Part11_PatchNumber_select_valueChanged(int)\0"
    "on_Part11_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part11_Level_select_valueChanged(int)\0"
    "on_Part11_Pan_select_valueChanged(int)\0"
    "on_Part11_ChorusSend_select_valueChanged(int)\0"
    "on_Part11_ReverbSend_select_valueChanged(int)\0"
    "on_Part11_OutputLevel_select_valueChanged(int)\0"
    "on_Part11_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part11_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part11_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part11_ReceiveHold_enable_toggled(bool)\0"
    "on_Part11_Output_select_currentIndexChanged(int)\0"
    "on_Part11_MidiChannel_select_valueChanged(int)\0"
    "on_Part11_TestTone_switch_toggled(bool)\0"
    "on_Part12_Transpose_select_valueChanged(int)\0"
    "on_Part12_TuneAdj_select_valueChanged(int)\0"
    "on_Part12_VoiceReserve_select_valueChanged(int)\0"
    "on_Part12_LowLimit_select_valueChanged(int)\0"
    "on_Part12_HighLimit_select_valueChanged(int)\0"
    "on_Part12_PatchNumber_select_valueChanged(int)\0"
    "on_Part12_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part12_Level_select_valueChanged(int)\0"
    "on_Part12_Pan_select_valueChanged(int)\0"
    "on_Part12_ChorusSend_select_valueChanged(int)\0"
    "on_Part12_ReverbSend_select_valueChanged(int)\0"
    "on_Part12_OutputLevel_select_valueChanged(int)\0"
    "on_Part12_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part12_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part12_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part12_ReceiveHold_enable_toggled(bool)\0"
    "on_Part12_Output_select_currentIndexChanged(int)\0"
    "on_Part12_MidiChannel_select_valueChanged(int)\0"
    "on_Part12_TestTone_switch_toggled(bool)\0"
    "on_Part13_Transpose_select_valueChanged(int)\0"
    "on_Part13_TuneAdj_select_valueChanged(int)\0"
    "on_Part13_VoiceReserve_select_valueChanged(int)\0"
    "on_Part13_LowLimit_select_valueChanged(int)\0"
    "on_Part13_HighLimit_select_valueChanged(int)\0"
    "on_Part13_PatchNumber_select_valueChanged(int)\0"
    "on_Part13_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part13_Level_select_valueChanged(int)\0"
    "on_Part13_Pan_select_valueChanged(int)\0"
    "on_Part13_ChorusSend_select_valueChanged(int)\0"
    "on_Part13_ReverbSend_select_valueChanged(int)\0"
    "on_Part13_OutputLevel_select_valueChanged(int)\0"
    "on_Part13_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part13_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part13_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part13_ReceiveHold_enable_toggled(bool)\0"
    "on_Part13_Output_select_currentIndexChanged(int)\0"
    "on_Part13_MidiChannel_select_valueChanged(int)\0"
    "on_Part13_TestTone_switch_toggled(bool)\0"
    "on_Part14_Transpose_select_valueChanged(int)\0"
    "on_Part14_TuneAdj_select_valueChanged(int)\0"
    "on_Part14_VoiceReserve_select_valueChanged(int)\0"
    "on_Part14_LowLimit_select_valueChanged(int)\0"
    "on_Part14_HighLimit_select_valueChanged(int)\0"
    "on_Part14_PatchNumber_select_valueChanged(int)\0"
    "on_Part14_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part14_Level_select_valueChanged(int)\0"
    "on_Part14_Pan_select_valueChanged(int)\0"
    "on_Part14_ChorusSend_select_valueChanged(int)\0"
    "on_Part14_ReverbSend_select_valueChanged(int)\0"
    "on_Part14_OutputLevel_select_valueChanged(int)\0"
    "on_Part14_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part14_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part14_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part14_ReceiveHold_enable_toggled(bool)\0"
    "on_Part14_Output_select_currentIndexChanged(int)\0"
    "on_Part14_MidiChannel_select_valueChanged(int)\0"
    "on_Part14_TestTone_switch_toggled(bool)\0"
    "on_Part15_Transpose_select_valueChanged(int)\0"
    "on_Part15_TuneAdj_select_valueChanged(int)\0"
    "on_Part15_VoiceReserve_select_valueChanged(int)\0"
    "on_Part15_LowLimit_select_valueChanged(int)\0"
    "on_Part15_HighLimit_select_valueChanged(int)\0"
    "on_Part15_PatchNumber_select_valueChanged(int)\0"
    "on_Part15_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part15_Level_select_valueChanged(int)\0"
    "on_Part15_Pan_select_valueChanged(int)\0"
    "on_Part15_ChorusSend_select_valueChanged(int)\0"
    "on_Part15_ReverbSend_select_valueChanged(int)\0"
    "on_Part15_OutputLevel_select_valueChanged(int)\0"
    "on_Part15_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part15_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part15_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part15_ReceiveHold_enable_toggled(bool)\0"
    "on_Part15_Output_select_currentIndexChanged(int)\0"
    "on_Part15_MidiChannel_select_valueChanged(int)\0"
    "on_Part15_TestTone_switch_toggled(bool)\0"
    "on_Part16_Transpose_select_valueChanged(int)\0"
    "on_Part16_TuneAdj_select_valueChanged(int)\0"
    "on_Part16_VoiceReserve_select_valueChanged(int)\0"
    "on_Part16_LowLimit_select_valueChanged(int)\0"
    "on_Part16_HighLimit_select_valueChanged(int)\0"
    "on_Part16_PatchNumber_select_valueChanged(int)\0"
    "on_Part16_PatchGroup_select_currentIndexChanged(int)\0"
    "on_Part16_Level_select_valueChanged(int)\0"
    "on_Part16_Pan_select_valueChanged(int)\0"
    "on_Part16_ChorusSend_select_valueChanged(int)\0"
    "on_Part16_ReverbSend_select_valueChanged(int)\0"
    "on_Part16_OutputLevel_select_valueChanged(int)\0"
    "on_Part16_ReceiveMidi_enable_toggled(bool)\0"
    "on_Part16_ReceivePrgChg_enable_toggled(bool)\0"
    "on_Part16_ReceiveVolume_enable_toggled(bool)\0"
    "on_Part16_ReceiveHold_enable_toggled(bool)\0"
    "on_Part16_Output_select_currentIndexChanged(int)\0"
    "on_Part16_MidiChannel_select_valueChanged(int)\0"
    "on_Part16_TestTone_switch_toggled(bool)\0"
    "slotPerfEFXsource(int)\0slotPerfEFXtype(int)\0"
    "slotPatchEFXtype(int)\0slotEFXoutput(int)\0"
    "slotEFXreverbSend(int)\0slotEFXchorusSend(int)\0"
    "slotEFXoutputLevel(int)\0"
    "slotEFXcontrol1Depth(int)\0"
    "slotEFXcontrol2Depth(int)\0"
    "slotEFXcontrolSource1(int)\0"
    "slotEFXcontrolSource2(int)\0slotEFXparm1(int)\0"
    "slotEFXparm2(int)\0slotEFXparm3(int)\0"
    "slotEFXparm4(int)\0slotEFXparm5(int)\0"
    "slotEFXparm6(int)\0slotEFXparm7(int)\0"
    "slotEFXparm8(int)\0slotEFXparm9(int)\0"
    "slotEFXparmA(int)\0slotEFXparmB(int)\0"
    "slotEFXparmC(int)\0on_Patch_Sync_button_clicked()\0"
    "on_Patch_Group_select_currentIndexChanged(int)\0"
    "on_Patch_Number_select_valueChanged(int)\0"
    "on_Patch_Name_edit_editingFinished()\0"
    "on_Patch_Level_select_valueChanged(int)\0"
    "on_Patch_Pan_select_valueChanged(int)\0"
    "on_Patch_AnalogFeel_select_valueChanged(int)\0"
    "on_Patch_PortamentoTime_select_valueChanged(int)\0"
    "on_Patch_BenderDown_select_valueChanged(int)\0"
    "on_Patch_BenderUp_select_valueChanged(int)\0"
    "on_Patch_HoldPeak_select_currentIndexChanged(int)\0"
    "on_Patch_C1_HoldPeak_select_currentIndexChanged(int)\0"
    "on_Patch_C2_HoldPeak_select_currentIndexChanged(int)\0"
    "on_Patch_C3_HoldPeak_select_currentIndexChanged(int)\0"
    "on_Patch_Struct12_select_valueChanged(int)\0"
    "on_Patch_Booster12_select_valueChanged(int)\0"
    "on_Patch_Struct34_select_valueChanged(int)\0"
    "on_Patch_Booster34_select_valueChanged(int)\0"
    "on_Patch_Tone1_enable_toggled(bool)\0"
    "on_Patch_Tone2_enable_toggled(bool)\0"
    "on_Patch_Tone3_enable_toggled(bool)\0"
    "on_Patch_Tone4_enable_toggled(bool)\0"
    "on_Patch_DefaultTempo_select_valueChanged(int)\0"
    "on_Patch_VoicePriority_switch_toggled(bool)\0"
    "on_Patch_VoiceMode_switch_toggled(bool)\0"
    "on_Patch_PortamentoEnable_switch_toggled(bool)\0"
    "on_Patch_PortamentoMode_switch_toggled(bool)\0"
    "on_Patch_PortamentoType_switch_toggled(bool)\0"
    "on_Patch_PortamentoStart_switch_toggled(bool)\0"
    "on_Patch_TestTone_switch_toggled(bool)\0"
    "on_Patch_PerfPartNum_select_currentIndexChanged(int)\0"
    "on_Patch_VelocityRange_enable_toggled(bool)\0"
    "on_Patch_ControlSource2_select_currentIndexChanged(int)\0"
    "on_Patch_ControlSource3_select_currentIndexChanged(int)\0"
    "on_Patch_SoloLegato_enable_toggled(bool)\0"
    "on_PatchEFX_ReverbHiFreqDamp_select_currentIndexChanged(int)\0"
    "on_PatchEFX_ReverbLevel_select_valueChanged(int)\0"
    "on_PatchEFX_ReverbTime_select_valueChanged(int)\0"
    "on_PatchEFX_ReverbType_select_currentIndexChanged(int)\0"
    "on_PatchEFX_ReverbFeedback_select_valueChanged(int)\0"
    "on_PatchEFX_ChorusLevel_select_valueChanged(int)\0"
    "on_PatchEFX_ChorusRate_select_valueChanged(int)\0"
    "on_PatchEFX_ChorusDepth_select_valueChanged(int)\0"
    "on_PatchEFX_ChorusPreDelay_select_valueChanged(int)\0"
    "on_PatchEFX_ChorusFeedback_select_valueChanged(int)\0"
    "on_PatchEFX_ChorusOutput_select_currentIndexChanged(int)\0"
    "on_PatchEFX_Control1Source_select_currentIndexChanged(int)\0"
    "on_PatchEFX_Control2Source_select_currentIndexChanged(int)\0"
    "on_PatchEFX_Control1Depth_select_valueChanged(int)\0"
    "on_PatchEFX_Control2Depth_select_valueChanged(int)\0"
    "on_ToneSync_button_clicked()\0"
    "on_Tone_ToneNumber_select_valueChanged()\0"
    "on_Tone_Number_select_valueChanged(int)\0"
    "on_Tone_Group_select_currentIndexChanged(int)\0"
    "on_Tone_InstrFamily_select_currentIndexChanged(int)\0"
    "on_Tone_WaveChooser_select_currentIndexChanged(int)\0"
    "on_Tone_Output_select_currentIndexChanged(int)\0"
    "on_Tone_C1D1_select_currentIndexChanged(int)\0"
    "on_Tone_C1D2_select_currentIndexChanged(int)\0"
    "on_Tone_C1D3_select_currentIndexChanged(int)\0"
    "on_Tone_C1D4_select_currentIndexChanged(int)\0"
    "on_Tone_C2D1_select_currentIndexChanged(int)\0"
    "on_Tone_C2D2_select_currentIndexChanged(int)\0"
    "on_Tone_C2D3_select_currentIndexChanged(int)\0"
    "on_Tone_C2D4_select_currentIndexChanged(int)\0"
    "on_Tone_C3D1_select_currentIndexChanged(int)\0"
    "on_Tone_C3D2_select_currentIndexChanged(int)\0"
    "on_Tone_C3D3_select_currentIndexChanged(int)\0"
    "on_Tone_C3D4_select_currentIndexChanged(int)\0"
    "on_Tone_WaveGain_select_currentIndexChanged(int)\0"
    "on_Tone_DelayMode_select_currentIndexChanged(int)\0"
    "on_Tone_ChorusSend_select_valueChanged(int)\0"
    "on_Tone_ReverbSend_select_valueChanged(int)\0"
    "on_Tone_OutputLevel_select_valueChanged(int)\0"
    "on_Tone_Level_select_valueChanged(int)\0"
    "on_Tone_VeloXfadeDepth_select_valueChanged(int)\0"
    "on_Tone_VeloLowerRange_select_valueChanged(int)\0"
    "on_Tone_DelayTime_select_valueChanged(int)\0"
    "on_Tone_VeloUpperRange_select_valueChanged(int)\0"
    "on_Tone_C1D1Depth_select_valueChanged(int)\0"
    "on_Tone_C1D2Depth_select_valueChanged(int)\0"
    "on_Tone_C1D3Depth_select_valueChanged(int)\0"
    "on_Tone_C1D4Depth_select_valueChanged(int)\0"
    "on_Tone_C2D1Depth_select_valueChanged(int)\0"
    "on_Tone_C2D2Depth_select_valueChanged(int)\0"
    "on_Tone_C2D3Depth_select_valueChanged(int)\0"
    "on_Tone_C2D4Depth_select_valueChanged(int)\0"
    "on_Tone_C3D1Depth_select_valueChanged(int)\0"
    "on_Tone_C3D2Depth_select_valueChanged(int)\0"
    "on_Tone_C3D3Depth_select_valueChanged(int)\0"
    "on_Tone_C3D4Depth_select_valueChanged(int)\0"
    "on_Tone_ReceiveVolume_enable_toggled(bool)\0"
    "on_Tone_ReceiveHold_enable_toggled(bool)\0"
    "on_Tone_ReceiveReDamper_enable_toggled(bool)\0"
    "on_Tone_ReceiveBender_enable_toggled(bool)\0"
    "on_Tone_FXM_enable_toggled(bool)\0"
    "on_Tone_FXMColor_select_currentIndexChanged(int)\0"
    "on_Tone_FXMDepth_select_currentIndexChanged(int)\0"
    "on_ToneEFX_LFO1FadeTime_select_valueChanged(int)\0"
    "on_ToneEFX_LFO2FadeTime_select_valueChanged(int)\0"
    "on_ToneEFX_LFO1Delay_select_valueChanged(int)\0"
    "on_ToneEFX_LFO1Rate_select_valueChanged(int)\0"
    "on_ToneEFX_LFO2Rate_select_valueChanged(int)\0"
    "on_ToneEFX_LFO2Delay_select_valueChanged(int)\0"
    "on_ToneEFX_LFO1KeyTrigger_enable_toggled(bool)\0"
    "on_ToneEFX_LFO2KeyTrigger_enable_toggled(bool)\0"
    "on_ToneEFX_LFO1LevelOffset_select_currentIndexChanged(int)\0"
    "on_ToneEFX_LFO2LevelOffset_select_currentIndexChanged(int)\0"
    "on_ToneEFX_LF01Waveform_select_currentIndexChanged(int)\0"
    "on_ToneEFX_LFO1FadeMode_select_currentIndexChanged(int)\0"
    "on_ToneEFX_LFO1ExtSync_select_currentIndexChanged(int)\0"
    "on_ToneEFX_LF02Waveform_select_currentIndexChanged(int)\0"
    "on_ToneEFX_LFO2FadeMode_select_currentIndexChanged(int)\0"
    "on_ToneEFX_LFO2ExtSync_select_currentIndexChanged(int)\0"
    "on_ToneEFX_PanControl_select_currentIndexChanged(int)\0"
    "on_ToneEFX_Pan_select_valueChanged(int)\0"
    "on_ToneEFX_PanKeyFollow_select_currentIndexChanged(int)\0"
    "on_ToneEFX_PanRandDepth_select_valueChanged(int)\0"
    "on_ToneEFX_AltPan_select_valueChanged(int)\0"
    "on_ToneEFX_PanLFO1Depth_select_valueChanged(int)\0"
    "on_ToneEFX_PanLFO2Depth_select_valueChanged(int)\0"
    "on_ToneTVA_Time1_select_valueChanged(int)\0"
    "on_ToneTVA_Time2_select_valueChanged(int)\0"
    "on_ToneTVA_Time3_select_valueChanged(int)\0"
    "on_ToneTVA_Time4_select_valueChanged(int)\0"
    "on_ToneTVA_Lvl1_select_valueChanged(int)\0"
    "on_ToneTVA_Lvl2_select_valueChanged(int)\0"
    "on_ToneTVA_Lvl3_select_valueChanged(int)\0"
    "on_ToneTVA_LFO1Depth_select_valueChanged(int)\0"
    "on_ToneTVA_LFO2Depth_select_valueChanged(int)\0"
    "on_ToneTVA_VelocSens_select_valueChanged(int)\0"
    "on_ToneTVA_BiasPoint_select_valueChanged(int)\0"
    "on_ToneTVA_BiasDirection_select_currentIndexChanged(int)\0"
    "on_ToneTVA_Time1Sens_select_currentIndexChanged(int)\0"
    "on_ToneTVA_Time4Sens_select_currentIndexChanged(int)\0"
    "on_ToneTVA_VelocityCurve_select_currentIndexChanged(int)\0"
    "on_ToneTVA_TimeKeyfollow_select_currentIndexChanged(int)\0"
    "on_ToneTVA_BiasLvl_select_currentIndexChanged(QString)\0"
    "on_ToneTVF_Time1_select_valueChanged(int)\0"
    "on_ToneTVF_Time2_select_valueChanged(int)\0"
    "on_ToneTVF_Time3_select_valueChanged(int)\0"
    "on_ToneTVF_Time4_select_valueChanged(int)\0"
    "on_ToneTVF_Lvl1_select_valueChanged(int)\0"
    "on_ToneTVF_Lvl2_select_valueChanged(int)\0"
    "on_ToneTVF_Lvl3_select_valueChanged(int)\0"
    "on_ToneTVF_Lvl4_select_valueChanged(int)\0"
    "on_ToneTVF_LFO1Depth_select_valueChanged(int)\0"
    "on_ToneTVF_LFO2Depth_select_valueChanged(int)\0"
    "on_ToneTVF_VelocSens_select_valueChanged(int)\0"
    "on_ToneTVF_ResVelocSens_select_valueChanged(int)\0"
    "on_ToneTVF_Resonance_select_valueChanged(int)\0"
    "on_ToneTVF_Depth_select_valueChanged(int)\0"
    "on_ToneTVF_TimeKeyfollow_select_currentIndexChanged(int)\0"
    "on_ToneTVF_Time1Sens_select_currentIndexChanged(int)\0"
    "on_ToneTVF_Time4Sens_select_currentIndexChanged(int)\0"
    "on_ToneTVF_VelocityCurve_select_currentIndexChanged(int)\0"
    "on_ToneTVF_FilterType_select_currentIndexChanged(int)\0"
    "on_ToneTVF_CutoffKeyfollow_select_currentIndexChanged(int)\0"
    "on_ToneTVF_CutoffFreq_select_valueChanged(int)\0"
    "on_Pitch_StretchTuning_select_valueChanged(int)\0"
    "on_Pitch_HighLimit_select_valueChanged(int)\0"
    "on_Pitch_LowLimit_select_valueChanged(int)\0"
    "on_Pitch_TimeKeyfollow_select_currentIndexChanged(int)\0"
    "on_Pitch_RandPitchDepth_select_currentIndexChanged(int)\0"
    "on_Pitch_Depth_select_valueChanged(int)\0"
    "on_Pitch_TuneAdj_select_valueChanged(int)\0"
    "on_Pitch_Transpose_select_valueChanged(int)\0"
    "on_Pitch_OctaveShift_select_currentIndexChanged(int)\0"
    "on_Pitch_KeyFollow_select_currentIndexChanged(int)\0"
    "on_Pitch_Time1_select_valueChanged(int)\0"
    "on_Pitch_Time2_select_valueChanged(int)\0"
    "on_Pitch_Time3_select_valueChanged(int)\0"
    "on_Pitch_Time4_select_valueChanged(int)\0"
    "on_Pitch_Lvl1_select_valueChanged(int)\0"
    "on_Pitch_Lvl2_select_valueChanged(int)\0"
    "on_Pitch_Lvl3_select_valueChanged(int)\0"
    "on_Pitch_Lvl4_select_valueChanged(int)\0"
    "on_Pitch_LFO1Depth_select_valueChanged(int)\0"
    "on_Pitch_LFO2Depth_select_valueChanged(int)\0"
    "on_Pitch_VelocSens_select_valueChanged(int)\0"
    "on_Pitch_Time1Sens_select_currentIndexChanged(int)\0"
    "on_Pitch_Time4Sens_select_currentIndexChanged(int)\0"
    "on_Tuning_ScaleTuning_enable_toggled(bool)\0"
    "on_Tuning_Sync_button_clicked()\0"
    "on_Tuning_PartTune_select_valueChanged(int)\0"
    "on_Tuning_MasterTune_select_valueChanged(double)\0"
    "slotTuning_TempButtons(int)\0"
    "on_Tuning_LoadCustomTemp_button_clicked()\0"
    "on_Tuning_SaveCustomTemp_button_clicked()\0"
    "on_Tuning_BaseKey_select_currentIndexChanged(int)\0"
    "on_Tuning_PartTuneA_select_valueChanged(int)\0"
    "on_Tuning_PartTuneAs_select_valueChanged(int)\0"
    "on_Tuning_PartTuneB_select_valueChanged(int)\0"
    "on_Tuning_PartTuneC_select_valueChanged(int)\0"
    "on_Tuning_PartTuneCs_select_valueChanged(int)\0"
    "on_Tuning_PartTuneD_select_valueChanged(int)\0"
    "on_Tuning_PartTuneDs_select_valueChanged(int)\0"
    "on_Tuning_PartTuneE_select_valueChanged(int)\0"
    "on_Tuning_PartTuneF_select_valueChanged(int)\0"
    "on_Tuning_PartTuneFs_select_valueChanged(int)\0"
    "on_Tuning_PartTuneG_select_valueChanged(int)\0"
    "on_Tuning_PartTuneGs_select_valueChanged(int)\0"
    "Tuning_QueryTemp(int)\0Tuning_setScaleTuning(int)\0"
    "on_Rhythm_Sync_button_clicked()\0"
    "on_Rhythm_EnvMode_select_toggled(bool)\0"
    "on_Rhythm_Note_enable_toggled(bool)\0"
    "on_Rhythm_Hold_enable_toggled(bool)\0"
    "on_Rhythm_Volume_enable_toggled(bool)\0"
    "on_Rhythm_WaveGroup_select_currentIndexChanged(int)\0"
    "on_Rhythm_WaveGain_select_currentIndexChanged(int)\0"
    "on_Rhythm_Output_select_currentIndexChanged(int)\0"
    "on_Rhythm_PanControl_select_currentIndexChanged(int)\0"
    "on_Rhythm_RandPitchDepth_select_currentIndexChanged(int)\0"
    "on_Rhythm_TVAVelTimeSens_select_currentIndexChanged(int)\0"
    "on_Rhythm_TVFFilterType_select_currentIndexChanged(int)\0"
    "on_Rhythm_TVFVelTimeSens_select_currentIndexChanged(int)\0"
    "on_Rhythm_WaveNumber_select_valueChanged(int)\0"
    "on_Rhythm_MuteGroup_select_valueChanged(int)\0"
    "on_Rhythm_PanRandDepth_select_valueChanged(int)\0"
    "on_Rhythm_PitchDepth_select_valueChanged(int)\0"
    "on_Rhythm_TVFDepth_select_valueChanged(int)\0"
    "on_Rhythm_KeyPress_select_valueChanged(int)\0"
    "on_Rhythm_OutputLevel_select_valueChanged(int)\0"
    "on_Rhythm_ChorusSend_select_valueChanged(int)\0"
    "on_Rhythm_ReverbSend_select_valueChanged(int)\0"
    "on_Rhythm_Pan_select_valueChanged(int)\0"
    "on_Rhythm_AltPan_select_valueChanged(int)\0"
    "on_Rhythm_PitchTime1_select_valueChanged(int)\0"
    "on_Rhythm_PitchTime2_select_valueChanged(int)\0"
    "on_Rhythm_PitchTime3_select_valueChanged(int)\0"
    "on_Rhythm_PitchTime4_select_valueChanged(int)\0"
    "on_Rhythm_PitchLvl1_select_valueChanged(int)\0"
    "on_Rhythm_PitchLvl2_select_valueChanged(int)\0"
    "on_Rhythm_PitchLvl3_select_valueChanged(int)\0"
    "on_Rhythm_PitchLvl4_select_valueChanged(int)\0"
    "on_Rhythm_PitchVelocSens_select_valueChanged(int)\0"
    "on_Rhythm_TVATime1_select_valueChanged(int)\0"
    "on_Rhythm_TVATime2_select_valueChanged(int)\0"
    "on_Rhythm_TVATime3_select_valueChanged(int)\0"
    "on_Rhythm_TVATime4_select_valueChanged(int)\0"
    "on_Rhythm_TVALvl1_select_valueChanged(int)\0"
    "on_Rhythm_TVALvl2_select_valueChanged(int)\0"
    "on_Rhythm_TVALvl3_select_valueChanged(int)\0"
    "on_Rhythm_TVAVelocSens_select_valueChanged(int)\0"
    "on_Rhythm_TVFTime1_select_valueChanged(int)\0"
    "on_Rhythm_TVFTime2_select_valueChanged(int)\0"
    "on_Rhythm_TVFTime3_select_valueChanged(int)\0"
    "on_Rhythm_TVFTime4_select_valueChanged(int)\0"
    "on_Rhythm_TVFLvl2_select_valueChanged(int)\0"
    "on_Rhythm_TVFLvl3_select_valueChanged(int)\0"
    "on_Rhythm_TVFLvl4_select_valueChanged(int)\0"
    "on_Rhythm_TVFLvl1_select_valueChanged(int)\0"
    "on_Rhythm_TVFResVelocSens_select_valueChanged(int)\0"
    "on_Rhythm_TVFCutoffFreq_select_valueChanged(int)\0"
    "on_Rhythm_TVFResonance_select_valueChanged(int)\0"
    "on_Rhythm_TVFVelocSens_select_valueChanged(int)\0"
    "on_Rhythm_SoundingPitch_select_valueChanged(int)\0"
    "on_Rhythm_BenderRange_select_valueChanged(int)\0"
    "on_Rhythm_PitchVeloTime_select_currentIndexChanged(int)\0"
    "on_Rhythm_ToneLevel_select_valueChanged(int)\0"
    "on_Rhythm_TuneAdj_select_valueChanged(int)\0"
    "on_Rhythm_TestTone_switch_clicked(bool)\0"
};

const QMetaObject JVlibForm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_JVlibForm,
      qt_meta_data_JVlibForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JVlibForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JVlibForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JVlibForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JVlibForm))
        return static_cast<void*>(const_cast< JVlibForm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int JVlibForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: noteval((*reinterpret_cast< const QString*(*)>(_a[1]))); break;
        case 1: open(); break;
        case 2: { bool _r = save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: about(); break;
        case 5: selectedPort(); break;
        case 6: HelpDoc(); break;
        case 7: slotConfig(); break;
        case 8: slotOffline(); break;
        case 9: slotactionCopy(); break;
        case 10: slotactionWrite(); break;
        case 11: slotactionBulk_Dump(); break;
        case 12: slotactionWhats_This(); break;
        case 13: { QString _r = funcNoteCalc((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: { QString _r = Pan2Deg((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: slotSysSetPerf(); break;
        case 16: slotSysSetPatch(); break;
        case 17: slotSysSetPerformanceMode(); break;
        case 18: slotSysSetPatchMode(); break;
        case 19: slotSysSetGmMode(); break;
        case 20: on_SysMode_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: { int _r = on_System_Sync_button_clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 22: on_SysPatchNumber_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: on_SysPerfNumber_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: on_SysClock_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: on_SysTapControl_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: on_SysHoldControl_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: on_SysPeakControl_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: on_SysVolumeControl_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: on_SysAftertouchControl_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: on_SysPatchRecvChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: on_SysControlRecvChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: on_System_Upload_button_clicked(); break;
        case 33: on_System_LoadData_button_clicked(); break;
        case 34: on_System_SaveData_button_clicked(); break;
        case 35: on_EFX_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: on_Chorus_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: on_Reverb_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: on_PatchRemain_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: on_AcceptProgramChg_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: on_AcceptBankSel_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: on_AcceptControlChange_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: on_AcceptModulation_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: on_AcceptVolumeChg_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: on_AcceptHold1Chg_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: on_AcceptBender_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: on_AcceptAftertouch_switch_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: on_SysPreviewMode_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: on_SysPreviewNote1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: on_SysPreviewNote2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: on_SysPreviewNote3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: on_SysPreviewNote4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: on_SysPreviewNote1_volume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: on_SysPreviewNote2_volume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: on_SysPreviewNote3_volume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: on_SysPreviewNote4_volume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: on_SysTestTone_button_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 57: on_SysPlayMidi_button_clicked(); break;
        case 58: on_SysPanic_button_clicked(); break;
        case 59: on_MainTabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: on_PerfGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 61: on_PerfNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 62: on_PerfSync_button_clicked(); break;
        case 63: on_PerfReverbTime_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 64: on_PerfReverbFeedback_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: on_PerfReverbLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: on_PerfChorusLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 67: on_PerfChorusRate_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 68: on_PerfChorusDepth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 69: on_PerfChorusPreDelay_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 70: on_PerfChorusFeedback_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: on_PerfDefaultTempo_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 72: on_PerfReverbHiFreqDamp_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 73: on_PerfReverbType_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 74: on_PerfChorusOutput_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 75: on_PerfName_edit_editingFinished(); break;
        case 76: on_Part1_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 77: on_Part1_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 78: on_PartsRangeLimitEnable_select_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 79: on_Part1_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 80: on_Part1_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 81: on_Part1_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 82: on_Part1_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 83: on_Part1_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 84: on_Part1_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 85: on_Part1_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 86: on_Part1_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 87: on_Part1_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 88: on_Part1_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 89: on_Part1_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 90: on_Part1_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 91: on_Part1_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 92: on_Part1_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 93: on_Part1_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 94: on_Part1_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 95: on_Part1_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 96: on_Part2_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 97: on_Part2_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 98: on_Part2_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 99: on_Part2_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 100: on_Part2_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 101: on_Part2_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 102: on_Part2_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 103: on_Part2_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 104: on_Part2_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 105: on_Part2_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 106: on_Part2_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 107: on_Part2_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 108: on_Part2_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 109: on_Part2_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 110: on_Part2_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 111: on_Part2_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 112: on_Part2_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 113: on_Part2_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 114: on_Part2_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 115: on_Part3_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 116: on_Part3_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 117: on_Part3_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 118: on_Part3_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 119: on_Part3_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 120: on_Part3_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 121: on_Part3_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 122: on_Part3_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 123: on_Part3_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 124: on_Part3_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 125: on_Part3_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 126: on_Part3_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 127: on_Part3_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 128: on_Part3_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 129: on_Part3_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 130: on_Part3_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 131: on_Part3_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 132: on_Part3_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 133: on_Part3_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 134: on_Part4_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 135: on_Part4_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 136: on_Part4_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 137: on_Part4_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 138: on_Part4_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 139: on_Part4_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 140: on_Part4_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 141: on_Part4_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 142: on_Part4_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 143: on_Part4_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 144: on_Part4_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 145: on_Part4_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 146: on_Part4_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 147: on_Part4_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 148: on_Part4_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 149: on_Part4_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 150: on_Part4_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 151: on_Part4_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 152: on_Part4_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 153: on_Part5_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 154: on_Part5_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 155: on_Part5_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 156: on_Part5_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 157: on_Part5_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 158: on_Part5_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 159: on_Part5_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 160: on_Part5_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 161: on_Part5_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 162: on_Part5_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 163: on_Part5_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 164: on_Part5_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 165: on_Part5_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 166: on_Part5_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 167: on_Part5_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 168: on_Part5_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 169: on_Part5_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 170: on_Part5_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 171: on_Part5_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 172: on_Part6_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 173: on_Part6_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 174: on_Part6_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 175: on_Part6_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 176: on_Part6_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 177: on_Part6_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 178: on_Part6_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 179: on_Part6_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 180: on_Part6_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 181: on_Part6_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 182: on_Part6_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 183: on_Part6_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 184: on_Part6_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 185: on_Part6_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 186: on_Part6_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 187: on_Part6_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 188: on_Part6_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 189: on_Part6_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 190: on_Part6_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 191: on_Part7_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 192: on_Part7_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 193: on_Part7_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 194: on_Part7_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 195: on_Part7_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 196: on_Part7_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 197: on_Part7_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 198: on_Part7_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 199: on_Part7_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 200: on_Part7_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 201: on_Part7_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 202: on_Part7_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 203: on_Part7_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 204: on_Part7_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 205: on_Part7_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 206: on_Part7_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 207: on_Part7_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 208: on_Part7_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 209: on_Part7_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 210: on_Part8_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 211: on_Part8_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 212: on_Part8_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 213: on_Part8_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 214: on_Part8_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 215: on_Part8_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 216: on_Part8_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 217: on_Part8_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 218: on_Part8_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 219: on_Part8_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 220: on_Part8_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 221: on_Part8_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 222: on_Part8_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 223: on_Part8_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 224: on_Part8_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 225: on_Part8_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 226: on_Part8_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 227: on_Part8_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 228: on_Part8_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 229: on_Part9_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 230: on_Part9_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 231: on_Part9_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 232: on_Part9_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 233: on_Part9_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 234: on_Part9_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 235: on_Part9_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 236: on_Part9_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 237: on_Part9_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 238: on_Part9_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 239: on_Part9_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 240: on_Part9_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 241: on_Part9_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 242: on_Part9_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 243: on_Part9_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 244: on_Part9_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 245: on_Part9_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 246: on_Part9_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 247: on_Part9_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 248: on_Part10_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 249: on_Part10_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 250: on_Part10_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 251: on_Part10_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 252: on_Part10_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 253: on_Part10_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 254: on_Part10_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 255: on_Part10_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 256: on_Part10_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 257: on_Part10_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 258: on_Part10_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 259: on_Part10_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 260: on_Part10_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 261: on_Part10_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 262: on_Part10_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 263: on_Part10_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 264: on_Part10_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 265: on_Part10_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 266: on_Part10_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 267: on_Part11_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 268: on_Part11_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 269: on_Part11_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 270: on_Part11_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 271: on_Part11_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 272: on_Part11_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 273: on_Part11_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 274: on_Part11_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 275: on_Part11_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 276: on_Part11_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 277: on_Part11_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 278: on_Part11_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 279: on_Part11_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 280: on_Part11_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 281: on_Part11_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 282: on_Part11_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 283: on_Part11_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 284: on_Part11_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 285: on_Part11_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 286: on_Part12_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 287: on_Part12_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 288: on_Part12_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 289: on_Part12_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 290: on_Part12_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 291: on_Part12_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 292: on_Part12_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 293: on_Part12_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 294: on_Part12_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 295: on_Part12_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 296: on_Part12_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 297: on_Part12_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 298: on_Part12_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 299: on_Part12_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 300: on_Part12_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 301: on_Part12_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 302: on_Part12_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 303: on_Part12_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 304: on_Part12_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 305: on_Part13_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 306: on_Part13_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 307: on_Part13_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 308: on_Part13_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 309: on_Part13_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 310: on_Part13_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 311: on_Part13_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 312: on_Part13_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 313: on_Part13_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 314: on_Part13_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 315: on_Part13_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 316: on_Part13_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 317: on_Part13_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 318: on_Part13_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 319: on_Part13_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 320: on_Part13_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 321: on_Part13_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 322: on_Part13_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 323: on_Part13_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 324: on_Part14_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 325: on_Part14_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 326: on_Part14_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 327: on_Part14_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 328: on_Part14_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 329: on_Part14_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 330: on_Part14_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 331: on_Part14_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 332: on_Part14_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 333: on_Part14_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 334: on_Part14_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 335: on_Part14_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 336: on_Part14_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 337: on_Part14_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 338: on_Part14_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 339: on_Part14_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 340: on_Part14_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 341: on_Part14_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 342: on_Part14_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 343: on_Part15_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 344: on_Part15_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 345: on_Part15_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 346: on_Part15_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 347: on_Part15_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 348: on_Part15_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 349: on_Part15_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 350: on_Part15_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 351: on_Part15_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 352: on_Part15_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 353: on_Part15_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 354: on_Part15_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 355: on_Part15_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 356: on_Part15_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 357: on_Part15_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 358: on_Part15_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 359: on_Part15_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 360: on_Part15_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 361: on_Part15_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 362: on_Part16_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 363: on_Part16_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 364: on_Part16_VoiceReserve_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 365: on_Part16_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 366: on_Part16_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 367: on_Part16_PatchNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 368: on_Part16_PatchGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 369: on_Part16_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 370: on_Part16_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 371: on_Part16_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 372: on_Part16_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 373: on_Part16_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 374: on_Part16_ReceiveMidi_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 375: on_Part16_ReceivePrgChg_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 376: on_Part16_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 377: on_Part16_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 378: on_Part16_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 379: on_Part16_MidiChannel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 380: on_Part16_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 381: slotPerfEFXsource((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 382: slotPerfEFXtype((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 383: slotPatchEFXtype((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 384: slotEFXoutput((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 385: slotEFXreverbSend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 386: slotEFXchorusSend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 387: slotEFXoutputLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 388: slotEFXcontrol1Depth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 389: slotEFXcontrol2Depth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 390: slotEFXcontrolSource1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 391: slotEFXcontrolSource2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 392: slotEFXparm1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 393: slotEFXparm2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 394: slotEFXparm3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 395: slotEFXparm4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 396: slotEFXparm5((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 397: slotEFXparm6((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 398: slotEFXparm7((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 399: slotEFXparm8((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 400: slotEFXparm9((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 401: slotEFXparmA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 402: slotEFXparmB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 403: slotEFXparmC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 404: on_Patch_Sync_button_clicked(); break;
        case 405: on_Patch_Group_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 406: on_Patch_Number_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 407: on_Patch_Name_edit_editingFinished(); break;
        case 408: on_Patch_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 409: on_Patch_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 410: on_Patch_AnalogFeel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 411: on_Patch_PortamentoTime_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 412: on_Patch_BenderDown_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 413: on_Patch_BenderUp_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 414: on_Patch_HoldPeak_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 415: on_Patch_C1_HoldPeak_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 416: on_Patch_C2_HoldPeak_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 417: on_Patch_C3_HoldPeak_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 418: on_Patch_Struct12_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 419: on_Patch_Booster12_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 420: on_Patch_Struct34_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 421: on_Patch_Booster34_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 422: on_Patch_Tone1_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 423: on_Patch_Tone2_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 424: on_Patch_Tone3_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 425: on_Patch_Tone4_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 426: on_Patch_DefaultTempo_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 427: on_Patch_VoicePriority_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 428: on_Patch_VoiceMode_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 429: on_Patch_PortamentoEnable_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 430: on_Patch_PortamentoMode_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 431: on_Patch_PortamentoType_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 432: on_Patch_PortamentoStart_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 433: on_Patch_TestTone_switch_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 434: on_Patch_PerfPartNum_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 435: on_Patch_VelocityRange_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 436: on_Patch_ControlSource2_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 437: on_Patch_ControlSource3_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 438: on_Patch_SoloLegato_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 439: on_PatchEFX_ReverbHiFreqDamp_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 440: on_PatchEFX_ReverbLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 441: on_PatchEFX_ReverbTime_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 442: on_PatchEFX_ReverbType_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 443: on_PatchEFX_ReverbFeedback_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 444: on_PatchEFX_ChorusLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 445: on_PatchEFX_ChorusRate_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 446: on_PatchEFX_ChorusDepth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 447: on_PatchEFX_ChorusPreDelay_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 448: on_PatchEFX_ChorusFeedback_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 449: on_PatchEFX_ChorusOutput_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 450: on_PatchEFX_Control1Source_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 451: on_PatchEFX_Control2Source_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 452: on_PatchEFX_Control1Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 453: on_PatchEFX_Control2Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 454: on_ToneSync_button_clicked(); break;
        case 455: on_Tone_ToneNumber_select_valueChanged(); break;
        case 456: on_Tone_Number_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 457: on_Tone_Group_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 458: on_Tone_InstrFamily_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 459: on_Tone_WaveChooser_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 460: on_Tone_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 461: on_Tone_C1D1_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 462: on_Tone_C1D2_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 463: on_Tone_C1D3_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 464: on_Tone_C1D4_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 465: on_Tone_C2D1_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 466: on_Tone_C2D2_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 467: on_Tone_C2D3_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 468: on_Tone_C2D4_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 469: on_Tone_C3D1_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 470: on_Tone_C3D2_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 471: on_Tone_C3D3_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 472: on_Tone_C3D4_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 473: on_Tone_WaveGain_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 474: on_Tone_DelayMode_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 475: on_Tone_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 476: on_Tone_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 477: on_Tone_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 478: on_Tone_Level_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 479: on_Tone_VeloXfadeDepth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 480: on_Tone_VeloLowerRange_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 481: on_Tone_DelayTime_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 482: on_Tone_VeloUpperRange_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 483: on_Tone_C1D1Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 484: on_Tone_C1D2Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 485: on_Tone_C1D3Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 486: on_Tone_C1D4Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 487: on_Tone_C2D1Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 488: on_Tone_C2D2Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 489: on_Tone_C2D3Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 490: on_Tone_C2D4Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 491: on_Tone_C3D1Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 492: on_Tone_C3D2Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 493: on_Tone_C3D3Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 494: on_Tone_C3D4Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 495: on_Tone_ReceiveVolume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 496: on_Tone_ReceiveHold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 497: on_Tone_ReceiveReDamper_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 498: on_Tone_ReceiveBender_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 499: on_Tone_FXM_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 500: on_Tone_FXMColor_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 501: on_Tone_FXMDepth_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 502: on_ToneEFX_LFO1FadeTime_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 503: on_ToneEFX_LFO2FadeTime_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 504: on_ToneEFX_LFO1Delay_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 505: on_ToneEFX_LFO1Rate_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 506: on_ToneEFX_LFO2Rate_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 507: on_ToneEFX_LFO2Delay_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 508: on_ToneEFX_LFO1KeyTrigger_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 509: on_ToneEFX_LFO2KeyTrigger_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 510: on_ToneEFX_LFO1LevelOffset_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 511: on_ToneEFX_LFO2LevelOffset_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 512: on_ToneEFX_LF01Waveform_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 513: on_ToneEFX_LFO1FadeMode_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 514: on_ToneEFX_LFO1ExtSync_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 515: on_ToneEFX_LF02Waveform_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 516: on_ToneEFX_LFO2FadeMode_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 517: on_ToneEFX_LFO2ExtSync_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 518: on_ToneEFX_PanControl_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 519: on_ToneEFX_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 520: on_ToneEFX_PanKeyFollow_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 521: on_ToneEFX_PanRandDepth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 522: on_ToneEFX_AltPan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 523: on_ToneEFX_PanLFO1Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 524: on_ToneEFX_PanLFO2Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 525: on_ToneTVA_Time1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 526: on_ToneTVA_Time2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 527: on_ToneTVA_Time3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 528: on_ToneTVA_Time4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 529: on_ToneTVA_Lvl1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 530: on_ToneTVA_Lvl2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 531: on_ToneTVA_Lvl3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 532: on_ToneTVA_LFO1Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 533: on_ToneTVA_LFO2Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 534: on_ToneTVA_VelocSens_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 535: on_ToneTVA_BiasPoint_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 536: on_ToneTVA_BiasDirection_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 537: on_ToneTVA_Time1Sens_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 538: on_ToneTVA_Time4Sens_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 539: on_ToneTVA_VelocityCurve_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 540: on_ToneTVA_TimeKeyfollow_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 541: on_ToneTVA_BiasLvl_select_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 542: on_ToneTVF_Time1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 543: on_ToneTVF_Time2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 544: on_ToneTVF_Time3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 545: on_ToneTVF_Time4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 546: on_ToneTVF_Lvl1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 547: on_ToneTVF_Lvl2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 548: on_ToneTVF_Lvl3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 549: on_ToneTVF_Lvl4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 550: on_ToneTVF_LFO1Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 551: on_ToneTVF_LFO2Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 552: on_ToneTVF_VelocSens_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 553: on_ToneTVF_ResVelocSens_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 554: on_ToneTVF_Resonance_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 555: on_ToneTVF_Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 556: on_ToneTVF_TimeKeyfollow_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 557: on_ToneTVF_Time1Sens_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 558: on_ToneTVF_Time4Sens_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 559: on_ToneTVF_VelocityCurve_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 560: on_ToneTVF_FilterType_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 561: on_ToneTVF_CutoffKeyfollow_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 562: on_ToneTVF_CutoffFreq_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 563: on_Pitch_StretchTuning_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 564: on_Pitch_HighLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 565: on_Pitch_LowLimit_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 566: on_Pitch_TimeKeyfollow_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 567: on_Pitch_RandPitchDepth_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 568: on_Pitch_Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 569: on_Pitch_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 570: on_Pitch_Transpose_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 571: on_Pitch_OctaveShift_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 572: on_Pitch_KeyFollow_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 573: on_Pitch_Time1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 574: on_Pitch_Time2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 575: on_Pitch_Time3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 576: on_Pitch_Time4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 577: on_Pitch_Lvl1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 578: on_Pitch_Lvl2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 579: on_Pitch_Lvl3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 580: on_Pitch_Lvl4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 581: on_Pitch_LFO1Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 582: on_Pitch_LFO2Depth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 583: on_Pitch_VelocSens_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 584: on_Pitch_Time1Sens_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 585: on_Pitch_Time4Sens_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 586: on_Tuning_ScaleTuning_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 587: on_Tuning_Sync_button_clicked(); break;
        case 588: on_Tuning_PartTune_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 589: on_Tuning_MasterTune_select_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 590: slotTuning_TempButtons((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 591: on_Tuning_LoadCustomTemp_button_clicked(); break;
        case 592: on_Tuning_SaveCustomTemp_button_clicked(); break;
        case 593: on_Tuning_BaseKey_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 594: on_Tuning_PartTuneA_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 595: on_Tuning_PartTuneAs_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 596: on_Tuning_PartTuneB_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 597: on_Tuning_PartTuneC_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 598: on_Tuning_PartTuneCs_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 599: on_Tuning_PartTuneD_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 600: on_Tuning_PartTuneDs_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 601: on_Tuning_PartTuneE_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 602: on_Tuning_PartTuneF_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 603: on_Tuning_PartTuneFs_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 604: on_Tuning_PartTuneG_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 605: on_Tuning_PartTuneGs_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 606: Tuning_QueryTemp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 607: Tuning_setScaleTuning((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 608: on_Rhythm_Sync_button_clicked(); break;
        case 609: on_Rhythm_EnvMode_select_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 610: on_Rhythm_Note_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 611: on_Rhythm_Hold_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 612: on_Rhythm_Volume_enable_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 613: on_Rhythm_WaveGroup_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 614: on_Rhythm_WaveGain_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 615: on_Rhythm_Output_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 616: on_Rhythm_PanControl_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 617: on_Rhythm_RandPitchDepth_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 618: on_Rhythm_TVAVelTimeSens_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 619: on_Rhythm_TVFFilterType_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 620: on_Rhythm_TVFVelTimeSens_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 621: on_Rhythm_WaveNumber_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 622: on_Rhythm_MuteGroup_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 623: on_Rhythm_PanRandDepth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 624: on_Rhythm_PitchDepth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 625: on_Rhythm_TVFDepth_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 626: on_Rhythm_KeyPress_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 627: on_Rhythm_OutputLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 628: on_Rhythm_ChorusSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 629: on_Rhythm_ReverbSend_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 630: on_Rhythm_Pan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 631: on_Rhythm_AltPan_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 632: on_Rhythm_PitchTime1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 633: on_Rhythm_PitchTime2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 634: on_Rhythm_PitchTime3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 635: on_Rhythm_PitchTime4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 636: on_Rhythm_PitchLvl1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 637: on_Rhythm_PitchLvl2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 638: on_Rhythm_PitchLvl3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 639: on_Rhythm_PitchLvl4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 640: on_Rhythm_PitchVelocSens_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 641: on_Rhythm_TVATime1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 642: on_Rhythm_TVATime2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 643: on_Rhythm_TVATime3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 644: on_Rhythm_TVATime4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 645: on_Rhythm_TVALvl1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 646: on_Rhythm_TVALvl2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 647: on_Rhythm_TVALvl3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 648: on_Rhythm_TVAVelocSens_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 649: on_Rhythm_TVFTime1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 650: on_Rhythm_TVFTime2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 651: on_Rhythm_TVFTime3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 652: on_Rhythm_TVFTime4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 653: on_Rhythm_TVFLvl2_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 654: on_Rhythm_TVFLvl3_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 655: on_Rhythm_TVFLvl4_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 656: on_Rhythm_TVFLvl1_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 657: on_Rhythm_TVFResVelocSens_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 658: on_Rhythm_TVFCutoffFreq_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 659: on_Rhythm_TVFResonance_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 660: on_Rhythm_TVFVelocSens_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 661: on_Rhythm_SoundingPitch_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 662: on_Rhythm_BenderRange_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 663: on_Rhythm_PitchVeloTime_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 664: on_Rhythm_ToneLevel_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 665: on_Rhythm_TuneAdj_select_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 666: on_Rhythm_TestTone_switch_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 667;
    }
    return _id;
}

// SIGNAL 0
void JVlibForm::noteval(const QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
