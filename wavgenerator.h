/*
  ==============================================================================

    wavgenerator.h
    Created: 12 Nov 2021 12:53:08pm
    Author:  Kimberly Young

  ==============================================================================
*/

#pragma once
#include <math.h>

class sine {
public:
    
    sine()
    : twopi {2*M_PI}, amplitude (0.9){
    }
    
    sine(float sr, float f)
    : twopi {2*M_PI}, amplitude (0.9){
        setSampleRate(sr);
        setFrequency(f);
    }
    
    ~sine(){}
    
    void setSampleRate(float sr){
        sampleRate=sr;
    }
    void setFrequency(float f){
        frequency=f;
    }
    
    float getFrequency (){
        return frequency;
    }
    float getSampleRate (){
        return sampleRate;
    }
    
    float getNextSineSample(){
       float time = position/sampleRate;
        position++;
        return amplitude*sin(twopi*frequency*time);
    }
    
   static auto setFile(std::string mainName){
    auto documents = juce::File::getSpecialLocation(juce::File::SpecialLocationType::userDocumentsDirectory);
    auto ourFoulder = documents.getChildFile(juce::String("classMember_folder"));
    
    if(!ourFoulder.isDirectory()){
        ourFoulder.createDirectory();
    }
    
    auto ourFile = ourFoulder.getChildFile(juce::String(mainName));
        
        return ourFile;
    
    //VOID GENERATE FILE
    }
    
    
    int position;
    
private:
    float sampleRate, frequency, twopi, amplitude;
    
    
};
