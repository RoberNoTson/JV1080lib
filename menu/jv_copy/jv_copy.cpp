// jv_copy.cpp
/* Contains:
 * JV_COPY
 * ~JV_COPY
 * on_Copy_buttonBox_accepted
 * on_Copy_buttonBox_rejected
 * on_Copy_buttonBox_helpRequested
 * on_Copy_Source_type_currentIndexChanged
 * on_Copy_Source_select_currentIndexChanged
 * on_Copy_Source_value_valueChanged
 * on_Copy_Source_Subtype_value_valueChanged
 * on_Copy_Dest_Subtype_value_valueChanged
 */

#include "jv_copy.h"
#include "ui_jv_copy.h"
#include "JVlibForm.h"
#include        <QtGui>
#include	<QtSql>

JV_COPY::JV_COPY(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JV_COPY)
{
    ui->setupUi(this);
    ui->Copy_Source_type->clear();
    ui->Copy_Source_select->clear();
    ui->Copy_Source_name->clear();
    ui->Copy_Source_Subtype_name->clear();
    ui->Copy_Dest_name->clear();
    ui->Copy_Dest_Subtype_name->clear();
    if (JVlibForm::state_table->perf_mode) {
      if (!JVlibForm::state_table->performance_sync) return;
      ui->Copy_Source_type->addItem("Perf Part");
      ui->Copy_Source_type->addItem("Perf FX");
      ui->Copy_Source_type->addItem("Patch FX");
      ui->Copy_Source_select->addItem("Temp");
      ui->Copy_Source_select->addItem("User");
      ui->Copy_Source_select->addItem("Preset A");
      ui->Copy_Source_select->addItem("Preset B");
      ui->Copy_Source_value->setRange(1,32);
      ui->Copy_Source_value->setValue(1);
      ui->Copy_Source_subtype->setText("Part Number");
      ui->Copy_Source_Subtype_value->setRange(1,16);
      ui->Copy_Source_Subtype_value->setValue(1);
      ui->Copy_Dest_type->setText("Active Performance");
      ui->Copy_Dest_subtype->setText("Part Number");
      ui->Copy_Dest_Subtype_value->setRange(1,16);
      ui->Copy_Dest_Subtype_value->setValue(1);
      QString tname = QString(JVlibForm::state_table->perf_group)+" "+QString::number(JVlibForm::state_table->perf_num)+
      "\n"+QString(JVlibForm::state_table->perf_name);
      ui->Copy_Dest_name->setText(tname);
ui->Copy_Dest_Subtype_name->setText("User 1\nViolin 1");
    }
    else if (JVlibForm::state_table->patch_mode) {
      if (!JVlibForm::state_table->patch_sync) return;
      ui->Copy_Source_type->addItem("Patch Tone");
      ui->Copy_Source_type->addItem("Patch FX");
      ui->Copy_Source_select->addItem("Temp");
      ui->Copy_Source_select->addItem("User");
      ui->Copy_Source_select->addItem("Expansion A");
      ui->Copy_Source_select->addItem("Preset A");
      ui->Copy_Source_select->addItem("Preset B");
      ui->Copy_Source_select->addItem("Preset C");
      ui->Copy_Source_select->addItem("Preset D");
      ui->Copy_Source_select->addItem("Expansion B");
      ui->Copy_Source_select->addItem("Expansion C");
      ui->Copy_Source_value->setRange(1,128);
      ui->Copy_Source_value->setValue(1);
      ui->Copy_Source_subtype->setText("Tone Number");
      ui->Copy_Source_Subtype_value->setRange(1,4);
      ui->Copy_Source_Subtype_value->setValue(1);
      ui->Copy_Dest_type->setText("Active Patch");
      ui->Copy_Dest_subtype->setText("Tone Number");
      ui->Copy_Dest_Subtype_value->setRange(1,4);
      ui->Copy_Dest_Subtype_value->setValue(1);
      QString tname = QString(JVlibForm::state_table->patch_group)+" "+QString::number(JVlibForm::state_table->patch_num)+
      "\n"+QString(JVlibForm::state_table->patch_name);
      ui->Copy_Dest_name->setText(tname);
    }
    else if (JVlibForm::state_table->rhythm_mode) {
      if (!JVlibForm::state_table->rhythm_sync) return;
      ui->Copy_Source_type->addItem("Rhythm Note");
      ui->Copy_Source_select->addItem("Temp");
      ui->Copy_Source_select->addItem("User");
      ui->Copy_Source_select->addItem("Preset A");
      ui->Copy_Source_select->addItem("Preset B");
      ui->Copy_Source_select->addItem("Preset C");
      ui->Copy_Source_select->addItem("Preset D");
      ui->Copy_Source_select->addItem("Expansion B");
      ui->Copy_Source_value->setRange(1,2);
      ui->Copy_Source_value->setValue(1);
      ui->Copy_Source_subtype->setText("Note Number");
      ui->Copy_Source_Subtype_value->setRange(35,98);
      ui->Copy_Source_Subtype_value->setValue(35);
      ui->Copy_Dest_type->setText("Active Rhythm");
      ui->Copy_Dest_subtype->setText("Note Number");
      ui->Copy_Dest_Subtype_value->setRange(35,98);
      ui->Copy_Dest_Subtype_value->setValue(35);
      QString tname = QString(JVlibForm::state_table->rhythm_group)+" "+QString::number(JVlibForm::state_table->rhythm_num)+
      "\n"+QString(JVlibForm::state_table->rhythm_name);
      ui->Copy_Dest_name->setText(tname);
    }
}	// end JV_COPY constructor

