#pragma once

#include <vector>
#include "JuceHeader.h"

class Filter
{
public:
	void setCutoffFrequency(float cutoffFrequency);
	void setSamplingRate(float samplingRate);

	void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages);

private:
	const float PI = 3.14159265358979323846f;

	float samplingRate;
	float cutoffFrequency;
	float previousSample = 0.f;

	std::vector<float> dnBuffer;
};

