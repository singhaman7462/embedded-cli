void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("UART Initialized successfully");

 

}

void loop() {
  // put your main code here, to run repeatedly:

 volatile int countInBuffer = Serial.available();
    String userInput = "";
    if (countInBuffer > 0) {
      for (int i = 0; i < countInBuffer; i++) {
        char currentCharacter=Serial.read();
        userInput +=currentCharacter;
      }
    }
    Serial.println(userInput);

  delay(3000); // this speeds up the simulation

}
