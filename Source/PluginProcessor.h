/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

/// <summary>
/// Enum used to set the type of clipping the plugin uses
/// </summary>
enum FuzzMode 
{
    ExpSoftClipping,
    SoftClipping,
    HardClipping
};

//==============================================================================
/**
*/
class PandamoniumAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    PandamoniumAudioProcessor();
    ~PandamoniumAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //==============================================================================
    float getGain();
    void setGain(float gain);

    float getFuzz();
    void setFuzz(float fuzz);

    float getVolume();
    void setVolume(float bias);

    FuzzMode getMode();
    void setMode(FuzzMode mode);

private:
    float _gain; // gain on input signal
    float _fuzz; // amount of distortion
    float _volume; // gain on output signal
    FuzzMode _mode; // clipping mode

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PandamoniumAudioProcessor)
};