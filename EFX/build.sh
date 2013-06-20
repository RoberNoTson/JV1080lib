#!/bin/sh

# build template for EFX code files
for fn in `cat filelist.txt`; do
  if [ -e $fn ]; then echo Skipping $fn; continue; fi

printf "// %s\n
#include\t\"JVlibForm.h\"
#include\t<QtGui>
#include\t\"EFX/EFX.h\"\n
void JVlibForm::%s() {
      enable_6(true);
      enable_7(true);
      enable_8(true);
      enable_9(true);
      enable_10(true);
      enable_11(true);
      enable_12(false);

      EFXparm1_label->setText(QString(\"\"));
      PerfEFXparm1_select->setRange(0, 1);
      PerfEFXparm1_select->setValue(active_area->active_performance.perf_common.EFX_parameter[0]);
      
      EFXparm2_label->setText(QString(\"\"));
      PerfEFXparm2_select->setRange(0, 30);
      PerfEFXparm2_select->setValue(active_area->active_performance.perf_common.EFX_parameter[1]);

      EFXparm3_label->setText(QString(\"\"));
      PerfEFXparm3_select->setRange(0, 1);
      PerfEFXparm3_select->setValue(active_area->active_performance.perf_common.EFX_parameter[2]);

      EFXparm4_label->setText(QString(\"\"));
      PerfEFXparm4_select->setRange(0, 30);
      PerfEFXparm4_select->setValue(active_area->active_performance.perf_common.EFX_parameter[3]);

      EFXparm5_label->setText(QString(\"\"));
      PerfEFXparm5_select->setRange(0, 16);
      PerfEFXparm5_select->setValue(active_area->active_performance.perf_common.EFX_parameter[4]);
      
      EFXparm6_label->setText(QString(\"\"));
      PerfEFXparm6_select->setRange(0, 4);
      PerfEFXparm6_select->setValue(active_area->active_performance.perf_common.EFX_parameter[5]);

      EFXparm7_label->setText(QString(\"\"));
      PerfEFXparm7_select->setRange(0, 30);
      PerfEFXparm7_select->setValue(active_area->active_performance.perf_common.EFX_parameter[6]);

      EFXparm8_label->setText(QString(\"\"));
      PerfEFXparm8_select->setRange(0, 16);
      PerfEFXparm8_select->setValue(active_area->active_performance.perf_common.EFX_parameter[7]);
      
      EFXparm9_label->setText(QString(\"\"));
      PerfEFXparm9_select->setRange(0, 4);
      PerfEFXparm9_select->setValue(active_area->active_performance.perf_common.EFX_parameter[8]);

      EFXparmA_label->setText(QString(\"\"));
      PerfEFXparmA_select->setRange(0, 30);
      PerfEFXparmA_select->setValue(active_area->active_performance.perf_common.EFX_parameter[9]);

      EFXparmB_label->setText(QString(\"\"));
      PerfEFXparmB_select->setRange(0, 127);
      PerfEFXparmB_select->setValue(active_area->active_performance.perf_common.EFX_parameter[10]);
}\t// end %s\n" $fn `basename $fn .cpp` `basename $fn .cpp` >$fn;
  
  echo Created $fn
done;

# build entries for JVlibForm.h
rm -f JVlibForm.h.entries.txt;
touch JVlibForm.h.entries.txt;
for fn in `cat filelist.txt`; do
  printf "    void %s();\n" `basename $n .cpp` >>JVlibForm.h.entries.txt;
done

# build entries for EFX.h
rm -f EFX.h.entries.txt;
touch EFX.h.entries.txt;
for fn in `cat filelist.txt`; do
  printf "  extern\tvoid %s()\n" `basename $n .cpp` >>EFX.h.entries.txt;
done

# build entries for JVlib.pro
rm -f JVlib.pro.entries.txt
touch JVlib.pro.entries.txt
for fn in `cat filelist.txt`; do
  printf "\tEFX/%s \\ \n" $n >>JVlib.pro.entries.txt;
done
