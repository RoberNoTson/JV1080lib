#!/bin/sh

A="on_ToneEFX_LFO1LevelOffset_select_currentIndexChanged";B="slotToneEFX_LFO1LevelOffset"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO2LevelOffset_select_currentIndexChanged";B="slotToneEFX_LFO2LevelOffset"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LF02Waveform_select_currentIndexChanged";B="slotToneEFX_LF02Waveform"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO2FadeMode_select_currentIndexChanged";B="slotToneEFX_LFO2FadeMode"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_PanKeyFollow_select_currentIndexChanged";B="slotToneEFX_PanKeyFollow"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LF01Waveform_select_currentIndexChanged";B="slotToneEFX_LF01Waveform"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO1FadeMode_select_currentIndexChanged";B="slotToneEFX_LFO1FadeMode"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO1ExtSync_select_currentIndexChanged";B="slotToneEFX_LFO1ExtSync"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO2ExtSync_select_currentIndexChanged";B="slotToneEFX_LFO2ExtSync"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_PanControl_select_currentIndexChanged";B="slotToneEFX_PanControl"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO1FadeTime_select_valueChanged";B="slotToneEFX_LFO1FadeTime"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO2FadeTime_select_valueChanged";B="slotToneEFX_LFO2FadeTime"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_PanLFO1Depth_select_valueChanged";B="slotToneEFX_PanLFO1Depth"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_PanLFO2Depth_select_valueChanged";B="slotToneEFX_PanLFO2Depth"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_PanRandDepth_select_valueChanged";B="slotToneEFX_PanRandDepth"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO1KeyTrigger_enable_toggled";B="slotToneEFX_LFO1KeyTrigger"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO2KeyTrigger_enable_toggled";B="slotoneEFX_LFO2KeyTrigger"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO1Delay_select_valueChanged";B="slotToneEFX_LFO1Delay"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO2Delay_select_valueChanged";B="slotToneEFX_LFO2Delay"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO1Rate_select_valueChanged";B="slotToneEFX_LFO1Rate"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_LFO2Rate_select_valueChanged";B="slotToneEFX_LFO2Rate"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_AltPan_select_valueChanged";B="slotToneEFX_AltPan"; sed -i s/"$B"/"$A"/g $1
A="on_ToneEFX_Pan_select_valueChanged";B="slotToneEFX_Pan"; sed -i s/"$B"/"$A"/g $1
