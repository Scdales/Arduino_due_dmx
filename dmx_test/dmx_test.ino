// These values define the gap (in microseconds) between frames
#define DMXFRAMELOW 200
#define DMXFRAMEHIGH 5000

#define DMXLENGTH 512
byte DMX[DMXLENGTH]; // Array to store DMX values

// Frame recorder counters
int i = 0; // Value counter
byte q = 0; // Verification pass counter

boolean recorded = false;

void setup() {
  // Comms
  Serial.begin(9600);
  Serial3.begin(250000);

}

void loop() {
  if(recordFrame() && !recorded) {
    recorded = true;
    Serial.println("Received DMX Frame");
    for (int i=0; i<DMXLENGTH; i++) {
      Serial.print(i);
      Serial.print(":");
      Serial.print(DMX[i]);
      Serial.print(" ");
      if (i % 8 == 0) Serial.println();
    }
  }

}

boolean recordFrame() {
  unsigned long frameTimeout = millis();
  unsigned long dmxTempVar = micros();
  while (true) {
    if (Serial3.available() > 0) {
      int inChar = Serial3.read();
      // Check data is good
      if (inChar >= 0 && inChar <= 255) DMX[i] = inChar;
      DMX[i] = inChar;
      // Check time between values
      long space = micros() - dmxTempVar;
      dmxTempVar = micros();
      i++;
      if (space >= DMXFRAMELOW && space <= DMXFRAMEHIGH) {
        q += 1;
        i = 0;
        if (q > 4) {
          q = 0;
          return true;
        }
      }
    }
  }
}
