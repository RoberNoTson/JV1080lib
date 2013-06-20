// set_initial.cpp
// for Performance tab, EFX section

#include        "JVlibForm.h"
#include        <QtGui>

void JVlibForm::setPerfEFXparms() {
  // called after the Performance Sync button is clicked as part of set_*_parms.cpp 
  //	sets controls/displays to reflect the current synth configuration.
  switch(active_area->active_performance.perf_common.EFX_type) {
    // every case has at least 5 parms
    case 0:	// Stereo EQ
      EFX01stereoEQ();
      break;
    case 1: 	// Overdrive
      EFX02overdrive();
      break;
    case 2: 	// Distortion
      EFX03distortion();
      break;
    case 3: 	// Phaser
      EFX04phaser();
      break;
    case 4: 	// Spectrum
      EFX05spectrum();
      break;
    case 5: 	// Enhancer
      EFX06enhancer();
      break;
    case 6: 	// Auto-Wah
      EFX07autoWah();
      break;
    case 7: 	// Rotary
      EFX08rotary();
      break;
    case 8: 	// Compressor
      EFX09compressor();
      break;
    case 9: 	// Limiter
      EFX10limiter();
      break;
    case 10: 	// Hexa-Chorus
      EFX11HexaChorus();
      break;
    case 11: 	// Tremolo-Chorus
      EFX12TremoloChorus();
      break;
    case 12: 	// Space_D
      EFX13Space_D();
      break;
    case 13: 	// Stereo-Chorus
      EFX14StereoChorus();
      break;
    case 14: 	// Stereo-Flanger
      EFX15StereoFlanger();
      break;
    case 15: 	// Step-Flanger
      EFX16StepFlanger();
      break;
    case 16: 	// Stereo-Delay
      EFX17StereoDelay();
      break;
    case 17: 	// Modulation-Delay
      EFX18ModulationDelay();
      break;
    case 18: 	// Triple-Tap-Delay
      EFX19TripleTapDelay();
      break;
    case 19: 	// Quadruple-Tap-Delay
      EFX20QuadrupleTapDelay();
      break;
    case 20: 	// Time-Control-Delay
      EFX21TimeControlDelay();
      break;
    case 21: 	// Voice-Pitch-Shifter
      EFX22VoicePitchShifter();
      break;
    case 22: 	// Feedback-Pitch-Shifter
      EFX23FeedbackPitchShifter();
      break;
    case 23: 	// Reverb
      EFX24Reverb();
      break;
    case 24: 	// Gate-Reverb
      EFX25GateReverb();
      break;
    case 25: 	// Overdrive-Series-Chorus
      EFX26OverdriveSeriesChorus();
      break;
    case 26: 	// Overdrive-Series-Flanger
      EFX27OverdriveSeriesFlanger();
      break;
    case 27: 	// Overdrive-Series-Delay
      EFX28OverdriveSeriesDelay();
      break;
    case 28: 	// Distortion-Series-Chorus
      EFX29DistortionSeriesChorus();
      break;
    case 29: 	// Distortion-Series-Flanger
      EFX30DistortionSeriesFlanger();
      break;
    case 30: 	// Distortion-Series-Delay
      EFX31DistortionSeriesDelay();
      break;
    case 31: 	// Enhancer-Series-Chorus
      EFX32EnhancerSeriesChorus();
      break;
    case 32: 	// Enhancer-Series-Flanger
      EFX33EnhancerSeriesFlanger();
      break;
    case 33: 	// Enhancer-Series-Delay
      EFX34EnhancerSeriesDelay();
      break;
    case 34: 	// Chorus-Series-Delay
      EFX35ChorusSeriesDelay();
      break;
    case 35: 	// Flanger-Series-Delay
      EFX36FlangerSeriesDelay();
      break;
    case 36: 	// Chorus-Series-Flanger
      EFX37ChorusSeriesFlanger();
      break;
    case 37: 	// Chorus-Parallel-Delay
      EFX38ChorusParallelDelay();
      break;
    case 38: 	// Flanger-Parallel-Delay
      EFX39FlangerParallelDelay();
      break;
    case 39: 	// Chorus-Parallel-Flanger
      EFX40ChorusParallelFlanger();
      break;
    default:
      break;
  }	// end switch EFX type
  displayEFXparms();
}	// end setPerfEFXparms

