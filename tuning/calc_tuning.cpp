// calc_tuning.cpp
// set the Tuning Tab display to the current temperament and key
#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::calc_tuning() {
int C = Tuning_PartTuneC_select->value()+0x40;
int Cs = Tuning_PartTuneCs_select->value()+0x40;
int D = Tuning_PartTuneD_select->value()+0x40;
int Ds = Tuning_PartTuneDs_select->value()+0x40;
int E = Tuning_PartTuneE_select->value()+0x40;
int F = Tuning_PartTuneF_select->value()+0x40;
int Fs = Tuning_PartTuneFs_select->value()+0x40;
int G = Tuning_PartTuneG_select->value()+0x40;
int Gs = Tuning_PartTuneGs_select->value()+0x40;
int A = Tuning_PartTuneA_select->value()+0x40;
int As = Tuning_PartTuneAs_select->value()+0x40;
int B = Tuning_PartTuneB_select->value()+0x40;
Tuning_ButtonGroup->blockSignals(true);
// Equal Temperament
if(A==0x40 && As==0x40 && B==0x40 && C==0x40 && Cs==0x40 && D==0x40 && Ds==0x40 && E==0x40 && F==0x40 && Fs==0x40 && G==0x40 && Gs==0x40)
  { state_table->tuning_type=EqualTemp; Tuning_EqualTemp_button->setChecked(true); 
    Tuning_BaseKey_C_select->setChecked(true); Tuning_QueryTemp(0); }
// Just tuning
else if(C==Tuning_Just.at(0) && Cs==Tuning_Just.at(1) && D==Tuning_Just.at(2) && Ds==Tuning_Just.at(3) &&
     E==Tuning_Just.at(4) && F==Tuning_Just.at(5) && Fs==Tuning_Just.at(6) && G==Tuning_Just.at(7) &&
     Gs==Tuning_Just.at(8) && A==Tuning_Just.at(9) && As==Tuning_Just.at(10) && B==Tuning_Just.at(11) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_C_select->setChecked(true); }
else if(C==Tuning_Just.at(1) && Cs==Tuning_Just.at(2) && D==Tuning_Just.at(3) && Ds==Tuning_Just.at(4) &&
      E==Tuning_Just.at(5) && F==Tuning_Just.at(6) && Fs==Tuning_Just.at(7) && G==Tuning_Just.at(8) &&
      Gs==Tuning_Just.at(9) && A==Tuning_Just.at(10) && As==Tuning_Just.at(11) && B==Tuning_Just.at(0) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_B_select->setChecked(true); }
else if(C==Tuning_Just.at(2) && Cs==Tuning_Just.at(3) && D==Tuning_Just.at(4) && Ds==Tuning_Just.at(5) &&
      E==Tuning_Just.at(6) && F==Tuning_Just.at(7) && Fs==Tuning_Just.at(8) && G==Tuning_Just.at(9) &&
      Gs==Tuning_Just.at(10) && A==Tuning_Just.at(11) && As==Tuning_Just.at(0) && B==Tuning_Just.at(1) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_As_select->setChecked(true); }
else if(C==Tuning_Just.at(3) && Cs==Tuning_Just.at(4) && D==Tuning_Just.at(5) && Ds==Tuning_Just.at(6) &&
      E==Tuning_Just.at(7) && F==Tuning_Just.at(8) && Fs==Tuning_Just.at(9) && G==Tuning_Just.at(10) &&
      Gs==Tuning_Just.at(11) && A==Tuning_Just.at(0) && As==Tuning_Just.at(1) && B==Tuning_Just.at(2) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_A_select->setChecked(true); }
else if(C==Tuning_Just.at(4) && Cs==Tuning_Just.at(5) && D==Tuning_Just.at(6) && Ds==Tuning_Just.at(7) &&
      E==Tuning_Just.at(8) && F==Tuning_Just.at(9) && Fs==Tuning_Just.at(10) && G==Tuning_Just.at(11) &&
      Gs==Tuning_Just.at(0) && A==Tuning_Just.at(1) && As==Tuning_Just.at(2) && B==Tuning_Just.at(3) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_Gs_select->setChecked(true); }
else if(C==Tuning_Just.at(5) && Cs==Tuning_Just.at(6) && D==Tuning_Just.at(7) && Ds==Tuning_Just.at(8) &&
      E==Tuning_Just.at(9) && F==Tuning_Just.at(10) && Fs==Tuning_Just.at(11) && G==Tuning_Just.at(0) &&
      Gs==Tuning_Just.at(1) && A==Tuning_Just.at(2) && As==Tuning_Just.at(3) && B==Tuning_Just.at(4) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_G_select->setChecked(true); }
else if(C==Tuning_Just.at(6) && Cs==Tuning_Just.at(7) && D==Tuning_Just.at(8) && Ds==Tuning_Just.at(9) &&
      E==Tuning_Just.at(10) && F==Tuning_Just.at(11) && Fs==Tuning_Just.at(0) && G==Tuning_Just.at(1) &&
      Gs==Tuning_Just.at(2) && A==Tuning_Just.at(3) && As==Tuning_Just.at(4) && B==Tuning_Just.at(5) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_Fs_select->setChecked(true); }
else if(C==Tuning_Just.at(7) && Cs==Tuning_Just.at(8) && D==Tuning_Just.at(9) && Ds==Tuning_Just.at(10) &&
      E==Tuning_Just.at(11) && F==Tuning_Just.at(0) && Fs==Tuning_Just.at(1) && G==Tuning_Just.at(2) &&
      Gs==Tuning_Just.at(3) && A==Tuning_Just.at(4) && As==Tuning_Just.at(5) && B==Tuning_Just.at(6) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_F_select->setChecked(true); }
