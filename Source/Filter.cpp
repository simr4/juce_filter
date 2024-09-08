#include "Filter.h"

void Filter::setCutoffFrequency(float cutoffFrequency)
{
	this->cutoffFrequency = cutoffFrequency;
}

void Filter::setSamplingRate(float samplingRate)
{
	this->samplingRate = samplingRate;
}

void Filter::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
	dnBuffer.resize(buffer.getNumChannels(), 0.f); // Resize the buffer to the number of channels

	const float theta = 2 * PI * cutoffFrequency / samplingRate;
	const float alpha = theta / (1 + theta);

	// Iterating over the channels
	for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
	{
		auto* samples = buffer.getWritePointer(channel); // Get the pointer to the channel data

		// Iterating over the channel samples
		for (int i = 0; i < buffer.getNumSamples(); ++i)
		{
			samples[i] = alpha * samples[i] + (1 - alpha) * previousSample; // Apply the filter
			previousSample = samples[i]; // Update the previous sample value
		}
	}
}
