

// put function declarations here:
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("UART Initialized successfully");
}

void loop()
{
  // put your main code here, to run repeatedly:

  /* Enter on Wokwi is 10 while Enter on VS Code is 13
  Moreover VS code doesn't even need ENTER to send data
   from terminal to the ESP32, As soon as yoou press the key on VS Code
  It is automatically sent to the ESP32*/
  int countInBuffer = Serial.available();
  String userInput = "";
  if (countInBuffer > 0)
  {
    for (int i = 0; i < countInBuffer; i++)
    {
      char currentCharacter = Serial.read();
      userInput += currentCharacter;
    }
  }
  Serial.println(userInput);

  delay(3000); // this speeds up the simulation
}