else if(C==Tuning_Just.at(8) && Cs==Tuning_Just.at(9) && D==Tuning_Just.at(10) && Ds==Tuning_Just.at(11) &&
      E==Tuning_Just.at(0) && F==Tuning_Just.at(1) && Fs==Tuning_Just.at(2) && G==Tuning_Just.at(3) &&
      Gs==Tuning_Just.at(4) && A==Tuning_Just.at(5) && As==Tuning_Just.at(6) && B==Tuning_Just.at(7) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_E_select->setChecked(true); }
else if(C==Tuning_Just.at(9) && Cs==Tuning_Just.at(10) && D==Tuning_Just.at(11) && Ds==Tuning_Just.at(0) &&
      E==Tuning_Just.at(1) && F==Tuning_Just.at(2) && Fs==Tuning_Just.at(3) && G==Tuning_Just.at(4) &&
      Gs==Tuning_Just.at(5) && A==Tuning_Just.at(6) && As==Tuning_Just.at(7) && B==Tuning_Just.at(8) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_Ds_select->setChecked(true); }
else if(C==Tuning_Just.at(10) && Cs==Tuning_Just.at(11) && D==Tuning_Just.at(0) && Ds==Tuning_Just.at(1) &&
      E==Tuning_Just.at(2) && F==Tuning_Just.at(3) && Fs==Tuning_Just.at(4) && G==Tuning_Just.at(5) &&
      Gs==Tuning_Just.at(6) && A==Tuning_Just.at(7) && As==Tuning_Just.at(8) && B==Tuning_Just.at(9) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_D_select->setChecked(true); }
else if(C==Tuning_Just.at(11) && Cs==Tuning_Just.at(0) && D==Tuning_Just.at(1) && Ds==Tuning_Just.at(2) &&
      E==Tuning_Just.at(3) && F==Tuning_Just.at(4) && Fs==Tuning_Just.at(5) && G==Tuning_Just.at(6) &&
      Gs==Tuning_Just.at(7) && A==Tuning_Just.at(8) && As==Tuning_Just.at(9) && B==Tuning_Just.at(10) )
  { Tuning_JustTemp_button->setChecked(true); state_table->tuning_type=JustTemp;
    Tuning_QueryTemp(1); Tuning_BaseKey_Cs_select->setChecked(true); }
// Pythagorean tuning
else if(C==Tuning_Pythag.at(0) && Cs==Tuning_Pythag.at(1) && D==Tuning_Pythag.at(2) && Ds==Tuning_Pythag.at(3) &&
     E==Tuning_Pythag.at(4) && F==Tuning_Pythag.at(5) && Fs==Tuning_Pythag.at(6) && G==Tuning_Pythag.at(7) &&
     Gs==Tuning_Pythag.at(8) && A==Tuning_Pythag.at(9) && As==Tuning_Pythag.at(10) && B==Tuning_Pythag.at(11) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_C_select->setChecked(true); }
else if(C==Tuning_Pythag.at(1) && Cs==Tuning_Pythag.at(2) && D==Tuning_Pythag.at(3) && Ds==Tuning_Pythag.at(4) &&
      E==Tuning_Pythag.at(5) && F==Tuning_Pythag.at(6) && Fs==Tuning_Pythag.at(7) && G==Tuning_Pythag.at(8) &&
      Gs==Tuning_Pythag.at(9) && A==Tuning_Pythag.at(10) && As==Tuning_Pythag.at(11) && B==Tuning_Pythag.at(0) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_B_select->setChecked(true); }
else if(C==Tuning_Pythag.at(2) && Cs==Tuning_Pythag.at(3) && D==Tuning_Pythag.at(4) && Ds==Tuning_Pythag.at(5) &&
      E==Tuning_Pythag.at(6) && F==Tuning_Pythag.at(7) && Fs==Tuning_Pythag.at(8) && G==Tuning_Pythag.at(9) &&
      Gs==Tuning_Pythag.at(10) && A==Tuning_Pythag.at(11) && As==Tuning_Pythag.at(0) && B==Tuning_Pythag.at(1) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_As_select->setChecked(true); }
else if(C==Tuning_Pythag.at(3) && Cs==Tuning_Pythag.at(4) && D==Tuning_Pythag.at(5) && Ds==Tuning_Pythag.at(6) &&
      E==Tuning_Pythag.at(7) && F==Tuning_Pythag.at(8) && Fs==Tuning_Pythag.at(9) && G==Tuning_Pythag.at(10) &&
      Gs==Tuning_Pythag.at(11) && A==Tuning_Pythag.at(0) && As==Tuning_Pythag.at(1) && B==Tuning_Pythag.at(2) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_A_select->setChecked(true); }
else if(C==Tuning_Pythag.at(4) && Cs==Tuning_Pythag.at(5) && D==Tuning_Pythag.at(6) && Ds==Tuning_Pythag.at(7) &&
      E==Tuning_Pythag.at(8) && F==Tuning_Pythag.at(9) && Fs==Tuning_Pythag.at(10) && G==Tuning_Pythag.at(11) &&
      Gs==Tuning_Pythag.at(0) && A==Tuning_Pythag.at(1) && As==Tuning_Pythag.at(2) && B==Tuning_Pythag.at(3) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_Gs_select->setChecked(true); }
