# woodyWaveShield
:Author: operaartificis

:Email: karey.higuera@gmail.com

:Date: 08/10/2017

:License: Public Domain

An arduino sketch for a wave shield to play Woody's catchphrases. 
The wave shield is programmed to play one of Woody's catchphrases each time it is triggered by button input.
The files are stored on and read from an SD card, then interpreted by the wave shield and output through an amplifier to a set of speakers. 

Download and include the WaveHC library (https://github.com/adafruit/WaveHC) or use the edited version included in this project. I've changed the OPTIMIZE_CONTIGUOUS setting in the WaveHC.h file to increase startup speed since continuous play won't be necessary. 

::Required hardware::
--Arduino Uno https://www.adafruit.com/product/50
--Arduino wave shield https://www.adafruit.com/product/94
--Speaker https://www.adafruit.com/product/1314
--Audio amplifier https://www.adafruit.com/product/987