void JVlibForm::setPatchEFXparms() {
  // called after the Patch Sync button is clicked, or when need to refresh the display
  switch(state_table->patch_mode ? active_area->active_patch_patch.patch_common.EFX_type : 
    active_area->active_perf_patch[Patch_PerfPartNum_select->currentIndex()].patch_common.EFX_type) 
  {
    // every case has at least 5 parms
    case 0:	// Stereo EQ
      EFX01stereoEQ();
      break;
    case 1: 	// Overdrive
      EFX02overdrive();
      break;
    case 2: 	// Distortion
      EFX03distortion();
      break;
    case 3: 	// Phaser
      EFX04phaser();
      break;
    case 4: 	// Spectrum
      EFX05spectrum();
      break;
    case 5: 	// Enhancer
      EFX06enhancer();
      break;
    case 6: 	// Auto-Wah
      EFX07autoWah();
      break;
    case 7: 	// Rotary
      EFX08rotary();
      break;
    case 8: 	// Compressor
      EFX09compressor();
      break;
    case 9: 	// Limiter
      EFX10limiter();
      break;
    case 10: 	// Hexa-Chorus
      EFX11HexaChorus();
      break;
    case 11: 	// Tremolo-Chorus
      EFX12TremoloChorus();
      break;
    case 12: 	// Space_D
      EFX13Space_D();
      break;
    case 13: 	// Stereo-Chorus
      EFX14StereoChorus();
      break;
    case 14: 	// Stereo-Flanger
      EFX15StereoFlanger();
      break;
    case 15: 	// Step-Flanger
      EFX16StepFlanger();
      break;
    case 16: 	// Stereo-Delay
      EFX17StereoDelay();
      break;
    case 17: 	// Modulation-Delay
      EFX18ModulationDelay();
      break;
    case 18: 	// Triple-Tap-Delay
      EFX19TripleTapDelay();
      break;
    case 19: 	// Quadruple-Tap-Delay
      EFX20QuadrupleTapDelay();
      break;
    case 20: 	// Time-Control-Delay
      EFX21TimeControlDelay();
      break;
    case 21: 	// Voice-Pitch-Shifter
      EFX22VoicePitchShifter();
      break;
    case 22: 	// Feedback-Pitch-Shifter
      EFX23FeedbackPitchShifter();
      break;
    case 23: 	// Reverb
      EFX24Reverb();
      break;
    case 24: 	// Gate-Reverb
      EFX25GateReverb();
      break;
    case 25: 	// Overdrive-Series-Chorus
      EFX26OverdriveSeriesChorus();
      break;
    case 26: 	// Overdrive-Series-Flanger
      EFX27OverdriveSeriesFlanger();
      break;
    case 27: 	// Overdrive-Series-Delay
      EFX28OverdriveSeriesDelay();
      break;
    case 28: 	// Distortion-Series-Chorus
      EFX29DistortionSeriesChorus();
      break;
    case 29: 	// Distortion-Series-Flanger
      EFX30DistortionSeriesFlanger();
      break;
    case 30: 	// Distortion-Series-Delay
      EFX31DistortionSeriesDelay();
      break;
    case 31: 	// Enhancer-Series-Chorus
      EFX32EnhancerSeriesChorus();
      break;
    case 32: 	// Enhancer-Series-Flanger
      EFX33EnhancerSeriesFlanger();
      break;
    case 33: 	// Enhancer-Series-Delay
      EFX34EnhancerSeriesDelay();
      break;
    case 34: 	// Chorus-Series-Delay
      EFX35ChorusSeriesDelay();
      break;
    case 35: 	// Flanger-Series-Delay
      EFX36FlangerSeriesDelay();
      break;
    case 36: 	// Chorus-Series-Flanger
      EFX37ChorusSeriesFlanger();
      break;
    case 37: 	// Chorus-Parallel-Delay
      EFX38ChorusParallelDelay();
      break;
    case 38: 	// Flanger-Parallel-Delay
      EFX39FlangerParallelDelay();
      break;
    case 39: 	// Chorus-Parallel-Flanger
      EFX40ChorusParallelFlanger();
      break;
    default:
      break;
  }	// end switch EFX type
  displayEFXparms();
  PatchEFX_ReverbFeedback_select->setEnabled(PatchEFX_ReverbType_select->currentIndex()>5?true:false);  
}	// end setPatchEFXparms