else if(C==Tuning_Pythag.at(5) && Cs==Tuning_Pythag.at(6) && D==Tuning_Pythag.at(7) && Ds==Tuning_Pythag.at(8) &&
      E==Tuning_Pythag.at(9) && F==Tuning_Pythag.at(10) && Fs==Tuning_Pythag.at(11) && G==Tuning_Pythag.at(0) &&
      Gs==Tuning_Pythag.at(1) && A==Tuning_Pythag.at(2) && As==Tuning_Pythag.at(3) && B==Tuning_Pythag.at(4) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_G_select->setChecked(true); }
else if(C==Tuning_Pythag.at(6) && Cs==Tuning_Pythag.at(7) && D==Tuning_Pythag.at(8) && Ds==Tuning_Pythag.at(9) &&
      E==Tuning_Pythag.at(10) && F==Tuning_Pythag.at(11) && Fs==Tuning_Pythag.at(0) && G==Tuning_Pythag.at(1) &&
      Gs==Tuning_Pythag.at(2) && A==Tuning_Pythag.at(3) && As==Tuning_Pythag.at(4) && B==Tuning_Pythag.at(5) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_Fs_select->setChecked(true); }
else if(C==Tuning_Pythag.at(7) && Cs==Tuning_Pythag.at(8) && D==Tuning_Pythag.at(9) && Ds==Tuning_Pythag.at(10) &&
      E==Tuning_Pythag.at(11) && F==Tuning_Pythag.at(0) && Fs==Tuning_Pythag.at(1) && G==Tuning_Pythag.at(2) &&
      Gs==Tuning_Pythag.at(3) && A==Tuning_Pythag.at(4) && As==Tuning_Pythag.at(5) && B==Tuning_Pythag.at(6) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_F_select->setChecked(true); }
else if(C==Tuning_Pythag.at(8) && Cs==Tuning_Pythag.at(9) && D==Tuning_Pythag.at(10) && Ds==Tuning_Pythag.at(11) &&
      E==Tuning_Pythag.at(0) && F==Tuning_Pythag.at(1) && Fs==Tuning_Pythag.at(2) && G==Tuning_Pythag.at(3) &&
      Gs==Tuning_Pythag.at(4) && A==Tuning_Pythag.at(5) && As==Tuning_Pythag.at(6) && B==Tuning_Pythag.at(7) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_E_select->setChecked(true); }
else if(C==Tuning_Pythag.at(9) && Cs==Tuning_Pythag.at(10) && D==Tuning_Pythag.at(11) && Ds==Tuning_Pythag.at(0) &&
      E==Tuning_Pythag.at(1) && F==Tuning_Pythag.at(2) && Fs==Tuning_Pythag.at(3) && G==Tuning_Pythag.at(4) &&
      Gs==Tuning_Pythag.at(5) && A==Tuning_Pythag.at(6) && As==Tuning_Pythag.at(7) && B==Tuning_Pythag.at(8) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_Ds_select->setChecked(true); }
else if(C==Tuning_Pythag.at(10) && Cs==Tuning_Pythag.at(11) && D==Tuning_Pythag.at(0) && Ds==Tuning_Pythag.at(1) &&
      E==Tuning_Pythag.at(2) && F==Tuning_Pythag.at(3) && Fs==Tuning_Pythag.at(4) && G==Tuning_Pythag.at(5) &&
      Gs==Tuning_Pythag.at(6) && A==Tuning_Pythag.at(7) && As==Tuning_Pythag.at(8) && B==Tuning_Pythag.at(9) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_D_select->setChecked(true); }
else if(C==Tuning_Pythag.at(11) && Cs==Tuning_Pythag.at(0) && D==Tuning_Pythag.at(1) && Ds==Tuning_Pythag.at(2) &&
      E==Tuning_Pythag.at(3) && F==Tuning_Pythag.at(4) && Fs==Tuning_Pythag.at(5) && G==Tuning_Pythag.at(6) &&
      Gs==Tuning_Pythag.at(7) && A==Tuning_Pythag.at(8) && As==Tuning_Pythag.at(9) && B==Tuning_Pythag.at(10) )
  { Tuning_PythagTemp_button->setChecked(true); state_table->tuning_type=PythagTemp; 
    Tuning_QueryTemp(2); Tuning_BaseKey_Cs_select->setChecked(true); }
// Pure
else if(C==Tuning_Pure.at(0) && Cs==Tuning_Pure.at(1) && D==Tuning_Pure.at(2) && Ds==Tuning_Pure.at(3) &&
     E==Tuning_Pure.at(4) && F==Tuning_Pure.at(5) && Fs==Tuning_Pure.at(6) && G==Tuning_Pure.at(7) &&
     Gs==Tuning_Pure.at(8) && A==Tuning_Pure.at(9) && As==Tuning_Pure.at(10) && B==Tuning_Pure.at(11) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_C_select->setChecked(true); }
else if(C==Tuning_Pure.at(1) && Cs==Tuning_Pure.at(2) && D==Tuning_Pure.at(3) && Ds==Tuning_Pure.at(4) &&
      E==Tuning_Pure.at(5) && F==Tuning_Pure.at(6) && Fs==Tuning_Pure.at(7) && G==Tuning_Pure.at(8) &&
      Gs==Tuning_Pure.at(9) && A==Tuning_Pure.at(10) && As==Tuning_Pure.at(11) && B==Tuning_Pure.at(0) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_B_select->setChecked(true); }
