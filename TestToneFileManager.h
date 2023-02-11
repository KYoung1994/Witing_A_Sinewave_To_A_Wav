/*
  ==============================================================================

    TestToneFileGenerator.h
    Created: 11 Feb 2023 8:50:29pm
    Author:  Kimberly Young

  ==============================================================================
*/

#pragma once
#include "wavgenerator.h"

class TestToneFileManager{
public:
    TestToneFileManager(float frequency)  : localFrequency{frequency}, sampleRate {44100}, seconds {5}, bitDepth {16}, numChannels {5}{
        
    }
    
    ~TestToneFileManager(){}
    
    void nameYourFile(){
        std::cout << "name your file" << std::endl;
        std::cin >> fileName;
    }
    
    void prepareSine(){
        sineWave.resize(numChannels);
        for(int channel {0}; channel < sineWave.size(); channel++){
            sineWave.at(channel).setSampleRate(sampleRate);
            sineWave.at(channel).setFrequency(localFrequency);
            sineWave.at(channel).position = 0;
           
        }
    }
    
    void createFile(){
        auto documents = juce::File::getSpecialLocation(juce::File::SpecialLocationType::userDocumentsDirectory);
        auto folder = documents.getChildFile ("THE test FOLDER");
        
        if (!folder.isDirectory()){
            folder.createDirectory();
        }
        
        ourFile = folder.getChildFile(juce::String(fileName + ".wav"));
        
        ourFile.deleteFile();
        ourFile.create();
    }
    
    void writeToFile(){
        juce::WavAudioFormat wavFormat;
        std::unique_ptr<juce::AudioFormatWriter> writer;
        writer.reset(wavFormat.createWriterFor(new juce::FileOutputStream(ourFile), sampleRate, numChannels, bitDepth, {}, 0));
        
        juce::AudioBuffer<float> buffer;
        buffer.clear();
        buffer.setSize(numChannels, sampleRate*seconds);
        
        for (int channel {0}; channel < numChannels; ++channel){
            auto writepointer = buffer.getWritePointer(channel);
           // sineWave.at(channel).position = 0;
            
            for(int sample {0}; sample < sampleRate * seconds; sample++){
                writepointer[sample] = sineWave.at(channel).getNextSineSample();
            }
        }
        
        if (writer != nullptr) {
               writer ->writeFromAudioSampleBuffer(buffer, 0, sampleRate * seconds);
           }
    }
    
protected:
    std::string fileName{};
private:
    float localFrequency, sampleRate, seconds;
    int bitDepth {}, numChannels {} ;
    juce::File ourFile{};
  //  std::string fileName{};
    std::vector<sine> sineWave;
};
