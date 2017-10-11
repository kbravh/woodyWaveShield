/*
 * Woody's pullstring voice box. Each time the Arduino is triggered, 
 * presumably by the pullstring on Woody's back, a random catchphrase 
 * will be selected and played.
 */

#include <WaveHC.h>
#include <WaveUtil.h>

SdReader card;    // This holds the information for the card
FatVolume vol;    // This holds the information for the partition on the card
FatReader root;   // This holds the information for the volume's root directory
FatReader file;   // This represents the WAV file
WaveHC wave;      // This is the only wave (audio) object, since we will only play one at a time

const char inputSwitchPin = 8;   //input pin for pullstring switch
char switchState;                //whether or not switch is active

void setup() {
    Serial.begin(9600);
    
    Serial.println("Woody's Voicebox");
    Serial.println("Files found:");
    root.ls();
}


void loop() {
    switchState = digitalRead(inputSwitchPin);
     
    /*
     * Code is not scalable. Files must be named with a specific
     * number, and the number of files cannot be increased. Could
     * possibly implement code from openByIndex?
     */
    if(switchState==1){
        char phrase = random(0,6);
        playWav(phrase);
    }
}

/*
 * Play the referenced wav file
 */
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
}