else if(C==Tuning_Pure.at(2) && Cs==Tuning_Pure.at(3) && D==Tuning_Pure.at(4) && Ds==Tuning_Pure.at(5) &&
      E==Tuning_Pure.at(6) && F==Tuning_Pure.at(7) && Fs==Tuning_Pure.at(8) && G==Tuning_Pure.at(9) &&
      Gs==Tuning_Pure.at(10) && A==Tuning_Pure.at(11) && As==Tuning_Pure.at(0) && B==Tuning_Pure.at(1) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_As_select->setChecked(true); }
else if(C==Tuning_Pure.at(3) && Cs==Tuning_Pure.at(4) && D==Tuning_Pure.at(5) && Ds==Tuning_Pure.at(6) &&
      E==Tuning_Pure.at(7) && F==Tuning_Pure.at(8) && Fs==Tuning_Pure.at(9) && G==Tuning_Pure.at(10) &&
      Gs==Tuning_Pure.at(11) && A==Tuning_Pure.at(0) && As==Tuning_Pure.at(1) && B==Tuning_Pure.at(2) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_A_select->setChecked(true); }
else if(C==Tuning_Pure.at(4) && Cs==Tuning_Pure.at(5) && D==Tuning_Pure.at(6) && Ds==Tuning_Pure.at(7) &&
      E==Tuning_Pure.at(8) && F==Tuning_Pure.at(9) && Fs==Tuning_Pure.at(10) && G==Tuning_Pure.at(11) &&
      Gs==Tuning_Pure.at(0) && A==Tuning_Pure.at(1) && As==Tuning_Pure.at(2) && B==Tuning_Pure.at(3) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_Gs_select->setChecked(true); }
else if(C==Tuning_Pure.at(5) && Cs==Tuning_Pure.at(6) && D==Tuning_Pure.at(7) && Ds==Tuning_Pure.at(8) &&
      E==Tuning_Pure.at(9) && F==Tuning_Pure.at(10) && Fs==Tuning_Pure.at(11) && G==Tuning_Pure.at(0) &&
      Gs==Tuning_Pure.at(1) && A==Tuning_Pure.at(2) && As==Tuning_Pure.at(3) && B==Tuning_Pure.at(4) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_G_select->setChecked(true); }
else if(C==Tuning_Pure.at(6) && Cs==Tuning_Pure.at(7) && D==Tuning_Pure.at(8) && Ds==Tuning_Pure.at(9) &&
      E==Tuning_Pure.at(10) && F==Tuning_Pure.at(11) && Fs==Tuning_Pure.at(0) && G==Tuning_Pure.at(1) &&
      Gs==Tuning_Pure.at(2) && A==Tuning_Pure.at(3) && As==Tuning_Pure.at(4) && B==Tuning_Pure.at(5) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_Fs_select->setChecked(true); }
else if(C==Tuning_Pure.at(7) && Cs==Tuning_Pure.at(8) && D==Tuning_Pure.at(9) && Ds==Tuning_Pure.at(10) &&
      E==Tuning_Pure.at(11) && F==Tuning_Pure.at(0) && Fs==Tuning_Pure.at(1) && G==Tuning_Pure.at(2) &&
      Gs==Tuning_Pure.at(3) && A==Tuning_Pure.at(4) && As==Tuning_Pure.at(5) && B==Tuning_Pure.at(6) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_F_select->setChecked(true); }
else if(C==Tuning_Pure.at(8) && Cs==Tuning_Pure.at(9) && D==Tuning_Pure.at(10) && Ds==Tuning_Pure.at(11) &&
      E==Tuning_Pure.at(0) && F==Tuning_Pure.at(1) && Fs==Tuning_Pure.at(2) && G==Tuning_Pure.at(3) &&
      Gs==Tuning_Pure.at(4) && A==Tuning_Pure.at(5) && As==Tuning_Pure.at(6) && B==Tuning_Pure.at(7) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_E_select->setChecked(true); }
else if(C==Tuning_Pure.at(9) && Cs==Tuning_Pure.at(10) && D==Tuning_Pure.at(11) && Ds==Tuning_Pure.at(0) &&
      E==Tuning_Pure.at(1) && F==Tuning_Pure.at(2) && Fs==Tuning_Pure.at(3) && G==Tuning_Pure.at(4) &&
      Gs==Tuning_Pure.at(5) && A==Tuning_Pure.at(6) && As==Tuning_Pure.at(7) && B==Tuning_Pure.at(8) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_Ds_select->setChecked(true); }
else if(C==Tuning_Pure.at(10) && Cs==Tuning_Pure.at(11) && D==Tuning_Pure.at(0) && Ds==Tuning_Pure.at(1) &&
      E==Tuning_Pure.at(2) && F==Tuning_Pure.at(3) && Fs==Tuning_Pure.at(4) && G==Tuning_Pure.at(5) &&
      Gs==Tuning_Pure.at(6) && A==Tuning_Pure.at(7) && As==Tuning_Pure.at(8) && B==Tuning_Pure.at(9) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_D_select->setChecked(true); }
else if(C==Tuning_Pure.at(11) && Cs==Tuning_Pure.at(0) && D==Tuning_Pure.at(1) && Ds==Tuning_Pure.at(2) &&
      E==Tuning_Pure.at(3) && F==Tuning_Pure.at(4) && Fs==Tuning_Pure.at(5) && G==Tuning_Pure.at(6) &&
      Gs==Tuning_Pure.at(7) && A==Tuning_Pure.at(8) && As==Tuning_Pure.at(9) && B==Tuning_Pure.at(10) )
  { Tuning_PureTemp_button->setChecked(true); state_table->tuning_type=PureTemp; 
    Tuning_QueryTemp(3); Tuning_BaseKey_Cs_select->setChecked(true); }

