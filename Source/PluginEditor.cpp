/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FilterAudioProcessorEditor::FilterAudioProcessorEditor (FilterAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
	addAndMakeVisible(cutoffFrequencySlider);
	cutoffFrequencySlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
	cutoffFrequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);

	cutoffFrequencyAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(vts, "cutoff_frequency", cutoffFrequencySlider));

	addAndMakeVisible(cutoffFrequencyLabel);
	cutoffFrequencyLabel.setText("Cutoff Frequency", juce::NotificationType::dontSendNotification);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	setSize(200, 200);
}

FilterAudioProcessorEditor::~FilterAudioProcessorEditor()
{
}

//==============================================================================
void FilterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
}

void FilterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	cutoffFrequencySlider.setBounds(10, 10, 100, 100);
	cutoffFrequencyLabel.setBounds(10, 110, 100, 20);
}
