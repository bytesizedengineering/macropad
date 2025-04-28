#include <Adafruit_TinyUSB.h>

// Define the button pin
#define BUTTON_PIN 2

// Track the button state
bool buttonState = false;
bool lastButtonState = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Internal pull-up resistor
  TinyUSBDevice.begin();  // Start TinyUSB
  delay(1000);  // Allow some startup time
}

void loop() {
  // Read the current state of the button
  buttonState = digitalRead(BUTTON_PIN);

  // Detect a button press (transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    sendKeyPress();
  }

  // Update the last state
  lastButtonState = buttonState;

  delay(10);  // Debounce delay
}

void sendKeyPress() {
  // Send the letter 'a' to the computer
  TinyUSBKeyboard.print("a");
}
