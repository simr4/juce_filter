/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class FilterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    FilterAudioProcessorEditor (FilterAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
    ~FilterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FilterAudioProcessor& audioProcessor;

	juce::Slider cutoffFrequencySlider;
	std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cutoffFrequencyAttachment;
	juce::Label cutoffFrequencyLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterAudioProcessorEditor)
};