JV_COPY::~JV_COPY()
{
    delete ui;
}

void JV_COPY::on_Copy_buttonBox_accepted() {
  
  this->close();
}
void JV_COPY::on_Copy_buttonBox_rejected() {
  this->close();
}
void JV_COPY::on_Copy_buttonBox_helpRequested() {
  QMessageBox::critical(this, "Copy Dialog", "Help not yet available for this function");
}

void JV_COPY::on_Copy_Source_type_currentIndexChanged(int val) {
  if (JVlibForm::state_table->perf_mode) {
    if (val==0) {	// Perf Part Copy
      ui->Copy_Source_subtype->setText("Part Number");
      if (ui->Copy_Source_select->count()>4) {
	ui->Copy_Source_select->removeItem(5);
	ui->Copy_Source_select->removeItem(4);
      }
      if (!ui->Copy_Source_subtype->isVisible())
	ui->Copy_Source_subtype->show();
      if (!ui->Copy_Source_Subtype_value->isVisible())
	ui->Copy_Source_Subtype_value->show();
      if (!ui->Copy_Source_Subtype_name->isVisible())
	ui->Copy_Source_Subtype_name->show();
    }
    else if (val==1) {	// Perf FX copy
      if (ui->Copy_Source_select->count()>4) {
	ui->Copy_Source_select->removeItem(5);
	ui->Copy_Source_select->removeItem(4);
      }
      if (ui->Copy_Source_subtype->isVisible())
	ui->Copy_Source_subtype->hide();
      if (ui->Copy_Source_Subtype_value->isVisible())
	ui->Copy_Source_Subtype_value->hide();
      if (ui->Copy_Source_Subtype_name->isVisible())
	ui->Copy_Source_Subtype_name->hide();
    }
    else if (val==2) {	// PatchFX to Perf copy
      ui->Copy_Source_subtype->setText("Patch Number");
      if (ui->Copy_Source_select->count()==4) {
	ui->Copy_Source_select->addItem("Preset C");
	ui->Copy_Source_select->addItem("Preset D");
      }
      if (ui->Copy_Source_subtype->isVisible())
	ui->Copy_Source_subtype->hide();
      if (ui->Copy_Source_Subtype_value->isVisible())
	ui->Copy_Source_Subtype_value->hide();
      if (ui->Copy_Source_Subtype_name->isVisible())
	ui->Copy_Source_Subtype_name->hide();
    }
  }
  else if (JVlibForm::state_table->patch_mode) {
    if (val==0) {	// Patch Copy
    }
    else if (val==1) {	// Patch FX copy
    }
  }
  else if (JVlibForm::state_table->rhythm_mode) {
  }
}

void JV_COPY::on_Copy_Source_select_currentIndexChanged(QString t_name) {
//  int pn = ui->Copy_Source_value->value() - 1;
  if (t_name == "Temp") {
    if (JVlibForm::state_table->perf_mode) {
    }
  }
  else if (t_name == "User") {}
  else if (t_name == "Preset A") {}
  else if (t_name == "Preset B") {}
  else if (t_name == "Preset C") {}
  else if (t_name == "Preset D") {}
  else if (t_name == "Expansion A") {}
  else if (t_name == "Expansion B") {}
  else if (t_name == "Expansion C") {}
  else if (t_name == "Expansion D") {}
  
}	// end on_Copy_Source_select_currentIndexChanged

void JV_COPY::on_Copy_Source_value_valueChanged(int val) {
//  int pn = val-1;
}
void JV_COPY::on_Copy_Source_Subtype_value_valueChanged(int val) {
//  int pn = val-1;
}
void JV_COPY::on_Copy_Dest_Subtype_value_valueChanged(int val) {
//  int pn = val-1;
}

