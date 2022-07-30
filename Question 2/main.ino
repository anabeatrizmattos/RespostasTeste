
const int BUTTON_PIN = 7; // the number of the pushbutton pin in arduino
const int WAIT_PRESS_TIME = 10000; // 10000 milliseconds, 10 seconds

// Variable declaration
int lastState = 0;  // the last state from the input pin
int currentState;     // the current reading from the input pin
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;
long pressDuration;

void setup() {
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
    // read the state of the button:
    
    currentState = digitalRead(BUTTON_PIN);

    if(lastState == 1 && currentState == 0)        // button is pressed
    {
        pressedTime = millis();
    }
    if(lastState == 0 && currentState == 1) 
    { // button is released
        releasedTime = millis();
        while (millis() - releasedTime < WAIT_PRESS_TIME) {
            }
    }

    pressDuration = releasedTime - pressedTime;
    lastState = currentState;
}