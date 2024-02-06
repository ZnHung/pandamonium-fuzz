/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class PandamoniumLookAndFeel : public juce::LookAndFeel_V4
{
public:
    PandamoniumLookAndFeel();
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider&) override;
    juce::Label* PandamoniumLookAndFeel::createSliderTextBox(juce::Slider& slider) override;
    
private:
    // colors
    juce::Colour _ice = juce::Colour(164, 254, 252);
    juce::Colour _gold = juce::Colour(254, 222, 104);
    juce::Colour _blackOutline = juce::Colour(0, 0, 0);
    juce::Colour _blackPanda = juce::Colour(51, 51, 51);
    juce::Colour _whitePanda = juce::Colour(255, 254, 254);
    juce::Colour _grey = juce::Colour(58, 58, 58);
    
    // typefaces
    juce::Font _komikax = juce::Font(juce::Typeface::createSystemTypefaceFor(BinaryData::KOMIKAX_ttf, BinaryData::KOMIKAX_ttfSize));
};


class ModeSlider : public juce::Slider
{
public:
    juce::String getTextFromValue(double value) override;
    double getValueFromText(const juce::String &text) override;
};

//==============================================================================
/**
*/
class PandamoniumAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                         private juce::Slider::Listener
{
public:
    PandamoniumAudioProcessorEditor (PandamoniumAudioProcessor&);
    ~PandamoniumAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged(juce::Slider* slider) override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PandamoniumAudioProcessor& audioProcessor;
    
    PandamoniumLookAndFeel _lookAndFeel;

    juce::Slider _gainSlider;
    juce::Slider _fuzzSlider;
    juce::Slider _volumeSlider;
    ModeSlider _modeSlider;
    
    juce::Label _pandamoniumText;
    juce::Label _fuzzText;
    
    juce::Image _background = juce::ImageCache::getFromMemory (BinaryData::pluginbackground_png, BinaryData::pluginbackground_pngSize);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PandamoniumAudioProcessorEditor)
};
