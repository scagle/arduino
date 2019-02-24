#include <IRremote.h>

//#define ms_remote_map.h

#define SL_BD_RT 9600

#define RECV_PIN 2
#define SPKR 7

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(SL_BD_RT);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(SPKR, OUTPUT);
  pinMode(RECV_PIN, INPUT);
  pinMode(8, OUTPUT);  //LED
}

void loop() {
  if (irrecv.decode(&results)) {  //If IR receive results are detected
    //Serial.println(results.value, HEX);
    digitalWrite(8, HIGH);
    int length_of_tone = 300;
    for (int i=0; i<length_of_tone; i++) 
    { 
      digitalWrite(SPKR, HIGH);
      delayMicroseconds(length_of_tone - (length_of_tone-i));
      digitalWrite(SPKR, LOW);
      delayMicroseconds(length_of_tone - (length_of_tone-i));
    }
    digitalWrite(8, LOW);
    irrecv.resume(); // Receive the next value
   }
}
