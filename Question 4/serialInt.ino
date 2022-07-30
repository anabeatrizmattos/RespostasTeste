String inputString = ""; // a string to hold incoming data
boolean completeString = false; // whether the string is complete expand sourceview plain


void setup() {
    Serial.begin(9600);
    // reserve 100 bytes for the inputString:
    inputString.reserve(100);
}
 
 
void loop() {
    if (completeString) 
    {
        Serial.println(inputString);
        // clear the string:
        inputString = "";
        //verifying
        completeString = false;
    }
}
 
 
    /*SerialEvent occurs when a new data comes in the hardware serial RX.  
        Multiple bytes of data may be available.*/
void serialEvent() {
    while (Serial.available()) 
    {
        // get the new byte:
        char inChar = (char)Serial.read();
        // add it to the inputString:
        inputString += inChar;
        // if the incoming character is a newline, set a flag
        // so the main loop can do something about it:
        if (inChar == '\n') 
        {
            completeString = true;
        }
    }
}