// Well-Tempered
else if(C==Tuning_Well.at(0) && Cs==Tuning_Well.at(1) && D==Tuning_Well.at(2) && Ds==Tuning_Well.at(3) &&
     E==Tuning_Well.at(4) && F==Tuning_Well.at(5) && Fs==Tuning_Well.at(6) && G==Tuning_Well.at(7) &&
     Gs==Tuning_Well.at(8) && A==Tuning_Well.at(9) && As==Tuning_Well.at(10) && B==Tuning_Well.at(11) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_C_select->setChecked(true); }
else if(C==Tuning_Well.at(1) && Cs==Tuning_Well.at(2) && D==Tuning_Well.at(3) && Ds==Tuning_Well.at(4) &&
      E==Tuning_Well.at(5) && F==Tuning_Well.at(6) && Fs==Tuning_Well.at(7) && G==Tuning_Well.at(8) &&
      Gs==Tuning_Well.at(9) && A==Tuning_Well.at(10) && As==Tuning_Well.at(11) && B==Tuning_Well.at(0) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_B_select->setChecked(true); }
else if(C==Tuning_Well.at(2) && Cs==Tuning_Well.at(3) && D==Tuning_Well.at(4) && Ds==Tuning_Well.at(5) &&
      E==Tuning_Well.at(6) && F==Tuning_Well.at(7) && Fs==Tuning_Well.at(8) && G==Tuning_Well.at(9) &&
      Gs==Tuning_Well.at(10) && A==Tuning_Well.at(11) && As==Tuning_Well.at(0) && B==Tuning_Well.at(1) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_As_select->setChecked(true); }
else if(C==Tuning_Well.at(3) && Cs==Tuning_Well.at(4) && D==Tuning_Well.at(5) && Ds==Tuning_Well.at(6) &&
      E==Tuning_Well.at(7) && F==Tuning_Well.at(8) && Fs==Tuning_Well.at(9) && G==Tuning_Well.at(10) &&
      Gs==Tuning_Well.at(11) && A==Tuning_Well.at(0) && As==Tuning_Well.at(1) && B==Tuning_Well.at(2) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_A_select->setChecked(true); }
else if(C==Tuning_Well.at(4) && Cs==Tuning_Well.at(5) && D==Tuning_Well.at(6) && Ds==Tuning_Well.at(7) &&
      E==Tuning_Well.at(8) && F==Tuning_Well.at(9) && Fs==Tuning_Well.at(10) && G==Tuning_Well.at(11) &&
      Gs==Tuning_Well.at(0) && A==Tuning_Well.at(1) && As==Tuning_Well.at(2) && B==Tuning_Well.at(3) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_Gs_select->setChecked(true); }
else if(C==Tuning_Well.at(5) && Cs==Tuning_Well.at(6) && D==Tuning_Well.at(7) && Ds==Tuning_Well.at(8) &&
      E==Tuning_Well.at(9) && F==Tuning_Well.at(10) && Fs==Tuning_Well.at(11) && G==Tuning_Well.at(0) &&
      Gs==Tuning_Well.at(1) && A==Tuning_Well.at(2) && As==Tuning_Well.at(3) && B==Tuning_Well.at(4) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_G_select->setChecked(true); }
else if(C==Tuning_Well.at(6) && Cs==Tuning_Well.at(7) && D==Tuning_Well.at(8) && Ds==Tuning_Well.at(9) &&
      E==Tuning_Well.at(10) && F==Tuning_Well.at(11) && Fs==Tuning_Well.at(0) && G==Tuning_Well.at(1) &&
      Gs==Tuning_Well.at(2) && A==Tuning_Well.at(3) && As==Tuning_Well.at(4) && B==Tuning_Well.at(5) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_Fs_select->setChecked(true); }
else if(C==Tuning_Well.at(7) && Cs==Tuning_Well.at(8) && D==Tuning_Well.at(9) && Ds==Tuning_Well.at(10) &&
      E==Tuning_Well.at(11) && F==Tuning_Well.at(0) && Fs==Tuning_Well.at(1) && G==Tuning_Well.at(2) &&
      Gs==Tuning_Well.at(3) && A==Tuning_Well.at(4) && As==Tuning_Well.at(5) && B==Tuning_Well.at(6) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_F_select->setChecked(true); }
else if(C==Tuning_Well.at(8) && Cs==Tuning_Well.at(9) && D==Tuning_Well.at(10) && Ds==Tuning_Well.at(11) &&
      E==Tuning_Well.at(0) && F==Tuning_Well.at(1) && Fs==Tuning_Well.at(2) && G==Tuning_Well.at(3) &&
      Gs==Tuning_Well.at(4) && A==Tuning_Well.at(5) && As==Tuning_Well.at(6) && B==Tuning_Well.at(7) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_E_select->setChecked(true); }
else if(C==Tuning_Well.at(9) && Cs==Tuning_Well.at(10) && D==Tuning_Well.at(11) && Ds==Tuning_Well.at(0) &&
      E==Tuning_Well.at(1) && F==Tuning_Well.at(2) && Fs==Tuning_Well.at(3) && G==Tuning_Well.at(4) &&
      Gs==Tuning_Well.at(5) && A==Tuning_Well.at(6) && As==Tuning_Well.at(7) && B==Tuning_Well.at(8) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_Ds_select->setChecked(true); }
