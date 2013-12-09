/****************************************************************************
** Meta object code from reading C++ file 'blackjack_canvas.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "blackjack_canvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blackjack_canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BlackjackCanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   16,   16,   16, 0x0a,
      61,   16,   16,   16, 0x0a,
      72,   16,   16,   16, 0x0a,
      85,   16,   16,   16, 0x0a,
      97,   16,   16,   16, 0x0a,
     111,   16,  107,   16, 0x0a,
     125,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BlackjackCanvas[] = {
    "BlackjackCanvas\0\0str\0needsButtonChange(QString)\0"
    "startPress()\0hitPress()\0standPress()\0"
    "dealPress()\0newHand()\0int\0computerHit()\0"
    "countPress()\0"
};

void BlackjackCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BlackjackCanvas *_t = static_cast<BlackjackCanvas *>(_o);
        switch (_id) {
        case 0: _t->needsButtonChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->startPress(); break;
        case 2: _t->hitPress(); break;
        case 3: _t->standPress(); break;
        case 4: _t->dealPress(); break;
        case 5: _t->newHand(); break;
        case 6: { int _r = _t->computerHit();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->countPress(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BlackjackCanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BlackjackCanvas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BlackjackCanvas,
      qt_meta_data_BlackjackCanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BlackjackCanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BlackjackCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BlackjackCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BlackjackCanvas))
        return static_cast<void*>(const_cast< BlackjackCanvas*>(this));
    return QWidget::qt_metacast(_clname);
}

int BlackjackCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void BlackjackCanvas::needsButtonChange(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
