# woodyWaveShield
:Author: operaartificis

:Email: karey.higuera@gmail.com

:Date: 08/10/2017

:License: Public Domain

An arduino sketch for a wave shield to play Woody's catchphrases. 
The wave shield will be programmed to play one of Woody's six catchphrases each time it is triggered by button input.
The files are stored on and read from an SD card, then interpreted by the wave shield and output through an amplifier to a small speaker. 

Download and include the WaveHC library (https://github.com/adafruit/WaveHC) or use the edited version included in this project. I've changed the OPTIMIZE_CONTIGUOUS setting in the WaveHC.h file to increase startup speed since continuous play won't be necessary. 