else if(C==Tuning_Well.at(10) && Cs==Tuning_Well.at(11) && D==Tuning_Well.at(0) && Ds==Tuning_Well.at(1) &&
      E==Tuning_Well.at(2) && F==Tuning_Well.at(3) && Fs==Tuning_Well.at(4) && G==Tuning_Well.at(5) &&
      Gs==Tuning_Well.at(6) && A==Tuning_Well.at(7) && As==Tuning_Well.at(8) && B==Tuning_Well.at(9) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_D_select->setChecked(true); }
else if(C==Tuning_Well.at(11) && Cs==Tuning_Well.at(0) && D==Tuning_Well.at(1) && Ds==Tuning_Well.at(2) &&
      E==Tuning_Well.at(3) && F==Tuning_Well.at(4) && Fs==Tuning_Well.at(5) && G==Tuning_Well.at(6) &&
      Gs==Tuning_Well.at(7) && A==Tuning_Well.at(8) && As==Tuning_Well.at(9) && B==Tuning_Well.at(10) )
  { Tuning_WellTemp_button->setChecked(true); state_table->tuning_type=WellTemp; 
    Tuning_QueryTemp(4); Tuning_BaseKey_Cs_select->setChecked(true); }
// Meantone
else if(C==Tuning_Meantone.at(0) && Cs==Tuning_Meantone.at(1) && D==Tuning_Meantone.at(2) && Ds==Tuning_Meantone.at(3) &&
     E==Tuning_Meantone.at(4) && F==Tuning_Meantone.at(5) && Fs==Tuning_Meantone.at(6) && G==Tuning_Meantone.at(7) &&
     Gs==Tuning_Meantone.at(8) && A==Tuning_Meantone.at(9) && As==Tuning_Meantone.at(10) && B==Tuning_Meantone.at(11) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_C_select->setChecked(true); }
else if(C==Tuning_Meantone.at(1) && Cs==Tuning_Meantone.at(2) && D==Tuning_Meantone.at(3) && Ds==Tuning_Meantone.at(4) &&
      E==Tuning_Meantone.at(5) && F==Tuning_Meantone.at(6) && Fs==Tuning_Meantone.at(7) && G==Tuning_Meantone.at(8) &&
      Gs==Tuning_Meantone.at(9) && A==Tuning_Meantone.at(10) && As==Tuning_Meantone.at(11) && B==Tuning_Meantone.at(0) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_B_select->setChecked(true); }
else if(C==Tuning_Meantone.at(2) && Cs==Tuning_Meantone.at(3) && D==Tuning_Meantone.at(4) && Ds==Tuning_Meantone.at(5) &&
      E==Tuning_Meantone.at(6) && F==Tuning_Meantone.at(7) && Fs==Tuning_Meantone.at(8) && G==Tuning_Meantone.at(9) &&
      Gs==Tuning_Meantone.at(10) && A==Tuning_Meantone.at(11) && As==Tuning_Meantone.at(0) && B==Tuning_Meantone.at(1) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_As_select->setChecked(true); }
else if(C==Tuning_Meantone.at(3) && Cs==Tuning_Meantone.at(4) && D==Tuning_Meantone.at(5) && Ds==Tuning_Meantone.at(6) &&
      E==Tuning_Meantone.at(7) && F==Tuning_Meantone.at(8) && Fs==Tuning_Meantone.at(9) && G==Tuning_Meantone.at(10) &&
      Gs==Tuning_Meantone.at(11) && A==Tuning_Meantone.at(0) && As==Tuning_Meantone.at(1) && B==Tuning_Meantone.at(2) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_A_select->setChecked(true); }
else if(C==Tuning_Meantone.at(4) && Cs==Tuning_Meantone.at(5) && D==Tuning_Meantone.at(6) && Ds==Tuning_Meantone.at(7) &&
      E==Tuning_Meantone.at(8) && F==Tuning_Meantone.at(9) && Fs==Tuning_Meantone.at(10) && G==Tuning_Meantone.at(11) &&
      Gs==Tuning_Meantone.at(0) && A==Tuning_Meantone.at(1) && As==Tuning_Meantone.at(2) && B==Tuning_Meantone.at(3) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_Gs_select->setChecked(true); }
else if(C==Tuning_Meantone.at(5) && Cs==Tuning_Meantone.at(6) && D==Tuning_Meantone.at(7) && Ds==Tuning_Meantone.at(8) &&
      E==Tuning_Meantone.at(9) && F==Tuning_Meantone.at(10) && Fs==Tuning_Meantone.at(11) && G==Tuning_Meantone.at(0) &&
      Gs==Tuning_Meantone.at(1) && A==Tuning_Meantone.at(2) && As==Tuning_Meantone.at(3) && B==Tuning_Meantone.at(4) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_G_select->setChecked(true); }
else if(C==Tuning_Meantone.at(6) && Cs==Tuning_Meantone.at(7) && D==Tuning_Meantone.at(8) && Ds==Tuning_Meantone.at(9) &&
      E==Tuning_Meantone.at(10) && F==Tuning_Meantone.at(11) && Fs==Tuning_Meantone.at(0) && G==Tuning_Meantone.at(1) &&
      Gs==Tuning_Meantone.at(2) && A==Tuning_Meantone.at(3) && As==Tuning_Meantone.at(4) && B==Tuning_Meantone.at(5) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_Fs_select->setChecked(true); }
