// parts_slots.cpp
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::on_PartsRangeLimitEnable_select_toggled(bool val) {
    setPerfSingleValue(0x2F ,val);
}	// end on_PartsRangeLimitEnable_select_toggled
