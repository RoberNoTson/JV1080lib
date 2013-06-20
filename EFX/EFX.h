// EFX.h
#ifndef EFX_H
#define EFX_H 1

//  int addr_EFX_parameter = 0xE;      // E

  extern	void EFX01stereoEQ();
  extern	void EFX02overdrive();
  extern	void EFX03distortion();
  extern	void EFX04phaser();
  extern	void EFX05spectrum();
  extern	void EFX06enhancer();
  extern	void EFX07autoWah();
  extern	void EFX08rotary();
  extern	void EFX09compressor();
  extern	void EFX10limiter();
  extern	void EFX11HexaChorus();
  extern	void EFX12TremoloChorus();
  extern	void EFX13Space_D();
  extern	void EFX14StereoChorus();
  extern	void EFX15StereoFlanger();
  extern	void EFX16StepFlanger();
  extern        void EFX17StereoDelay();
  extern        void EFX18ModulationDelay();
  extern        void EFX19TripleTapDelay();
  extern        void EFX20QuadrupleTapDelay();
  extern        void EFX21TimeControlDelay();
  extern        void EFX22VoicePitchShifter();
  extern        void EFX23FeedbackPitchShifter();
  extern        void EFX24Reverb();
  extern        void EFX25GateReverb();
  extern        void EFX26OverdriveSeriesChorus();
  extern        void EFX27OverdriveSeriesFlanger();
  extern        void EFX28OverdriveSeriesDelay();
  extern        void EFX29DistortionSeriesChorus();
  extern        void EFX30DistortionSeriesFlanger();
  extern        void EFX31DistortionSeriesDelay();
  extern        void EFX32EnhancerSeriesChorus();
  extern        void EFX33EnhancerSeriesFlanger();
  extern        void EFX34EnhancerSeriesDelay();
  extern        void EFX35ChorusSeriesDelay();
  extern        void EFX36FlangerSeriesDelay();
  extern        void EFX37ChorusSeriesFlanger();
  extern        void EFX38ChorusParallelDelay();
  extern        void EFX39FlangerParallelDelay();
  extern        void EFX40ChorusParallelFlanger();
#endif