else if(C==Tuning_Meantone.at(7) && Cs==Tuning_Meantone.at(8) && D==Tuning_Meantone.at(9) && Ds==Tuning_Meantone.at(10) &&
      E==Tuning_Meantone.at(11) && F==Tuning_Meantone.at(0) && Fs==Tuning_Meantone.at(1) && G==Tuning_Meantone.at(2) &&
      Gs==Tuning_Meantone.at(3) && A==Tuning_Meantone.at(4) && As==Tuning_Meantone.at(5) && B==Tuning_Meantone.at(6) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_F_select->setChecked(true); }
else if(C==Tuning_Meantone.at(8) && Cs==Tuning_Meantone.at(9) && D==Tuning_Meantone.at(10) && Ds==Tuning_Meantone.at(11) &&
      E==Tuning_Meantone.at(0) && F==Tuning_Meantone.at(1) && Fs==Tuning_Meantone.at(2) && G==Tuning_Meantone.at(3) &&
      Gs==Tuning_Meantone.at(4) && A==Tuning_Meantone.at(5) && As==Tuning_Meantone.at(6) && B==Tuning_Meantone.at(7) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_E_select->setChecked(true); }
else if(C==Tuning_Meantone.at(9) && Cs==Tuning_Meantone.at(10) && D==Tuning_Meantone.at(11) && Ds==Tuning_Meantone.at(0) &&
      E==Tuning_Meantone.at(1) && F==Tuning_Meantone.at(2) && Fs==Tuning_Meantone.at(3) && G==Tuning_Meantone.at(4) &&
      Gs==Tuning_Meantone.at(5) && A==Tuning_Meantone.at(6) && As==Tuning_Meantone.at(7) && B==Tuning_Meantone.at(8) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_Ds_select->setChecked(true); }
else if(C==Tuning_Meantone.at(10) && Cs==Tuning_Meantone.at(11) && D==Tuning_Meantone.at(0) && Ds==Tuning_Meantone.at(1) &&
      E==Tuning_Meantone.at(2) && F==Tuning_Meantone.at(3) && Fs==Tuning_Meantone.at(4) && G==Tuning_Meantone.at(5) &&
      Gs==Tuning_Meantone.at(6) && A==Tuning_Meantone.at(7) && As==Tuning_Meantone.at(8) && B==Tuning_Meantone.at(9) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_D_select->setChecked(true); }
else if(C==Tuning_Meantone.at(11) && Cs==Tuning_Meantone.at(0) && D==Tuning_Meantone.at(1) && Ds==Tuning_Meantone.at(2) &&
      E==Tuning_Meantone.at(3) && F==Tuning_Meantone.at(4) && Fs==Tuning_Meantone.at(5) && G==Tuning_Meantone.at(6) &&
      Gs==Tuning_Meantone.at(7) && A==Tuning_Meantone.at(8) && As==Tuning_Meantone.at(9) && B==Tuning_Meantone.at(10) )
  { Tuning_MeantoneTemp_button->setChecked(true); state_table->tuning_type=MeantoneTemp; 
    Tuning_QueryTemp(5); Tuning_BaseKey_Cs_select->setChecked(true); }
// Arabic
else if(C==Tuning_Arabic.at(0) && Cs==Tuning_Arabic.at(1) && D==Tuning_Arabic.at(2) && Ds==Tuning_Arabic.at(3) &&
     E==Tuning_Arabic.at(4) && F==Tuning_Arabic.at(5) && Fs==Tuning_Arabic.at(6) && G==Tuning_Arabic.at(7) &&
     Gs==Tuning_Arabic.at(8) && A==Tuning_Arabic.at(9) && As==Tuning_Arabic.at(10) && B==Tuning_Arabic.at(11) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_C_select->setChecked(true); }
else if(C==Tuning_Arabic.at(1) && Cs==Tuning_Arabic.at(2) && D==Tuning_Arabic.at(3) && Ds==Tuning_Arabic.at(4) &&
      E==Tuning_Arabic.at(5) && F==Tuning_Arabic.at(6) && Fs==Tuning_Arabic.at(7) && G==Tuning_Arabic.at(8) &&
      Gs==Tuning_Arabic.at(9) && A==Tuning_Arabic.at(10) && As==Tuning_Arabic.at(11) && B==Tuning_Arabic.at(0) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_B_select->setChecked(true); }
else if(C==Tuning_Arabic.at(2) && Cs==Tuning_Arabic.at(3) && D==Tuning_Arabic.at(4) && Ds==Tuning_Arabic.at(5) &&
      E==Tuning_Arabic.at(6) && F==Tuning_Arabic.at(7) && Fs==Tuning_Arabic.at(8) && G==Tuning_Arabic.at(9) &&
      Gs==Tuning_Arabic.at(10) && A==Tuning_Arabic.at(11) && As==Tuning_Arabic.at(0) && B==Tuning_Arabic.at(1) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_As_select->setChecked(true); }
else if(C==Tuning_Arabic.at(3) && Cs==Tuning_Arabic.at(4) && D==Tuning_Arabic.at(5) && Ds==Tuning_Arabic.at(6) &&
      E==Tuning_Arabic.at(7) && F==Tuning_Arabic.at(8) && Fs==Tuning_Arabic.at(9) && G==Tuning_Arabic.at(10) &&
      Gs==Tuning_Arabic.at(11) && A==Tuning_Arabic.at(0) && As==Tuning_Arabic.at(1) && B==Tuning_Arabic.at(2) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_A_select->setChecked(true); }
