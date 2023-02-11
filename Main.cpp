/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TestToneFileManager.h"


int main (int argc, char* argv[])
{
    
    TestToneFileManager sineTestTone(440);
    
    sineTestTone.nameYourFile();
    sineTestTone.prepareSine();
    sineTestTone.createFile();
    sineTestTone.writeToFile();

       return 0;
 
}
