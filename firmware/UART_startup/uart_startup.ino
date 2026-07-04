
// put function declarations here:
void processCommand(String);

//Global Variables
String userInput = "";
const char BACKSPACE_KEY = 127;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Embedded CLI v1.0");
  Serial.println("Type 'help' to see available commands.");
  Serial.print("CLI> ");
}

void loop()
{
  // put your main code here, to run repeatedly:

  /* 
  Enter on Wokwi is 10 while Enter on VS Code is 13. Backspace on VS Code is 127
  Moreover VS code doesn't even need ENTER to send data
   from terminal to the ESP32, As soon as you press the key on VS Code
  It is automatically sent to the ESP32
  */
  int countInBuffer = Serial.available();

  if (countInBuffer > 0)
  {
    for (int i = 0; i < countInBuffer; i++)
    {
      char currentCharacter = Serial.read();
      if (currentCharacter != '\r' && currentCharacter != '\n')
      {
        if(currentCharacter == BACKSPACE_KEY  ){
          if(!userInput.isEmpty()){
           int lastIndex = userInput.length()-1 ;
           // Buffer Handling for the Backspace
           userInput.remove(lastIndex);    
            // Echo Handling for the Backspace
           Serial.print('\b');  
           Serial.print(' ');  
           Serial.print('\b'); 
          }             
        
        }else{
           userInput += currentCharacter;
           Serial.print(currentCharacter);  //  handling the echo of each character
        }
         
      }
      else
      {
        Serial.println();  //To print the result from a new line
        processCommand(userInput);
        userInput = "";
        Serial.print("\nCLI> ");  // Showing the CLI prompt
        
      }
    }
  }

  // delay(5000); // this speeds up the simulation // Not needed after we use the Carriage return Condition
}

void processCommand(String command)
{
   Serial.println(command) ;  // To check the command sent : just for debugging : will comment later
  if (command == "help")
  {
    Serial.println("Available Commands: ");
    Serial.println("help");
    Serial.println("version");
  }
  else if (command == "version")
  {
    Serial.println("1.0.0");
  }
  else
  {
    Serial.println("Unknown Command");
  }
}