else if(C==Tuning_Arabic.at(4) && Cs==Tuning_Arabic.at(5) && D==Tuning_Arabic.at(6) && Ds==Tuning_Arabic.at(7) &&
      E==Tuning_Arabic.at(8) && F==Tuning_Arabic.at(9) && Fs==Tuning_Arabic.at(10) && G==Tuning_Arabic.at(11) &&
      Gs==Tuning_Arabic.at(0) && A==Tuning_Arabic.at(1) && As==Tuning_Arabic.at(2) && B==Tuning_Arabic.at(3) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_Gs_select->setChecked(true); }
else if(C==Tuning_Arabic.at(5) && Cs==Tuning_Arabic.at(6) && D==Tuning_Arabic.at(7) && Ds==Tuning_Arabic.at(8) &&
      E==Tuning_Arabic.at(9) && F==Tuning_Arabic.at(10) && Fs==Tuning_Arabic.at(11) && G==Tuning_Arabic.at(0) &&
      Gs==Tuning_Arabic.at(1) && A==Tuning_Arabic.at(2) && As==Tuning_Arabic.at(3) && B==Tuning_Arabic.at(4) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_G_select->setChecked(true); }
else if(C==Tuning_Arabic.at(6) && Cs==Tuning_Arabic.at(7) && D==Tuning_Arabic.at(8) && Ds==Tuning_Arabic.at(9) &&
      E==Tuning_Arabic.at(10) && F==Tuning_Arabic.at(11) && Fs==Tuning_Arabic.at(0) && G==Tuning_Arabic.at(1) &&
      Gs==Tuning_Arabic.at(2) && A==Tuning_Arabic.at(3) && As==Tuning_Arabic.at(4) && B==Tuning_Arabic.at(5) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_Fs_select->setChecked(true); }
else if(C==Tuning_Arabic.at(7) && Cs==Tuning_Arabic.at(8) && D==Tuning_Arabic.at(9) && Ds==Tuning_Arabic.at(10) &&
      E==Tuning_Arabic.at(11) && F==Tuning_Arabic.at(0) && Fs==Tuning_Arabic.at(1) && G==Tuning_Arabic.at(2) &&
      Gs==Tuning_Arabic.at(3) && A==Tuning_Arabic.at(4) && As==Tuning_Arabic.at(5) && B==Tuning_Arabic.at(6) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_F_select->setChecked(true); }
else if(C==Tuning_Arabic.at(8) && Cs==Tuning_Arabic.at(9) && D==Tuning_Arabic.at(10) && Ds==Tuning_Arabic.at(11) &&
      E==Tuning_Arabic.at(0) && F==Tuning_Arabic.at(1) && Fs==Tuning_Arabic.at(2) && G==Tuning_Arabic.at(3) &&
      Gs==Tuning_Arabic.at(4) && A==Tuning_Arabic.at(5) && As==Tuning_Arabic.at(6) && B==Tuning_Arabic.at(7) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_E_select->setChecked(true); }
else if(C==Tuning_Arabic.at(9) && Cs==Tuning_Arabic.at(10) && D==Tuning_Arabic.at(11) && Ds==Tuning_Arabic.at(0) &&
      E==Tuning_Arabic.at(1) && F==Tuning_Arabic.at(2) && Fs==Tuning_Arabic.at(3) && G==Tuning_Arabic.at(4) &&
      Gs==Tuning_Arabic.at(5) && A==Tuning_Arabic.at(6) && As==Tuning_Arabic.at(7) && B==Tuning_Arabic.at(8) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_Ds_select->setChecked(true); }
else if(C==Tuning_Arabic.at(10) && Cs==Tuning_Arabic.at(11) && D==Tuning_Arabic.at(0) && Ds==Tuning_Arabic.at(1) &&
      E==Tuning_Arabic.at(2) && F==Tuning_Arabic.at(3) && Fs==Tuning_Arabic.at(4) && G==Tuning_Arabic.at(5) &&
      Gs==Tuning_Arabic.at(6) && A==Tuning_Arabic.at(7) && As==Tuning_Arabic.at(8) && B==Tuning_Arabic.at(9) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_D_select->setChecked(true); }
else if(C==Tuning_Arabic.at(11) && Cs==Tuning_Arabic.at(0) && D==Tuning_Arabic.at(1) && Ds==Tuning_Arabic.at(2) &&
      E==Tuning_Arabic.at(3) && F==Tuning_Arabic.at(4) && Fs==Tuning_Arabic.at(5) && G==Tuning_Arabic.at(6) &&
      Gs==Tuning_Arabic.at(7) && A==Tuning_Arabic.at(8) && As==Tuning_Arabic.at(9) && B==Tuning_Arabic.at(10) )
  { Tuning_ArabicTemp_button->setChecked(true); state_table->tuning_type=ArabicTemp; 
    Tuning_QueryTemp(6); Tuning_BaseKey_Cs_select->setChecked(true); }
// Custom
else { Tuning_CustomTemp_button->setChecked(true); state_table->tuning_type=CustomTemp;
       Tuning_BaseKey_C_select->setChecked(true); }

Tuning_ButtonGroup->blockSignals(false);
Tuning_BaseKey_box->setEnabled(!Tuning_EqualTemp_button->isChecked());
}	// end calc_tuning
