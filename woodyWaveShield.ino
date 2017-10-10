/*
 * Woody's pullstring voice box. Each time the Arduino is triggered, 
 * presumably by the pullstring on Woody's back, a random catchphrase 
 * will be selected and played.
 */

#include <WaveHC.h>
#include <WaveUtil.h>

void setup() {
    
}

void loop() {
    
}

void playWav(char *name) {
  //stop a wave file if it's already playing
  if (wave.isplaying) {
    wave.stop(); 
  }
  //error if file cannot be opened
  if (!file.open(root, name)) {
    Serial.print(F("Couldn't open file "));
    Serial.print(name); 
    return;
  }
  //error if WAV file is invalid
  if (!wave.create(file)) {
    Serial.println(F("Not a valid WAV"));
    return;
  }
  //play sound file if no error is found
  wave.play();
  
  //plays file until it finishes without interruptions
  while (wave.isplaying);
  
  // see if an error occurred while playing
  sdErrorCheck();
}
